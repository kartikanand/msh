#ifndef __SHELL__
#define __SHELL__

#define TOKEN_LIMIT 1024

void print_banner ();
void print_prompt ();
int read_line (char **input);
int eval (const char *input);

#endif

