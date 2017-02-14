CC=gcc
CFLAGS=-I.
DEPS=shell.h

BIN_DIR=bin
LIB_DIR=lib

.PHONY: clean

$(BIN_DIR)/msh: $(LIB_DIR)/shell.o | $(BIN_DIR)
	$(CC) -o $@ $(LIB_DIR)/shell.o main.c $(DEPS)

$(LIB_DIR):
	@mkdir -p $(LIB_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

$(LIB_DIR)/%.o: %.c $(DEPS) | $(LIB_DIR)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	@rm -rf bin lib

