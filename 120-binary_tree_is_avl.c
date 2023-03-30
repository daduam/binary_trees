#include <limits.h>
#include "binary_trees.h"

/**
 * _binary_tree_is_avl - binary_tree_is_avl helper
 *
 * @tree: Pointer to the root node of the tree to check
 * @min: Minimum value in current subtree
 * @max: Maximum value in current subtree
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int _binary_tree_is_avl(const binary_tree_t *tree, int min, int max)
{
	int height_l, height_r;

	if (!tree)
		return (0);
	if (tree->n < min || tree->n > max)
		return (-1);
	height_l = _binary_tree_is_avl(tree->left, min, tree->n - 1);
	if (height_l == -1)
		return (-1);
	height_r = _binary_tree_is_avl(tree->right, tree->n + 1, max);
	if (height_r == -1)
		return (-1);
	if ((height_l - height_r > 1) || (height_l - height_r < -1))
		return (-1);
	return (height_l > height_r ? height_l + 1 : height_r + 1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 *
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree && _binary_tree_is_avl(tree, INT_MIN, INT_MAX) > 0)
		return (1);
	return (0);
}
