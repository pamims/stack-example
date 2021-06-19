#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct node Node;
Node *make_stack(void);
bool push(Node *, char);
char pop(Node *);
char peak(Node *);
bool free_stack(Node *stack);

#endif

