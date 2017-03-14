CC=gcc
CFLAGS=-I. -g
DEPS=$(wildcard *.h)

BIN_DIR=bin
LIB_DIR=lib

OBJS=$(LIB_DIR)/shell.o $(LIB_DIR)/utils.o $(LIB_DIR)/builtins.o

.PHONY: clean

$(BIN_DIR)/msh: $(OBJS) main.c
	@mkdir -p bin ;\
	$(CC) -o $@ $^ $(CFLAGS)

$(LIB_DIR)/%.o: %.c $(DEPS)
	@mkdir -p lib ;\
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	@rm -rf bin lib

