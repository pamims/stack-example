#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"


/* - STRUCTS - */


// Nodes contain stored data and a pointer to the next node.
struct node {
	char character;
	struct node *next;
};


/* - FUNCTIONS - */


// Creates a blank node that acts as the accessor for the stack structure. The
// returned pointer will be NULL if malloc fails to allocate this node.
Node *make_stack() {
	Node *new_stack = (Node *)malloc(sizeof(Node));
	if (new_stack) {
		new_stack->character = '\0';
		new_stack->next = NULL;
	}
	return new_stack;
}


// Adds a node to the top of the stack containing the value c. Returns false if
// the stack is NULL.
bool push(Node *stack, char c) {
    if (!stack) return false;
    Node *node = (Node *)malloc(sizeof(Node));
	if (!node) return false;
    node->next = stack->next;
    node->character = c;
    stack->next = node;
	return true;
}


// Removes node at top of stack and returns its stored value
char pop(Node *stack) {
	if (stack && stack->next) {
		Node *temp = stack->next;
        stack->next = temp->next;
        char return_value = temp->character;
		free(temp);
		return return_value;
	}
	return '\0';
}


// Returns the value at the top of the stack without removing the node.
char peak(Node *stack) {
	if (stack && stack->next) {
		return stack->next->character;
	}
	return '\0';
}


// Frees every node in the stack structure. Returns false if the stack is NULL.
bool free_stack(Node *stack) {
    if (!stack) return false;
	Node *temp = stack;
	while (stack) {
		temp = stack->next;
		free(stack);
		stack = temp;
		// printf("free node\n");
	}
    return true;
}
