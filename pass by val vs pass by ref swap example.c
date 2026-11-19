void swapByVal(int x, int y){   /* void means the function returns nothing; x and y are copies of the caller's values */
    int temp = x;   /* saves x's value in a temporary variable so it isn't lost when x is overwritten */
    x = y;   /* overwrites the local copy of x with y's value */
    y = temp;   /* puts the saved original x into y, completing the swap of the copies only */
}

void swapByRef(int *x, int *y){   /* x and y are pointers holding the addresses of the caller's variables */
    int temp = *x;   /* dereferences x to read the value it points to and saves it in temp */
    *x = *y;   /* writes the value y points to into the variable x points to, changing the caller's variable */
    *y = temp;
}

#include <stdio.h>   /* gives access to printf */

int main(){   /* program entry point */
    int a=10, b=20;   /* declares and initializes two ints */
    swapByVal(a,b);   /* passes copies of a and b; the swap happens on the copies, so a and b are unchanged */
    printf("swap by value: a was 10, is now %d, b was 20, is now %d\n\n", a, b);   /* each %d is replaced by the next argument in order; \n\n prints a newline plus a blank line */
    swapByRef(&a, &b);   /* & passes the addresses of a and b, so the function can change them directly */
    printf("swap by reference: a was 10, is now %d, b was 20, is now %d\n", a, b);
    return 0;   /* tells the operating system the program finished normally */
}