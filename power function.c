/*This is a code example from lecture 9 on functions*/

double myPower(double num, int pow){
    double powerResult = 1;
    for(int i=1; i <= pow; i++){
        powerResult *= num;
    }
    return powerResult; 
}

#include <stdio.h>

int main(){
    double n =5;
    int p= 3;
    printf("n to the power of p = %f \n", myPower(n,p));
    return 0;
}