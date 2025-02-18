CXX = g++
CC = gcc
CXX_FLAGS = -Wall -g -DDEBUG
LD_FLAGS = -lglfw3 -lopengl32 -lgdi32 -luser32 -lkernel32 -lshell32

SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIRS = -I./include
LIB_DIRS = -L./lib

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp) $(SRC_DIR)/glad.c
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(wildcard $(SRC_DIR)/*.cpp)) $(BUILD_DIR)/glad.o

TARGET = app.exe

.PHONY: all
all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir $(BUILD_DIR) 2> NUL || true

$(TARGET): $(OBJ_FILES) $(BUILD_DIR)/glad.o
	$(CXX) $(CXX_FLAGS) -o $@ $^ $(LIB_DIRS) $(LD_FLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXX_FLAGS) $(INCLUDE_DIRS) -c $< -o $@

$(BUILD_DIR)/glad.o: $(SRC_DIR)/glad.c
	$(CC) $(INCLUDE_DIRS) -c $< -o $@

.PHONY: clean
clean:
	if exist $(BUILD_DIR) rmdir /S /Q $(BUILD_DIR)
	if exist $(TARGET) del $(TARGET)
