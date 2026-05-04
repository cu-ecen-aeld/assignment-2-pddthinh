CROSS_COMPILE ?= 


SRC_DIR := .
# BUILD_DIR := build

TARGET := writer

# Collect source files
SRCS := $(wildcard $(SRC_DIR)/*.c)
# Transform source file to object inside BUILD_DIR
OBJS := $(SRCS:$(SRC_DIR)/%.c=%.o)

CFLAGS :=

CC := $(CROSS_COMPILE)gcc
LD := $(CROSS_COMPILE)ld
AR := $(CROSS_COMPILE)ar

all: $(TARGET)

clean:
	@rm -rf $(TARGET) $(OBJS)

# # Common rule to create the output directory
# $(BUILD_DIR):
# 	@mkdir -p $(BUILD_DIR)

# Link executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

# Compile Source to Objects
%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean
