#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}LTNode;

LTNode* ListInit();
void ListDestory(LTNode* phead);

LTNode* BuyListNode(LTDataType x);
void ListPrint(LTNode* phead);
bool ListEmpty(LTNode* phead);
size_t ListSize(LTNode* phead);

LTNode* ListFind(LTNode* phead, LTDataType x);
void ListInsert(LTNode* pos, LTDataType x);
void ListErase(LTNode* pos);

void ListPushFront(LTNode* phead, LTDataType x);
void ListPushBack(LTNode* phead, LTDataType x);
void ListPopFront(LTNode* phead);
void ListPopBack(LTNode* phead);
