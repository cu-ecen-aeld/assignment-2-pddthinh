SRC_DIR := .
BUILD_DIR := build

TARGET := $(BUILD_DIR)/writer

# Collect source files
SRCS := $(wildcard $(SRC_DIR)/*.c)
# Transform source file to object inside BUILD_DIR
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

CFLAGS :=

all: $(TARGET)

clean:
	@rm -rf $(BUILD_DIR)

# Common rule to create the output directory
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

# Link executable
$(TARGET): $(OBJS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

# Compile Source to Objects
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean
