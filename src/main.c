#include <stdlib.h>
#include<stdio.h>
#include "shell.h"

int main () {

    print_banner();

    int err = 0;
    do {
        print_prompt();
        
        // read
        char *input = NULL;
        err = read_line(&input);
        if(err) break;

        // eval
        err = eval(input);

        // loop
    } while (!err);

    return 0;
}
