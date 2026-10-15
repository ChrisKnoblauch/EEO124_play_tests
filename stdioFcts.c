/*C Knoblauch and Claude AI, 10/14/26.
These are code snippets from claude to help me understand
stdio functions*/

#include <stdio.h>
int main(void){

    int num;
    char ch, name [50];
    FILE *fp;

    printf("Age: %d\n", 20);        // formatted output
    putchar('A');
    putchar('\n');                   // one character
    puts("Hello\n");                  // string + newline
    fprintf(fp, "Score: %d\n", 95); // formatted output to a file

    return 0;
}