#include "005_BuildHeap.h"

using namespace Ljs;

int main()
{
	int arr[] = { 1, 3, 4, 5, 7, 2, 6, 8, 0 };
	makeHeap(arr, 7);
	for (auto e:arr)
	{
		printf("%d\n", e);
	}
	return 0;
}