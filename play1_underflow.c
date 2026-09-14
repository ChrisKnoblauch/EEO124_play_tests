#include <stdio.h>

int main(void) {
    //unsigned char n = 1;
    //unsigned char z = 0;
    //unsigned char result = z-n;
    char n = 22;
    char z = 0;
    unsigned char result = z-n;
    printf("Demonstrating Underflow....");
    printf("The unsigned char result of chars %u - %u is: %u\n", z, n, result);
    return 0;
}