#pragma once
#include "Common.h"

namespace Ljs
{
	void makeHeap(int array[], int n)
	{
		if (n<=1)
		{
			return;
		}
		for (int i = n / 2; i >= 0;--i)
		{
			int left_i = 2 * i;
			if (array[i-1] < array[left_i-1])
				left_i++;
			else
			{
				int tmp = array[i-1];
				array[i-1] = array[left_i-1];
				array[left_i-1] = tmp;
			}
			if (left_i<=n && array[i-1]>array[left_i-1])
			{
				int tmp = array[i-1];
				array[i-1] = array[left_i-1];
				array[left_i-1] = tmp;
			}
		}
	}
}