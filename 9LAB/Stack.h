#ifndef STACK_H
#define STACK_H
#include "Tree.h"

typedef struct stack {
    node* node_ptr;
    struct stack* next;
} stack;

void push(stack** head, node* node);
node* pop(stack** head);

#endif //STACK_H
