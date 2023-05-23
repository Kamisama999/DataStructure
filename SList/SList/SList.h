#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SListDataType;

typedef struct SListNode
{
	SListDataType data;
	struct SListNode* next;
}SLTNode;

SLTNode* BuySLTNode(SListDataType x);

void SListPrint(SLTNode* phead);
void SListDestory(SLTNode** pphead);
void SListPushFront(SLTNode** pphead, SListDataType x);
void SListPushBack(SLTNode** pphead, SListDataType x);
void SListPopFront(SLTNode** pphead);
void SListPopBack(SLTNode** pphead);

SLTNode* SListFind(SLTNode* phead, SListDataType x);
void SListInsert(SLTNode** pphead, SLTNode* pos, SListDataType x);
void SListInsertAfter(SLTNode* pos, SListDataType x);

void SListErase(SLTNode** pphead, SLTNode* pos);
void SListEraseAfter(SLTNode* pos);
