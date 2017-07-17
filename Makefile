CC=gcc

BIN_DIR=bin
LIB_DIR=lib
SRC_DIR=src
INC_DIR=include

CFLAGS=-I$(INC_DIR) -g
DEPS=$(wildcard $(INC_DIR)/*.h)

OBJS=$(LIB_DIR)/shell.o $(LIB_DIR)/builtins.o

.PHONY: clean

$(BIN_DIR)/msh: $(OBJS) $(SRC_DIR)/main.c
	@mkdir -p bin ;\
	$(CC) -o $@ $^ $(CFLAGS)

$(LIB_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS)
	@mkdir -p lib ;\
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	@rm -rf bin lib

