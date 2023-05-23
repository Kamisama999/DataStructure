#include "SList.h"
#include "List.h"

void TestSList1()
{
	SLTNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushBack(&plist, 3);
	SListPrint(plist);

	SLTNode* pos = SListFind(plist, 1);
	if (pos)
	{
		SListInsert(&plist, pos, 5);
		SListPrint(plist);
		SListInsertAfter(pos, 4);
		SListPrint(plist);
	}
	else
	{
		printf("√ª’“µΩ\n");
	}
	SListPopFront(&plist);
	SListPrint(plist);
	SListPopBack(&plist);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPrint(plist);
	SListEraseAfter( pos);
	SListPrint(plist);

	SListDestory(&plist);
}

void TestList1()
{
	LTNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPrint(plist);
	ListPushFront(plist, 3);
	ListPushFront(plist, 4);
	ListPrint(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPrint(plist);
	ListDestory(plist);
	plist = NULL;

}

int main()
{
	int n, m;
	LTNode* guard = ListInit();
	LTNode* cur = guard;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		ListPushBack(guard, i);
	while (ListSize(guard) > 1)
	{
		cur = guard;
		for (int i = 0; i < m; i++)
		{
			cur = cur->next;
		}
		ListErase(cur);
	}
	printf("%d", guard->next->data + 1);
	return 0;
}