#include <limits.h>
#include "binary_trees.h"

/**
 * _binary_tree_is_bst - binary_tree_is_bst helper
 *
 * @tree: Pointer to the root node of the tree to check
 * @min: Minimum value in current subtree
 * @max: Maximum value in current subtree
 * Return: 1 if tree is a valid BST, and 0 otherwise.
 */
int _binary_tree_is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (_binary_tree_is_bst(tree->left, min, tree->n - 1) &&
			_binary_tree_is_bst(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 *
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, and 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (_binary_tree_is_bst(tree, INT_MIN, INT_MAX));
}
