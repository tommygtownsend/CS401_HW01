# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

# Executable name
TARGET = inventory_system

# Source files
SRC = HW01.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Default target: build the executable
all: $(TARGET)

# Rule to create the executable
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# Rule to compile .cpp files to .o object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to clean up generated files
clean:
	rm -f $(OBJ) $(TARGET)

# Rule to run the program
run: $(TARGET)
	./$(TARGET)
