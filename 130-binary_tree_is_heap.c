#include "binary_trees.h"

/**
 * _size - Measures the size of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure the size
 * Return: Size of the tree, or 0 if tree is NULL
 */
size_t _size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + _size(tree->left) + _size(tree->right));
}

/**
 * _is_complete - Checks if binary tree is complete
 *
 * @tree: Pointer to the root node of the subtree to check
 * @i: Index of current node
 * @size: Number of nodes in the current subtree
 * Return: 1 if tree is complete, 0 otherwise
 */
int _is_complete(const binary_tree_t *tree, size_t i, size_t size)
{
	if (!tree)
		return (1);
	if (i >= size)
		return (0);
	return (_is_complete(tree->left, 2 * i + 1, size) &&
			_is_complete(tree->right, 2 * i + 2, size));
}

/**
 * _is_heap - Checks if a binary tree is a max heap
 *
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a max heap, and 0 otherwise
 */
int _is_heap(const binary_tree_t *tree)
{
	if (!tree->left && !tree->right)
		return (1);
	if (!tree->right)
		return (tree->n >= tree->left->n);
	else if (tree->n >= tree->left->n && tree->n >= tree->right->n)
		return (_is_heap(tree->left) && _is_heap(tree->right));
	else
		return (0);
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 *
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid Max Binary Heap, and 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	size_t size = _size(tree);
	size_t i = 0;

	if (_is_complete(tree, i, size) && _is_heap(tree))
		return (1);
	return (0);
}
