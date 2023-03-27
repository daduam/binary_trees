#include "binary_trees.h"

/**
 * _height - Measures the height of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure the height
 * Return: Height of the tree, or 0 if tree is NULL.
 */
static size_t _height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	if (!tree)
		return (0);

	height_l = height_r = 1;
	if (tree->left)
		height_l = 1 + _height(tree->left);
	if (tree->right)
		height_r = 1 + _height(tree->right);
	return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure the balance factor
 * Return: Balance factor of tree, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (_height(tree->left) - _height(tree->right));
}
