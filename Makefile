# Compiler to use
CC = gcc

# Compilation flags
CFLAGS = -Wall -std=c11   # -Wall enables all warnings, -std=c11 specifies the C standard

# The name of the executable file
TARGET = num_conversion

# The source file(s) - only one source file here
SRC = main.c

# The object file(s) - automatically derived from the source files
OBJ = $(SRC:.c=.o)

# Default target to build the executable
all: $(TARGET)
	./$(TARGET)

# Rule for building the executable from object files
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)  # Link object files to create the executable

# Rule for compiling the source code into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@  # Compile each .c file into a .o file

# Clean up object files and the executable
clean:
	rm -f $(OBJ) $(TARGET)

# Phony target to avoid conflict with file names
.PHONY: all clean

