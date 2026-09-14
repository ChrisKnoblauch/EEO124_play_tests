#include <stdio.h>

int main(void) {

    char n = 1;
    char z = 0;
    unsigned char resultU = z-n;
    printf("Demonstrating Underflow....");
    printf("The unsigned char result of chars %u - %u is: %u\n", z, n, resultU);

    char m = 256;
    char y = 97;
    unsigned char resultO = m+y;
    printf("Demonstrating Overflow....");
    printf("The unsigned char result of chars %u + %u is: %u\n", m, y, resultO);
    
    return 0;
}