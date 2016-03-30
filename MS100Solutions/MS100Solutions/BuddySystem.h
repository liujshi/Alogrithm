#pragma once
#include "Common.h"

// ConsoleApplication14.cpp : 定义控制台应用程序的入口点。
//
#include <cassert>

#define IS_POWER_OF_2(x) (!((x)&((x)-1)))
#define LEFT_LEAF(index) ((index) * 2 + 1)
#define RIGHT_LEAF(index) ((index) * 2 + 2)
#define PARENT(index) ( ((index) + 1) / 2 - 1)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
static unsigned fixsize(unsigned size) {
	size |= size >> 1;
	size |= size >> 2;
	size |= size >> 4;
	size |= size >> 8;
	size |= size >> 16;
	return size + 1;
}


class Buddy
{
public:
	Buddy(size_t size = 32) :len(size)
	{
		unsigned node_size;
		if (size < 1 || !IS_POWER_OF_2(size))
		{
			return;
		}
		look_table = new unsigned[2 * size - 1];
		node_size = 2 * size;
		for (int i = 0; i < 2 * size - 1; ++i)
		{
			if (IS_POWER_OF_2(i + 1))
			{
				node_size /= 2;
			}
			look_table[i] = node_size;
		}
	}
	~Buddy()
	{
		delete look_table;
		look_table = nullptr;
		len = 0;
	}
	int alloc(int size)
	{
		size_t index = 0;
		unsigned offset;
		if (look_table == nullptr)
		{
			return 0;
		}
		if (size <= 0)
		{
			size = 1;
		}
		else if (!IS_POWER_OF_2(size))
		{
			size = fixsize(size);
		}
		if (look_table[index] < size)
		{
			return -1;
		}
		unsigned node_size;
		for (node_size = len; node_size != size; node_size /= 2)
		{
			if (look_table[LEFT_LEAF(index)] >= size)
			{
				index = LEFT_LEAF(index);
			}
			else
			{
				index = RIGHT_LEAF(index);
			}
		}
		look_table[index] = 0;
		offset = (index + 1)*node_size - len;
		while (index)
		{
			index = PARENT(index);
			look_table[index] = MAX(look_table[LEFT_LEAF(index)], look_table[RIGHT_LEAF(index)]);
		}
		return offset;
	}
	void free(int offset)
	{
		unsigned node_size, index = 0;

		assert(0 <= offset&&offset < len);

		node_size = 1;
		index = offset + len - 1;
		for (; look_table[index]; index = PARENT(index))
		{
			node_size *= 2;
			if (index == 0)
				return;
		}
		look_table[index] = node_size;
		while (index)
		{
			index = PARENT(index);
			node_size *= 2;
			unsigned left_size = look_table[LEFT_LEAF(index)];
			unsigned right_size = look_table[RIGHT_LEAF(index)];
			if (left_size + right_size == node_size)
			{
				look_table[index] = node_size;
			}
			else
				look_table[index] = MAX(left_size, right_size);
		}

	}
	int offset_size(int offset) {
		unsigned node_size, index = 0;

		assert(offset >= 0 && offset < len);

		node_size = 1;
		for (index = offset + len - 1; look_table[index]; index = PARENT(index))
			node_size *= 2;

		return node_size;
	}
	void dump()
	{
		char *canvas = new char[len + 1];
		memset(canvas, '_', len);
		canvas[len] = '\0';
		unsigned node_size = len * 2;
		for (int i = 0; i < 2 * len - 1; ++i)
		{
			if (IS_POWER_OF_2(i + 1))
			{
				node_size /= 2;
			}
			if (look_table[i] == 0)
			{
				if (i >= len - 1)
				{
					canvas[i - len + 1] = '*';
				}
				else if (look_table[LEFT_LEAF(i)] && look_table[RIGHT_LEAF(i)])
				{
					unsigned offset = (i + 1) * node_size - len;
					for (unsigned j = offset; j < offset + node_size; ++j)
					{
						canvas[j] = '*';
					}
				}
			}
		}
		puts(canvas);
		putchar('\n');
	}
private:
	unsigned *look_table;
	size_t len;
};

