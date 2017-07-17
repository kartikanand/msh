#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "builtins.h"
#include "shell.h"


static void strip_line(char *line) {
    size_t len = strlen(line);
    size_t end = len - 1;

    // since 'end' is unsigned, we can't check for greater than 0
    while (1) {
        if (line[end] == '\n')  line[end] = '\0';
        if (end == 0)   break;

        end--;
    }

    // handle 0 index
    if (line[end] == '\n')  line[end] = '\0';
}


static int tokenize_line(char *line, char ***tokens) {
    // clear new lines
    strip_line(line);

    // by default we support 1024 tokens. Plus one for final NULL pointer
    (*tokens) = (char**)malloc(sizeof(char*) * TOKEN_LIMIT);

    const char *delim = " ";
    char *token = strtok(line, delim);

    int num_tokens = 0;
    while (token) {
        (*tokens)[num_tokens++] = token;

        // token limit reached
        if (num_tokens == TOKEN_LIMIT)     return -1;

        token = strtok(NULL, delim);
    }

    return num_tokens;
}


void print_banner () {
    printf("welcome to msh - the modern shell v0.1\n");
}


void print_prompt () {
    printf("msh >> ");
}


int read_line (char **input) {
    size_t len;

    int char_read = getline(input, &len, stdin);

    // For ctrl-D we'll get a char_read of -1
    return char_read;
}


int eval (const char *input) {
    char **tokens;

    // duplicate the input since strtok would modify it
    char *input_dup = strdup(input);

    int num_tokens = tokenize_line(input_dup, &tokens);
    if (num_tokens == 0)    return 0;
    if (num_tokens < 0) {
        printf("Huge number of tokens\n");
        return -1;
    }

    BUILTIN_CMD cmd = get_builtin(tokens[0]);
    if (cmd != BLTIN_NONE) {
        call_builtin(cmd, (const char**)tokens);

        free(input_dup);
        free(tokens);
        return 0;
    }

    pid_t pid = fork();

    if (pid > 0) {
        int status;
        waitpid(pid, &status, 0);
        free(input_dup);
        free(tokens);

        if (WIFEXITED(status)) {
            return 0;
        } else {
            return 1;
        }
    } else {
        execvp(tokens[0], tokens);
    }
}

