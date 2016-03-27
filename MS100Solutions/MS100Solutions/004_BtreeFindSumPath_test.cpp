#include "004_BtreeFindSumPath.h"

using namespace Ljs;

int BtreeFindSumPath_test()
{
	TreeNode *root = new TreeNode(40);
	root->left = new TreeNode(20);
	root->left->left = new TreeNode(10);
	root->left->right = new TreeNode(30);
	root->right = new TreeNode(60);
	root->right->left = new TreeNode(50);
	root->right->right = new TreeNode(70);

	root->printPath(root, 70);
	return 0;
}