#include "Stack.h"
#include "LinkStack.h"

void TestStack()
{
	ST st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	StackDestroy(&st);
}

void TestLinkStack()
{
	LStack lstack;
	LinkStackInit(&lstack);
	LinkStackPush(&lstack, 1);
	LinkStackPush(&lstack, 2);
	LinkStackPush(&lstack, 3);
	printf("%d ", LinkStackSize(&lstack));
	while (!LinkStackEmpty(&lstack))
	{
		printf("%d ", LinkStackTop(&lstack));
		LinkStackPop(&lstack);
	}
	LinkStackDestroy(&lstack);
}
int main()
{
	TestLinkStack();
	return 0;
}