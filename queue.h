#ifndef QUEUE_H
#define QUEUE_H

#define size 100

int is_empty(void);
int is_full(void);
int front(void);
void reset(void);
void enqueue(int value);
int dequeue(void);

#endif
