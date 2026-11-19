#include "queue.h"

static int front_idx = 0;
static int end_idx = 0;
static int queue[size];

int is_empty(void){
    if(front_idx == end_idx)
        return 1;
    else
        return 0;
}

int is_full(void){
    if(end_idx == size)
        return 1;
    else
        return 0;
}

int front(void){
    if(is_empty())
        return -1;
    else
        return queue[front_idx];
}

void reset(void){
    front_idx = 0;
    end_idx = 0;
}

void enqueue(int value){
    if(! is_full())
        queue[end_idx ++] = value;
}

int dequeue(void){
    if(is_empty())
        return -1;
    else
        return queue[front_idx ++];
}
