#include "binary_trees.h"

/**
 * bst_remove - Removes a node from a Binary Search Tree
 *
 * @root: Pointer to the root node of the tree where you will remove a node
 * @value: Value to remove in the tree
 * Return: Pointer to the new root node of the tree after
 *         removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp, *succ;

	if (!root)
		return (NULL);
	if (value > root->n)
	{
		root->right = bst_remove(root->right, value);
		return (root);
	}
	if (value < root->n)
	{
		root->left = bst_remove(root->left, value);
		return (root);
	}
	if (!root->left)
	{
		tmp = root->right;
		free(root);
		return (tmp);
	}
	if (!root->right)
	{
		tmp = root->left;
		free(root);
		return (tmp);
	}
	tmp = root;
	succ = root->right;
	while (succ->left)
	{
		tmp = succ;
		succ = succ->left;
	}
	if (tmp != root)
		tmp->left = succ->right;
	else
		tmp->right = succ->right;
	root->n = succ->n;
	free(succ);
	return (root);
}
