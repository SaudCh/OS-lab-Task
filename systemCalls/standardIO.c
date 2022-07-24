// write a program to count the number of blanks lines and characters in a file using linux system calls
#include <stdio.h>
int main()
{
    FILE *fp;
    int b = 0, nl = 0, c = 0;
    char ch;
    fp = fopen("text.txt", "r");
    while (ch != EOF)
    {
        ch = fgetc(fp);
        if (ch == ' ')
            b++;
        if (ch == '\n')
            nl++;
        c++;
    }
    printf("no.of blanks %d\n", b);
    printf("no.of lines %d\n", nl);
    printf("no.of characters %d\n", c);
}