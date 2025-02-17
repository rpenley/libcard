# Compiler and flags
CC = gcc
CFLAGS = -Wall -g
LIB_DIR = libcard
GAME_DIR = games
LIBRARY = libcard.a  # Static library name

# Directories for object files
OBJ_DIR = obj
GAME_OBJ_DIR = $(OBJ_DIR)/games

# Find all the C files in libcard and games directories
LIBCARD_SRC = $(LIB_DIR)/libcard.c
LIBCARD_OBJ = $(OBJ_DIR)/libcard.o
GAME_SRC = $(wildcard $(GAME_DIR)/*.c)
GAME_OBJ = $(GAME_SRC:$(GAME_DIR)/%.c=$(GAME_OBJ_DIR)/%.o)

# Targets
all: $(LIBRARY) $(GAME_OBJ)
	$(CC) $(GAME_OBJ) -L$(OBJ_DIR) -lcard -o games_executable

$(LIBRARY): $(LIBCARD_OBJ)
	ar rcs $@ $^

$(GAME_OBJ_DIR)/%.o: $(GAME_DIR)/%.c | $(OBJ_DIR)/$(GAME_OBJ_DIR)
	$(CC) $(CFLAGS) -I$(LIB_DIR) -c $< -o $@

$(OBJ_DIR)/$(GAME_OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR) $(LIBRARY) games_executable

.PHONY: all clean

