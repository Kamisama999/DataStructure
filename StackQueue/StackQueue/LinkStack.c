#include "LinkStack.h"

void LinkStackInit(LStack* p)
{
	assert(p);
	p->guard = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	if (p->guard == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	p->guard->next = NULL;
	p->capacity = 0;
}

void LinkStackDestroy(LStack* p)
{
	assert(p);
	while (p->guard)
	{
		LinkStackNode* del = p->guard;
		p->guard = p->guard->next;
		free(del);
	}
	p->capacity = 0;
}

void LinkStackPush(LStack* p, LinkStackType x)
{
	assert(p);
	LinkStackNode* newNode = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	if (newNode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = p->guard->next;
	p->guard->next = newNode;
	p->capacity++;
}

void LinkStackPop(LStack* p)
{
	assert(p);
	assert(!LinkStackEmpty(p));
	LinkStackNode* del = p->guard->next;
	p->guard->next = p->guard->next->next;
	free(del);
	p->capacity--;
}

LinkStackType LinkStackTop(LStack* p)
{
	assert(p);
	assert(!LinkStackEmpty(p));
	return p->guard->next->data;
}

bool LinkStackEmpty(LStack* p)
{
	assert(p);
	return p->capacity == 0;
}

int LinkStackSize(LStack* p)
{
	assert(p);
	return p->capacity;
}

