# Directories
LIBCARD_DIR = libcard
GAMES_DIR = games
BUILD_DIR = build

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -I$(LIBCARD_DIR) -I$(GAMES_DIR)

# Output directories for build files
OBJ_DIR = $(BUILD_DIR)/obj
BIN_DIR = $(BUILD_DIR)/bin
LIB_DIR = $(BUILD_DIR)/libcard

# Games list (add more games as needed)
GAMES = blackjack

# Source files for libcard
LIBCARD_SRC = $(LIBCARD_DIR)/libcard.c
LIBCARD_OBJ = $(OBJ_DIR)/libcard.o

# Create directories if they don't exist
$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR) $(LIB_DIR))

# Default target: build all games
all: $(GAMES:%=$(BIN_DIR)/%)

# Rule to build each game executable
$(BIN_DIR)/%: $(GAMES_DIR)/%.c $(LIBCARD_OBJ)
	$(CC) $(CFLAGS) -o $@ $^
	@echo "Built $@"

# Rule to build libcard object file
$(LIBCARD_OBJ): $(LIBCARD_SRC)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Built libcard object file"

# Clean the build
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
	@echo "Cleaned build files"

# Phony targets (don't create files named 'clean' or 'all')
.PHONY: all clean

