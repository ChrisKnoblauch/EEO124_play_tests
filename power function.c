/*This is a code example from lecture 10 on functions,
a custom made power function found in math.h*/

double myPower(double num, int pow){
    double powerResult = 1;
    for(int i=1; i <= pow; i++){
        powerResult *= num;
    }
    return powerResult; 
}

#include <stdio.h>

int main(){
    double n=5;
    int p=3;
    printf("%g to the power of %d = %g \n", n, p, myPower(n,p));
    return 0;
}