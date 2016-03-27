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
			int left_i = 2 * i + 1;
			if (array[i] < array[left_i])
				left_i++;
			else
			{
				int tmp = array[i];
				array[i] = array[left_i];
				array[left_i] = tmp;
			}
			if (array[i]>array[left_i])
			{
				int tmp = array[i];
				array[i] = array[left_i];
				array[left_i] = tmp;
			}
		}
	}
}