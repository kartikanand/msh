#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "builtins.h"
#include "shell.h"
#include "utils.h"


void print_banner () {
    printf("welcome to msh - the modern shell v0.1\n");
}


void print_prompt () {
    printf("msh >> ");
}


int read_line (char **input) {
    size_t len;

    int err = getline(input, &len, stdin);
    return err;
}


int eval (const char *input) {
    char **tokens;

    int num_tokens = tokenize_line(input, &tokens);

    BUILTIN_CMD cmd = is_builtin(tokens[0]);
    if (cmd != -1) {
        call_builtin(cmd, (const char**)tokens);
        return 0;
    }

    pid_t pid = fork();

    if (pid > 0) {
        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            return 0;
        } else {
            return 1;
        }
    } else {
        execvp(tokens[0], tokens);
    }
}

