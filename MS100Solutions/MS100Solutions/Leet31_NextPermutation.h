#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	void reverse(vector<int>& nums, int begin, int end)
	{
		while (begin < end)
		{
			swap(nums[begin++], nums[end--]);
		}
	}
	void nextPermutation(vector<int> nums)
	{
		int len = nums.size();
		if (len < 2) return;
		int i = len - 1;
		while (i > 0)
		{
			if (nums[i-1]<nums[i])
			{
				int flag = i - 1;
				while (nums[flag] <= nums[i - 1])
					flag--;
				swap(nums[flag], nums[i - 1]);
				reverse(nums,i,flag);
				return;
			}
			--i;
		}
		reverse(nums, 0, len - 1);
		return;
	}
};