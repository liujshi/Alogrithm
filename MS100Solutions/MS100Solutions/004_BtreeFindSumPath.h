#pragma once
#include "Common.h"
namespace Ljs
{
	class TreeNode
	{
	public:
		int val;
		TreeNode *left;
		TreeNode *right;

		TreeNode(int val = -1) :val(val), left(nullptr), right(nullptr) {}

		void printPath(TreeNode* root,int sum)
		{
			int path[1024] = {0};
			printHelper(root, sum, path, 0);
		}
		void printHelper(TreeNode* root,int sum, int path[], int index)
		{
			path[index++] = root->val;
			sum -= root->val;
			if (root->left==nullptr && root->right ==nullptr)
			{
				if (sum == 0)
				{
					for (int i = 0; i < index;++i)
					{
						printf("%d\n", path[i]);
					}
				}
				return;
			}
			else{
				if (root->left!=nullptr)
				{
					printHelper(root->left, sum, path, index);
				}
				if (root->right!=nullptr)
				{
					printHelper(root->right, sum, path, index);
				}
			}
			sum += root->val;
			index--;
		}
	};
}