#include "stack.h"

void InitializeStack(Stack *s) {
	s->top = NULL;
	s->itemCount = 0;
}

bool PushToStack(Item pitem, Stack *s) {
	Node *pnew;

	pnew = (Node *)malloc(sizeof(Node));
	if (pnew) {
		CopyToNode(pitem, pnew);
		if (s->top) {
			pnew->bottom = s->top;
		}else {
			pnew->bottom = NULL;
		}
		s->top = pnew;
		s->itemCount++;
		return true;
	}else {
		return false;
	}
}

bool PopFromStack(Item *pitem, Stack *s) {
	Node *prev;

	if (s->top) {
		CopyToItem(pitem, s->top);
		prev = s->top;
		s->top = s->top->bottom;
		free(prev);
		s->itemCount--;
		return true;
	}else {
		return false;
	}

}

uint8_t CountItemsInStack(const Stack *s) {
	return s->itemCount;
}

void DisplayStackContent(const Stack *s, enum STACKDIR stackDir) {
	if (stackDir == TOPDOWN) {
		DisplayStackFromTopDown(s);
	}else {
		DisplayStackFromBottomUp(s);
	}
}

static void DisplayStackFromTopDown(const Stack *s) {
	Node *iterator = s->top;
	if (iterator) {
		while (iterator) {
			printf("%" PRId64 " ", iterator->item);
			iterator = iterator->bottom;
		}
	}else {
		printf("Stack is empty");
	}
    printf("\n");
}

static void DisplayStackFromBottomUp(const Stack *s) {
	uint8_t limit = s->itemCount;
	Node *iterator = s->top;
	if (iterator) {
		for (uint8_t i = 1; i <= limit; i++) {
			iterator = s->top;
			for (uint8_t j = 0; j < limit - i; j++) {
				iterator = iterator->bottom;
			}
			printf("%" PRId64 " ", iterator->item);
		}
	}else {
		printf("Stack is empty");
	}
	printf("\n");
}

static void CopyToNode(Item pitem, Node *pn) {
	pn->item = pitem;
}

static void CopyToItem(Item *pitem, Node *pn) {
	*pitem = pn->item;
}
