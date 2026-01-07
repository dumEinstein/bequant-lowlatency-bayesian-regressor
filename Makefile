CXX      := g++
# -O3: Max optimization
# -march=native: Use AVX/SSE instructions specific to your CPU (Essential for linear algebra)
# -funroll-loops: Unrolls loops for speed where possible
CXXFLAGS := -std=c++20 -O3 -march=native -funroll-loops -Wall -Wextra -Iinclude

SRC_DIR := src
OBJ_DIR := build
TARGET  := app

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Default target
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR) $(TARGET) $(TARGET).exe

.PHONY: all clean