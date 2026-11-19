/*Author C. Knoblauch, 11/18/2026, psuedocode from instructor.
This program utilizes a header file to establish an array-based queue
with related functions. It enqueues, prints the front index value, 
dequeues, then checks if it is empty.*/

#include <stdio.h>
#include "queue.h"

int main(void){
    reset();
    printf("enqueue 10, 20, 30:\n");
    enqueue(10); enqueue(20); enqueue(30);
    printf("front = %d\n", front());
   
    printf("dequeing until empty:\n");
    while(! is_empty())
        printf("%d ", dequeue());
    printf("\n");
    printf("is queue empty?\n");
    printf("is_empty = %d\n", is_empty());

    return 0;
}