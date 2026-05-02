#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <sys/errno.h>

#include <syslog.h>

///////////////////////////////////////////////////////////
#define SYSLOG_ID   "MyWriterSysLog"

#define WRITER_LOG_STDOUT(format,...) printf(format"\n", ##__VA_ARGS__)
#define WRITER_LOG0(level, message)    \
            WRITER_LOG_STDOUT(message); \
            syslog(level, "%s", message); \

#define WRITER_LOG(level, format,...)    \
            WRITER_LOG_STDOUT(format, ##__VA_ARGS__); \
            syslog(level, format, __VA_ARGS__); \
///////////////////////////////////////////////////////////

int main(int argc, char** argv) {
    int ret = 1;
    FILE* file = NULL;

    openlog(SYSLOG_ID, LOG_PID, LOG_USER);

    do {
        // Step 1: Validate arguments
        if (argc != 3) {
            WRITER_LOG0(LOG_ERR, "Invalid syntax! Call program with 2 arguments!");
            break;
        }
        const char* pFileName = argv[1];
        const char* pText = argv[2];
        int pTextLen = strlen(pText);
        if (strlen(pFileName) <= 0 || pTextLen <= 0) {
            WRITER_LOG0(LOG_ERR, "Invalid syntax! Both 2 arguments must be non-empty!");
            break;
        }

        // Step 2: Write to the file
        file = fopen(pFileName, "w");
        if (file == NULL) {
            WRITER_LOG(LOG_ERR, "Failed to open file %s, error %d", pFileName, errno);
            break;
        }

        WRITER_LOG(LOG_DEBUG, "Writing %s to %s", pText, pFileName);
        int written = fprintf(file, "%s", pText);
        if (written != pTextLen) {
            WRITER_LOG(LOG_ERR, "Failed writing string \"%s\" to file", pText);
            break;
        }

        // Step 3: return success
        ret = 0;
    } while (0);

    if (file != NULL) fclose(file);

    // Close syslog
    closelog();

    return ret;
}
