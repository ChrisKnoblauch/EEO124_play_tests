/*Author: C. Knoblauch with tutor, 10/18/2026.
This program reads values from two input files and puts both into separate arrays.
Then a third array is created which is the convergence of the two, which is written 
to an output file*/

#include <stdio.h>
int main(){

    FILE *input1=fopen("input1.txt", "r");
    if(input1 == NULL){
        perror("could open inp 1");
        return 1;
    }

    FILE *input2=fopen("input2.txt", "r");
    if(input2 == NULL){
        perror("could open inp 2");
        return 1;
    }

    FILE *output=fopen("output1.txt", "w");
    if(output == NULL){
        perror("could open output file");
        return 1;
    }

    int arrayA[100], m=0;
    while(m<100 && fscanf(input1, "%d", &arrayA[m]) == 1)
        m++;
    fclose(input1);

    int arrayB[100], n=0;
    while(n<100 && fscanf(input2, "%d", &arrayB[n]) == 1)
        n++;
    fclose(input2);


    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            if(arrayB[j] == arrayA[i])
                fprintf(output, "%d ", arrayA[i]);
        }
    }
    fclose(output);
    return 0;
}