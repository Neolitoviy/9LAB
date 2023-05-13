#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

void push(stack** head, node* node) {
    stack* new_node = (stack*)malloc(sizeof(stack));
    if (new_node != NULL) {
        new_node->node_ptr = node;
        new_node->next = *head;
        *head = new_node;
    }
}

node* pop(stack** head) {
    if (*head == NULL)
        return NULL;
    node* node = (*head)->node_ptr;
    stack* new_head = (*head)->next;
    free(*head);
    *head = new_head;
    return node;
}