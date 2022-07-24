// execvp - execute a command and wait for it to finish
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    char *args[] = {"../basic/even", NULL};
    execvp(args[0], args);

    printf("Ending-----");

    return 0;
}