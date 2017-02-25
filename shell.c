#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
#include "utils.h"


void print_banner () {
    printf("welcome to msh - the modern shell v0.1\n");
}


void print_prompt () {
    printf("msh >> ");
}


int read (char **input) {
    size_t len;

    int err = getline(input, &len, stdin);
    return err;
}


int eval (const char *input) {
    char **tokens;

    int num_tokens = tokenize_line(input, &tokens);
    while (num_tokens) {
        printf("token : %s\n", tokens[num_tokens-1]);

        num_tokens--;
    }

    return 0;
}

