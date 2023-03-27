#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree
 *
 * @tree: Pointer to the root node of the tree to rotate
 * Return: Pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *x, *y, *new_root;

	if (!tree)
		return (NULL);

	x = new_root = tree;
	if (!x->right)
		return (tree);

	y = x->right;
	x->right = y->left;
	if (y->left)
		y->left->parent = x;
	y->parent = x->parent;
	if (!x->parent)
		new_root = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;
	y->left = x;
	x->parent = y;
	return (new_root);
}
