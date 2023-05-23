#include "SeqList.h"

void Test1()
{
	SL a;
	SLInit(&a);

	SLPushBack(&a, 1);
	SLPushBack(&a, 2);
	SLPushBack(&a, 3);
	SLPushBack(&a, 4);
	SLPushBack(&a, 5);
	SLPushFront(&a, 6);
	SLPrint(&a);

	SLPopBack(&a);
	SLPopFront(&a);
	SLPrint(&a);

	SLDistroy(&a);
}
void Test2()
{
	SL a;
	SLInit(&a);

	SLPushBack(&a, 1);
	SLPushBack(&a, 2);
	SLPushBack(&a, 3);
	SLPushBack(&a, 4);
	SLPushBack(&a, 5);
	SLPushFront(&a, 6);
	SLPrint(&a);

	printf("%d\n", SLFind(&a, 2));
	SLInsert(&a, 3, 5);
	SLPrint(&a);
	SLErase(&a, 3);
	SLPrint(&a);
	SLModify(&a, 3, 6);
	SLPrint(&a);

	SLDistroy(&a);
}
int main()
{
	Test2();
	return 0;
}