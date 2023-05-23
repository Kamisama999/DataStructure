#include "SeqList.h"

void SLInit(SL* psl)
{
	assert(psl);
	psl-> a = NULL;
	psl->size = psl->capacity = 0;
}

void SLDistroy(SL* psl)
{
	assert(psl);
	free(psl->a);
	psl->a = NULL;
	psl->size = psl->capacity = 0;
}

void SLCheckCapacity(SL* psl)
{
	assert(psl);

	if (psl->size == psl->capacity)
	{
		int NewCapacity = psl->capacity == 0 ? 4 : psl->capacity * 2;
		SLDateType* tmp = realloc(psl->a, NewCapacity*sizeof(SLDateType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}

		psl->capacity = NewCapacity;
		psl->a = tmp;

	}
}

void SLPrint(SL* psl)
{
	assert(psl);
	for (int i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->a[i]);
	}
	printf("\n");
}

void SLPushFront(SL* psl, SLDateType x)
{
	assert(psl);
	SLCheckCapacity(psl);
	int end = psl->size;
	while (end > 0)
	{
		psl->a[end] = psl->a[end - 1];
		--end;
	}
	psl->a[0] = x;
	psl->size++;
}

void SLPushBack(SL* psl, SLDateType x)
{
	assert(psl);
	SLCheckCapacity(psl);
	psl->a[psl->size++] = x;
}

void SLPopFront(SL* psl)
{
	assert(psl);
	assert(psl->size > 0);
	int end = 0;
	while (end < psl->size - 1)
	{
		psl->a[end] = psl->a[end + 1];
		end++;
	}
	psl->size--;
}

void SLPopBack(SL* psl)
{
	assert(psl);
	assert(psl->size > 0);
	psl->size--;
}

int SLFind(SL* psl, SLDateType x)
{
	assert(psl);
	for (int i = 0; i < psl->size; i++)
	{
		if (psl->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void SLInsert(SL* psl, size_t pos, SLDateType x)
{
	assert(psl);
	assert(pos < psl->size);
	SLCheckCapacity(psl);
	for (int i = psl->size; i > pos; i--)
	{
		psl->a[i] = psl->a[i - 1];
	}
	psl->a[pos] = x;
	psl->size++;
}

void SLErase(SL* psl, size_t pos)
{
	assert(psl);
	assert(pos < psl->size);
	for (int i = pos; i < psl->size; i++)
	{
		psl->a[i] = psl->a[i + 1];
	}
	psl->size--;
}

void SLModify(SL* psl, size_t pos, SLDateType x)
{
	assert(psl);
	assert(pos < psl->size);
	psl->a[pos] = x;
}

