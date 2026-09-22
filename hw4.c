#include <stdio.h>

void printBinary32(const char *format, int x);

int main()
{
    int x;
    printf("Enter an integer: ");
    scanf("%d", &x);

    printBinary32("\nBinary representation of %d: ", x);

    return 0;
}

void printBinary32(const char *format, int x)
{
    printf(format, x);
    for (unsigned char i = 0; i < 32; i++, x <<= 1)
    {
        if (x & 0x80000000)
            printf("1");
        else
            printf("0");
    }
}