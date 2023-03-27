#include "binary_trees.h"

/**
 * _leaf - Return a leaf node from tree
 *
 * @tree: Pointer to the root node of the tree to check
 * Return: Leaf node
 */
const binary_tree_t *_leaf(const binary_tree_t *tree)
{
	if (tree && !tree->left && !tree->right)
		return (tree);
	return (_leaf(tree->left ? tree->left : tree->right));
}

/**
 * _depth - Measures the depth of a node in a binary node
 *
 * @tree: Pointer to the node to measure the depth of
 * Return: Depth of node, or 0 if tree is NULL
 */
size_t _depth(const binary_tree_t *tree)
{
	if (tree && tree->parent)
		return (1 + _depth(tree->parent));
	return (0);
}

/**
 * _binary_tree_is_perfect - binary_tree_is_perfect recursive helper
 *
 * @tree: Pointer to the root node of the tree to check
 * @depth: Depth of the binary tree
 * @level: Level of the current node
 * Return: 1 if tree is perfect, 0 if otherwise
 */
int _binary_tree_is_perfect(const binary_tree_t *tree,
							size_t depth,
							size_t level)
{
	if (!tree->left && !tree->right)
		return (depth == level);

	if (!tree->left || !tree->right)
		return (0);

	return (_binary_tree_is_perfect(tree->left, depth, level + 1) &&
			_binary_tree_is_perfect(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 *
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is perfect, 0 if otherwise or if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (_binary_tree_is_perfect(tree, _depth(_leaf(tree)), 0));
}
