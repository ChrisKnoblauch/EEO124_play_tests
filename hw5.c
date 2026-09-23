//Author C. Knoblauch, AI assisted, 9/22/2026
//This program reads a 32bit hexadecimal and counts the leading zeros.
//An evaluation of the user entry would improve functionality.

#include <stdio.h>

int main()
{
    unsigned int x; int zeros = 0;
    printf("Enter a 32-bit hexadecimal number: ");
    scanf("%x", &x);
    
    for (unsigned char i = 0; i < 32; i++, x <<= 1)
    { 
        if (!(x & 0x80000000)) //if the left most bit is not set.
            zeros++; //zeros = zeros + 1
        else 
            i=32;
                  
    }
    printf("Number of leading zeros: %d\n", zeros);
    return 0;
}