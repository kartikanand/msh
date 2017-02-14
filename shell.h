#ifndef __SHELL__
#define __SHELL__

void print_banner ();
void print_prompt ();
int read (char **input);
int eval (const char *input);

#endif

