# Simple-Stack-Implementation-in-C
A simple stack implementation in C

## Sample Usage
```
#include <stdio.h>
#include <inttypes.h>

#include "stack.h"

#define SIZE 10

int main() {
	Stack numStack;
	Item num;
	InitializeStack(&numStack);
	for (Item i = 0; i < SIZE; i++) {
		if (PushToStack(i, &numStack)) {
            printf("Successfully pushed %" PRId64 " to the stack\n", i);
        }else {
            printf("Cannot push to the stack\n");
            exit(1);
        }
	}
	printf("Item count is %d\n", CountItemsInStack(&numStack));
	for (int i = 0; i < SIZE; i++) {
		if (PopFromStack(&num, &numStack)) {
		    printf("Popping %" PRId64 " from the stack\n", num);
        }else {
            printf("Cannot pop from the stack anymore\n");
            exit(1);
        }
	}
	printf("Item count is %d\n", CountItemsInStack(&numStack));
	DisplayStackContent(&numStack, BOTTOMUP);

    return 0;
}
```
