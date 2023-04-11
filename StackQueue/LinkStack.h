#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int LinkStackType;
typedef struct LinkStackNode
{
	LinkStackType data;          //数据域
	struct LinkStackNode* next;  //指针域
}LinkStackNode;

typedef struct LinkStack
{
	LinkStackNode* guard;        //带哨兵位的头节点
	int capacity;                //栈的元素个数
}LStack;

void LinkStackInit(LStack* p);
void LinkStackDestroy(LStack* p);

void LinkStackPush(LStack* p, LinkStackType x);
void LinkStackPop(LStack* p);

LinkStackType LinkStackTop(LStack* p);
bool LinkStackEmpty(LStack* p);
int LinkStackSize(LStack* p);

