//Author, VS Code chatbot, notes C. Knoblauch, 9/22/2026.
//This program compares the left most bit of a 32 bit hexadeimal with a mask that has a 1 in 
//the left most bit, using bitwise &. Each iteration of the for loop shifts the bits of the
//hexadecimal left to continue through each bit. When the & produces a 1 it increases the 
//count of ones increases. When & does not produce 1 the count of zero increases.

#include <stdio.h>

int main()
{
    unsigned int x;
    printf("Enter a 32-bit hexadecimal number: ");
    scanf("%x", &x);

    int ones = 0, zeros = 0;
//(initialize i to 0; continue while i < 32; i = i+1; bits in x shift left each iteration)
    for (unsigned char i = 0; i < 32; i++, x <<= 1)
    { //0x80000000 is a mask with only the leftmost bit set.
      //If the leftmost bit of x is 1, the result is nonzero, so the condition is true.
      //Otherwise, the result is 0, so the condition is false.
        if (x & 0x80000000)
            ones++; //ones = ones + 1
        else
            zeros++; //zeros = zeros + 1
    }

    printf("Number of 1s: %d\n", ones);
    printf("Number of 0s: %d\n", zeros);

    return 0;
}