// MS100Solutions.cpp : �������̨Ӧ�ó������ڵ㡣
//

#pragma once
#include "Common.h"
namespace Ljs{
	class TreeNode
	{
	public:
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int v = -1) :val(v), left(nullptr), right(nullptr) {}

		void VisitTree(TreeNode *root)
		{
			if (root == nullptr)
			{
				return;
			}
			VisitTree(root->left);
			printf("%d\n", root->val);
			VisitTree(root->right);
		}

		void helper(TreeNode *& head, TreeNode *& tail, TreeNode *root) {
			TreeNode *leftTail, *rightHead;
			if (root == nullptr)
			{
				head = nullptr;
				tail = nullptr;
				return;
			}
			helper(head, leftTail, root->left);
			helper(rightHead, tail, root->right);
			if (leftTail != nullptr)
			{
				leftTail->right = root;
				root->left = leftTail;
			}
			else
				head = root;
			if (rightHead != nullptr)
			{
				rightHead->left = root;
				root->right = rightHead;
			}
			else
				tail = root;
		}

		TreeNode * treeToLinkedList(TreeNode * root) {
			TreeNode * head, *tail;
			helper(head, tail, root);
			return head;
		}
	};
}