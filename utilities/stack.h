#include <stdlib.h>

typedef struct stack_node {
    void * value;
    struct stack_node *next;
} stack_node_t;

typedef struct stack {
    int size;
    stack_node_t *first;
} stack_t;

stack_t *init_stack() {
    stack_t *stack = (stack_t *) malloc(sizeof(stack_t));
    stack->size = 0;
    stack->first = NULL;
    return stack;
}

void push_stack(stack_t *stack, void *n) {
    stack_node_t *new_node = (stack_node_t *) malloc(sizeof(stack_node_t));
    new_node->value =  n;
    new_node->next = stack->first;
    stack->first = new_node;
    stack->size++;
}

void *pop_stack(stack_t *stack) {
    if (stack->size == 0) return NULL;
    void *elem = stack->first->value;
    stack->size--;
    stack->first = stack->first->next;
    return elem;
}