#pragma once
#include "Common.h"


class linkedListNode
{
public:
	linkedListNode *next;
	int value;
	linkedListNode(int i = -1):value(-1),next(nullptr){}

	linkedListNode* reverse(linkedListNode *head)
	{
		if (head == nullptr)
		{
			return head;
		}
		if (head->next == nullptr)
		{
			return head;
		}
		linkedListNode* p = reverse(head->next);
		head->next->next = head;
		head->next = nullptr;
		return p;
	}
	linkedListNode* reverseNoRecurisve(linkedListNode* head)
	{
		if (head == nullptr)
		{
			return head;
		}
		linkedListNode* p = head;
		linkedListNode* prev = nullptr;
		while (p->next != nullptr)
		{
			p->next = prev;
			prev = p;
			p = p->next;
		}
		p->next = prev;
		return p;
	}

	linkedListNode* testCylic(linkedListNode* h1)
	{
		linkedListNode* p1 = h1, *p2 = h1;
		while (p1 != nullptr && p2 != nullptr)
		{
			p1 = p1->next;
			p2 = p2->next->next;
			if (p1 == p2)
			{
				return p1;
			}
		}
		return nullptr;
	}

};

