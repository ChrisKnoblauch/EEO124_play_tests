int func(int a, int b){ /* function taking two ints by value: a and b are copies of the caller's values */
    a=5; /* assigns to the local copy only; the caller's variable is unchanged */
    b=8;
    return 0; /* sends a value back to the caller */
}
int FUNC(int *a, int *b){ /* function taking two pointers: a and b hold the addresses of the caller's variables */
    *a=5; /* dereferences the pointer and writes to the variable it points to, so the caller's variable changes */
    *b=8;
    return 0;
}

#include <stdio.h>
int main(){ /* program entry point */
    int x=10, y=40, m=0, n=0; /* declare and initialize four ints */
    int z=func(x, y); /* calls func with copies of x and y, and stores the returned value in z */
    int Z=FUNC(&m, &n); /* calls FUNC with the addresses of m and n (& takes an address); the return value is ignored */
    
    //pass by value
    printf("%d\n",x);
    printf("%d\n",y);
    //print return value
    printf("%d\n", z);
    printf("%d\n", Z);
    //pass by reference
    printf("%d\n", m);
    printf("%d\n", n);
    return 0; /* tells the operating system the program finished normally */
}