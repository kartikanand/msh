#ifndef __BUILTINS_H_
#define __BUILTINS_H_

typedef enum {
	BLTIN_CD, 
	BLTIN_NONE
} BUILTIN_CMD;

BUILTIN_CMD get_builtin(const char *cmd);
int call_builtin(BUILTIN_CMD cmd, const char **args);

#endif
