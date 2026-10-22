/*Author C. Knoblauch with tutor, 10/18/2026.
This program calculates a Taylor series approximation for the arctan of 
z where -1 <= z <= 1.*/
#include <stdio.h>
int main(){

    float acc=0.0001, z=0.5, term=z, sum=0, pi=3.14159;
    
    for(int i=0; term >= acc || -term >= acc; i++){
        sum += term;
        term *= ((-z*z)*(2*i+1))/(2*i+3);
        printf(" intermediate arctan of %g= %f\n",z, sum*(180/pi));
    }

    //result is converted into degrees 
    printf("\n final arctan angle of %g = %f degrees\n",z, sum*(180/pi));

    return 0;
}