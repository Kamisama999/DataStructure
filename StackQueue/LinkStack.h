#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int LinkStackType;
typedef struct LinkStackNode
{
	LinkStackType data;          //������
	struct LinkStackNode* next;  //ָ����
}LinkStackNode;

typedef struct LinkStack
{
	LinkStackNode* guard;        //���ڱ�λ��ͷ�ڵ�
	int capacity;                //ջ��Ԫ�ظ���
}LStack;

void LinkStackInit(LStack* p);
void LinkStackDestroy(LStack* p);

void LinkStackPush(LStack* p, LinkStackType x);
void LinkStackPop(LStack* p);

LinkStackType LinkStackTop(LStack* p);
bool LinkStackEmpty(LStack* p);
int LinkStackSize(LStack* p);

