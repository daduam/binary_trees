#include "binary_trees.h"

/**
 * _height - Measures the height of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure the height
 * Return: Height of the tree, or 0 if tree is NULL.
 */
int _height(const binary_tree_t *tree)
{
	int height_l, height_r;

	if (!tree)
		return (0);
	height_l = 1 + _height(tree->left);
	height_r = 1 + _height(tree->right);
	return (height_l > height_r ? height_l : height_r);
}

/**
 * _binary_tree_levelorder - Apply func on the root of the current subtree
 *
 * @root: Pointer to root node of the subtree
 * @func: Pointer to a function to call for each node
 * @level: Node level in subtree
 */
void _binary_tree_levelorder(const binary_tree_t *root,
							 void (*func)(int),
							 int level)
{
	if (!root)
		return;
	if (level == 0)
	{
		func(root->n);
	}
	else
	{
		_binary_tree_levelorder(root->left, func, level - 1);
		_binary_tree_levelorder(root->right, func, level - 1);
	}
}

/**
 * binary_tree_levelorder - Goes through a binary tree using
 *                          level-order traversal
 *
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int i, height;

	if (!tree || !func)
		return;
	height = _height(tree);
	for (i = 0; i < height; i++)
		_binary_tree_levelorder(tree, func, i);
}
