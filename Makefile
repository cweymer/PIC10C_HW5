.PHONY: clean
# Compiler
COMPILER = g++
CFLAGS = -std=c++20 -O3
# Linker
LINKER = $(COMPILER) -lm
# Executable name
EXEC = hw5
# Object files
OBJ = HW5.o 
# Default target
all: $(EXEC)
# Link object files to create the executable $(EXEC): $(OBJ)
$(EXEC): $(OBJ)
	$(LINKER) -o $@ $^
%.o: %.cpp binary_search_tree.h
	$(COMPILER) $(CFLAGS) -c $< -o $@ 
clean:
	rm -f $(OBJ) $(EXEC)