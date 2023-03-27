#include "binary_trees.h"

/**
 * _size - Measures the size of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure the size
 * Return: Size of the tree, or 0 if tree is NULL
 */
int _size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + _size(tree->left) + _size(tree->right));
}

/**
 * _binary_tree_is_complete - binary_tree_is_complete helper
 *
 * @tree: Pointer to the root node of the tree to check
 * @idx: Index of node in array representation of binary tree
 * @size: Number of nodes in binary tree
 * Return: 1 if binary tree is complete. Otherwise 0.
 */
int _binary_tree_is_complete(const binary_tree_t *tree, int idx, int size)
{
	if (!tree)
		return (1);
	if (idx >= size)
		return (0);
	return (_binary_tree_is_complete(tree->left, 2 * idx + 1, size) &&
			_binary_tree_is_complete(tree->right, 2 * idx + 2, size));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 *
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if binary tree is complete. Otherwise 0.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (_binary_tree_is_complete(tree, 0, _size(tree)));
}
