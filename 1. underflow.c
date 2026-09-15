#include <stdio.h>

int main(void) {

    unsigned char n = 182;
    unsigned char z = 181;
    unsigned char resultU = z-n;
    printf("Demonstrating Underflow....");
    printf("The unsigned char result of chars %u - %u is: %u\n", z, n, resultU);

    unsigned char m = 256;
    unsigned char y = 97;
    unsigned char resultO = m+y;
    printf("Demonstrating Overflow....");
    printf("The unsigned char result of chars %u + %u is: %u\n", m, y, resultO);
    
    return 0;
}