//#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "005_makeHeap.h"
using namespace Ljs;

int MakeHeap_test()
{
	int arr[] = { 1, 3, 4, 5, 7, 2, 6, 8, 0 };
	for (int i = 0; i < 8; ++i)
	{
		makeHeap(arr+i, 9-i);
		for (auto e : arr)
		{
			printf("%d  ", e);
		}
		printf("\n");
}
	return 0;
}

TEST_CASE("MakeHeap_test", "one") {
	REQUIRE(MakeHeap_test() == 0);
}