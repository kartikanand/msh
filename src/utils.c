#include <stdlib.h>
#include <string.h>
#include "utils.h"


static void strip_line(char *line) {
    size_t len = strlen(line);
    size_t end = len-1;

    // since 'end' is unsigned, we can't check for greater than 0
    while (1) {
        if (line[end] == '\n')  line[end] = '\0';

        end--;

        if (end == 0)   break;
    }

    // handle 0 index
    if (line[end] == '\n')  line[end] = '\0';
}


int tokenize_line(const char *line, char ***tokens) {
    // duplicate the line since strtok would modify it
    char *line_dup = strdup(line);

    // clear new lines
    strip_line(line_dup);

    // by default we support 1024 tokens. Plus one for final NULL pointer
    (*tokens) = (char**)malloc(sizeof(char*) * 1025);

    const char *delim = " ";
    char *token = strtok(line_dup, delim);

    int num_tokens = 0;
    while (token) {
        (*tokens)[num_tokens++] = token;
        token = strtok(NULL, delim);
    }
    (*tokens)[num_tokens] = NULL;

    return num_tokens;
}

