#!/bin/bash

filesdir=$1
searchstr=$2

if [ ! -d "${filesdir}" ]; then
    echo "ERROR: \"${filesdir}\" is not a directory."
    exit 1
fi

if [ -z "${searchstr}" ]; then
    echo "ERROR: \"${searchstr}\" is empty."
    exit 1
fi

# Search for the content
tmpResult=$(grep -r -c "${searchstr}" "${filesdir}")

# Analyze each result line
fileCount=0
matchCount=0
for line in ${tmpResult}
do
    # echo "Found =>> ${line}"

    # Break the line
    IFS=':' read -r file match <<< "${line}"

    if [ ${match} -gt 0 ];
    then
        fileCount=$((fileCount + 1))
        matchCount=$((matchCount + match))
    fi
done
echo "The number of files are ${fileCount} and the number of matching lines are ${matchCount}"
