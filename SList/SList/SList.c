#include "SList.h"

SLTNode* BuySLTNode(SListDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (!newnode)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void SListDestory(SLTNode** pphead)
{
	assert(pphead);

	SLTNode* cur = *pphead;
	while (cur)
	{
		SLTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}

void SListPushFront(SLTNode** pphead, SListDataType x)
{
	SLTNode* newnode = BuySLTNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

void SListPushBack(SLTNode** pphead, SListDataType x)
{
	assert(pphead);
	SLTNode* newnode = BuySLTNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

void SListPopFront(SLTNode** pphead)
{
	assert(pphead);
	assert(*pphead != NULL);

	SLTNode* del = *pphead;
	*pphead = (*pphead)->next;
	free(del);
	del = NULL;
}

void SListPopBack(SLTNode** pphead)
{
	assert(pphead);
	assert(*pphead != NULL);
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* tail = *pphead;
		while (tail->next->next != NULL)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}
}

SLTNode* SListFind(SLTNode* phead, SListDataType x)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void SListInsert(SLTNode** pphead, SLTNode* pos, SListDataType x)
{
	assert(pphead);
	assert(pos);

	if (pos == *pphead)
	{
		SListPushFront(pphead,x);
		return;
	}
	SLTNode* prev = *pphead;
	while (prev->next != pos)
	{
		prev = prev->next;
		assert(prev);
	}
	SLTNode* newnode = BuySLTNode(x);
	prev->next = newnode;
	newnode->next = pos;
}

void SListInsertAfter(SLTNode* pos, SListDataType x)
{
	assert(pos);
	SLTNode* newnode = BuySLTNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SListErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead);
	assert(pos);
	if (*pphead == pos)
	{
		SListPopFront(pphead);
		return ;
	}
	SLTNode* prev = *pphead;
	while (prev->next != pos)
	{
		prev = prev->next;
		assert(prev);
	}
	prev->next = pos->next;
	free(pos);
}

void SListEraseAfter(SLTNode* pos)
{
	assert(pos);
	assert(pos->next);
	SLTNode* del = pos->next;
	pos->next = pos->next->next;
	free(del);
	del = NULL;
}
