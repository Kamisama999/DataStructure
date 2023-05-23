#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDateType;
typedef struct SeqList
{
	SLDateType* a;
	int size;        //�洢���ݵĸ���
	int capacity;    //�洢�ռ�Ĵ�С
}SL;

void SLInit(SL* psl);
void SLDistroy(SL* psl);

void SLCheckCapacity(SL* psl);
void SLPrint(SL* psl);

void SLPushFront(SL* psl, SLDateType x);
void SLPushBack(SL* psl, SLDateType x);
void SLPopFront(SL* psl);
void SLPopBack(SL* psl);

int SLFind(SL* psl, SLDateType x);
void SLInsert(SL* psl, size_t pos, SLDateType x);
void SLErase(SL* psl, size_t pos);
void SLModify(SL* psl, size_t pos, SLDateType x);