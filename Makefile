# Compiler
CXX = g++

# Compiler flags
# -std=c++17: Use the C++17 standard
# -g: Include debugging information
# -Wall: Turn on all warnings
CXXFLAGS = -std=c++17 -g -Wall

# Include directory
IDIR = ./include

# Source directory
SDIR = ./src

# Build directory
BDIR = ./build

# Binary directory
BINDIR = ./bin

# List of C++ source files
# This finds all .cpp files in the src directory
SRCS = $(wildcard $(SDIR)/*.cpp)

# List of object files (replaces .cpp with .o and puts them in the build dir)
OBJS = $(patsubst $(SDIR)/%.cpp,$(BDIR)/%.o,$(SRCS))

# The final executable name
TARGET = $(BINDIR)/rubiks_solver

# Default target: build the executable
all: $(TARGET)

# Rule to link the final executable
$(TARGET): $(OBJS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile a .cpp file into a .o object file
$(BDIR)/%.o: $(SDIR)/%.cpp
	@mkdir -p $(BDIR)
	$(CXX) $(CXXFLAGS) -I$(IDIR) -c $< -o $@

# Target to clean up the project (remove build files and the executable)
clean:
	rm -rf $(BDIR)/* $(BINDIR)/*

.PHONY: all clean