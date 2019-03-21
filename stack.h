#ifndef _STACK_H
#define _STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>

enum STACKDIR { BOTTOMUP, TOPDOWN };

typedef int64_t Item;

typedef struct node {
	Item item;
	struct node *bottom;
} Node;

typedef struct stack {
	Node *top;
	uint64_t itemCount;
} Stack;


void InitializeStack(Stack *s);

bool PushToStack(Item pitem, Stack *s);

bool PopFromStack(Item *pitem, Stack *s);

uint8_t CountItemsInStack(const Stack *s);

void DisplayStackContent(const Stack *s, enum STACKDIR stackDir);

static void DisplayStackFromTopDown(const Stack *s);

static void DisplayStackFromBottomUp(const Stack *s);

static void CopyToNode(Item pitem, Node *pn);

static void CopyToItem(Item *pitem, Node *pn);

#endif
