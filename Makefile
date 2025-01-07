# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Output library and executable names
LIBRARY = liblibcard.a
EXEC = main

# Source and object files
LIB_SRC = libcard.c
LIB_OBJ = libcard.o
MAIN_SRC = main.c
MAIN_OBJ = main.o

# Targets
all: $(EXEC)

# Build the executable
$(EXEC): $(MAIN_OBJ) $(LIB_OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(MAIN_OBJ) $(LIB_OBJ)

# Build the library
$(LIBRARY): $(LIB_OBJ)
	ar rcs $(LIBRARY) $(LIB_OBJ)

# Compile source files
$(LIB_OBJ): libcard.c libcard.h
	$(CC) $(CFLAGS) -c libcard.c

$(MAIN_OBJ): main.c libcard.h
	$(CC) $(CFLAGS) -c main.c

# Clean up build files
clean:
	rm -f $(EXEC) $(LIBRARY) *.o

