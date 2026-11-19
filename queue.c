/*Author C. Knoblauch, 11/18/2026.
This program establishes functions related to array based queue, is called in a header file*/

#include "queue.h"

static int front_idx = 0;
static int end_idx = 0;
static int queue[size];

int is_empty(void){//checks if front index == end index
    if(front_idx == end_idx)
        return 1;
    else
        return 0;
}

int is_full(void){//checks end index == queue array size
    if(end_idx == size)
        return 1;
    else
        return 0;
}

int front(void){//gets element at front index iff queue is not empty o/w return -1
    if(is_empty())
        return -1;
    else
        return queue[front_idx];
}

void reset(void){//sets front index = end index = 0
    front_idx = 0;
    end_idx = 0;
}

void enqueue(int value){//inserts value at end index then ncrements the index iff queue is not full
    if(! is_full())
        queue[end_idx ++] = value;
}

int dequeue(void){//get value at front index then increment front index iff queue is not empty o/w return -1
    if(is_empty())
        return -1;
    else
        return queue[front_idx ++];
}
