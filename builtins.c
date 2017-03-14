#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "builtins.h"

static int cd(const char*, const char **);

static int (*func_ptr_array[])(const char*, const char**) = {
    &cd
};


BUILTIN_CMD is_builtin(const char *cmd) {
    if (!cmd)   return NULL_CMD;

    // successively check for each BUILTIN
    if (strcmp(cmd, "cd") == 0)     return CD;

    return -1;
}


int call_builtin(BUILTIN_CMD cmd, const char **args) {
    int (*func_ptr)(const char*, const char**) = func_ptr_array[(int)cmd];
    int ret = func_ptr(args[0], args);
    return ret;
}

static int cd(const char *cmd, const char **args) {
    if (!cmd)  return -1;

    int ret = chdir(args[1]);
    return ret;
}

