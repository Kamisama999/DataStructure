#include "List.h"

LTNode* ListInit()
{
	LTNode* guard = (LTNode*)malloc(sizeof(LTNode));
	if (guard == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	guard->next = guard;
	guard->prev = guard;
	return guard;
}

void ListDestory(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
}

LTNode* BuyListNode(LTDataType x)
{
	LTNode* node = (LTNode*)malloc(sizeof(LTNode));
	if (node == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	node->next = NULL;
	node->prev = NULL;
	node->data = x;
	return node;
}

void ListPrint(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	printf("head<=>");
	while (cur != phead)
	{
		printf("%d<=>", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

bool ListEmpty(LTNode* phead)
{
	assert(phead);

	return phead->next == phead;
}

size_t ListSize(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	size_t num = 0;
	while (cur != phead)
	{
		cur = cur->next;
		++num;
	}
	return num;
}

LTNode* ListFind(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void ListInsert(LTNode* pos, LTDataType x)
{
	LTNode* newnode = BuyListNode(x);
	pos->prev->next = newnode;
	newnode->prev = pos->prev;
	pos->prev = newnode;
	newnode->next = pos;
}

void ListErase(LTNode* pos)
{
	assert(pos);
	LTNode* prev = pos->prev;
	LTNode* next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
}

void ListPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	//LTNode* newnode = BuyListNode(x);
	//newnode->next = phead->next;
	//phead->next->prev = newnode;
	//phead->next = newnode;
	//newnode->prev = phead;
	ListInsert(phead->next, x);
}

void ListPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);

	//LTNode* newnode = BuyListNode(x);
	//LTNode* tail = phead->prev;

	//tail->next = newnode;
	//newnode->prev = tail;
	//newnode->next = phead;
	//phead->prev = newnode;
	ListInsert(phead, x);
}

void ListPopFront(LTNode* phead)
{
	assert(phead);
	assert(!ListEmpty(phead));
	//LTNode* first = phead->next;
	//phead->next = first->next;
	//first->next->prev = phead;
	//free(first);
	//first = NULL;
	ListErase(phead->next);
}

void ListPopBack(LTNode* phead)
{
	assert(phead);
	assert(!ListEmpty(phead));
	//LTNode* tail = phead->prev;
	//LTNode* prev = tail->prev;
	//prev->next = phead;
	//phead->prev = prev;
	//free(tail);
	//tail = NULL;
	ListErase(phead->prev);
}
