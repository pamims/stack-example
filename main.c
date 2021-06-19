#include <stdio.h>
#include "stack.h"


/* - Program Start - */

int main(int argc, char *argv[]) {
    printf("Making stack: ");
    Node *stack = make_stack();
    if (!stack) {
        printf("fail\nProgram terminated.\n");
        return 0;
    }
    printf("success\n\n");

    printf("Peaking at empty stack behaves as expected:   %s\n", peak(stack) == '\0' ? "success" : "fail");
    printf("Popping from empty stack behaves as expected: %s\n", pop(stack) == '\0' ? "success" : "fail");

    printf("\nPushing alphabet to stack...\n");
    for (char c = 'a'; c <= 'z'; c++) {
	    printf("Pushing %c to stack: %s\n", c, push(stack,c) ? "success" : "fail");
    }

    printf("\nTesting peak and pop...\n");
    printf("peak: '%c'\n", peak(stack));
    printf("pop:  '%c'\n", pop(stack));
    printf("pop:  '%c'\n\n", pop(stack));

    printf("Destroying stack:              %s\n", free_stack(stack) ? "success" : "fail");
    printf("Setting stack pointer to NULL: %s\n\n", (stack = NULL) ? "fail" : "success");

    printf("Pushing to NULL stack behaves as expected:   %s\n", push(stack, 'a') ? "fail" : "success");
    printf("Peaking at NULL stack behaves as expected:   %s\n", peak(stack) == '\0' ? "success" : "fail");
    printf("Popping from NULL stack behaves as expected: %s\n", pop(stack) == '\0' ? "success" : "fail");

    return 0;
}
