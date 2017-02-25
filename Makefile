CC=gcc
CFLAGS=-I. -g
DEPS=shell.h utils.h

BIN_DIR=bin
LIB_DIR=lib

.PHONY: clean

$(BIN_DIR)/msh: $(LIB_DIR)/shell.o $(LIB_DIR)/utils.o | $(BIN_DIR)
	$(CC) -o $@ $(LIB_DIR)/shell.o $(LIB_DIR)/utils.o main.c $(CFLAGS)

$(LIB_DIR):
	@mkdir -p $(LIB_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

$(LIB_DIR)/%.o: %.c $(DEPS) | $(LIB_DIR)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	@rm -rf bin lib

