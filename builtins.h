#ifndef __BUILTINS_H_
#define __BUILTINS_H_

typedef enum {NULL_CMD=-1, CD} BUILTIN_CMD;

BUILTIN_CMD is_builtin(const char *cmd);
int call_builtin(BUILTIN_CMD cmd, const char **args);

#endif
