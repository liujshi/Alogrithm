// MS100Solutions.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class TreeNode
{
public:
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int v = -1) :val(v), left(nullptr), right(nullptr) {}
};
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

int main()
{
	TreeNode *root = new TreeNode(40);
	root->left = new TreeNode(20);
	root->left->left = new TreeNode(10);
	root->left->right = new TreeNode(30);
	root->right = new TreeNode(60);
	root->right->left = new TreeNode(50);
	root->right->right = new TreeNode(70);

	TreeNode* p = treeToLinkedList(root);
	for (; p; p = p->right)
	{
		printf("%d\n", p->val);
	}

	return 0;
}

