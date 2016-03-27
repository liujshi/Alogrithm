#include "BTree2LinkedList.h"
using namespace Ljs;
int main()
{
	TreeNode *root = new TreeNode(40);
	root->left = new TreeNode(20);
	root->left->left = new TreeNode(10);
	root->left->right = new TreeNode(30);
	root->right = new TreeNode(60);
	root->right->left = new TreeNode(50);
	root->right->right = new TreeNode(70);

	TreeNode* p = root->treeToLinkedList(root);
	for (; p; p = p->right)
	{
		printf("%d\n", p->val);
	}
	return 0;
}