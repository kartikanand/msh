#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "builtins.h"

static int cd(const char*, const char **);

static int (*get_func_ptr(BUILTIN_CMD cmd))(const char*, const char**) {
    switch (cmd) {
        case BLTIN_CD:
            return &cd;
        default:
            return NULL;
    }
}


BUILTIN_CMD get_builtin(const char *cmd) {
    if (!cmd)   return BLTIN_NONE;

    // successively check for each BUILTIN
    if (strcmp(cmd, "cd") == 0)     return BLTIN_CD;

    return BLTIN_NONE;
}


int call_builtin(BUILTIN_CMD cmd, const char **args) {
    int (*func_ptr)(const char*, const char**) = get_func_ptr(cmd);
    if (!func_ptr)   return 1;

    int ret = func_ptr(args[0], args);
    return ret;
}

static int cd(const char *cmd, const char **args) {
    if (!cmd)  return -1;

    int ret = chdir(args[1]);
    return ret;
}
