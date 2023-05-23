#include "Heap.h"

//int main()
//{
//	int b[] = { 5,8,9,18,35,4,32,4,27,37,25 };
//	HP hp;
//	HeapInit(&hp);
//	for (int i = 0; i < sizeof(b) / sizeof(b[0]); i++)
//	{
//		HeapPush(&hp, b[i]);
//	}
//	HeapPrint(&hp);
//	return 0;
//}

//堆排序
void HeapSort(int* a, int n)
{
	//建堆 -- 向上调整  O(N*logN)
	//for (int i = 1; i < n; i++)
	//{
	//	AdjustUp(a, i);
	//}
	// 
	//建堆 -- 向下调整   O(N)
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	int i = 1;
	while (i < n)
	{
		Swap(&a[0], &a[n - i]);
		AdjustDown(a, n-i, 0);
		++i;
	}
}

int main()
{
	int a[] = { 15,1,19,25,8,34,65,4,27,7 };
	HeapSort(a, sizeof(a) / sizeof(a[0]));
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}