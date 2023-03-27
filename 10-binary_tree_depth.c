#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary node
 *
 * @tree: Pointer to the node to measure the depth of
 * Return: Depth of node, or 0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree->parent)
		return (1 + binary_tree_depth(tree->parent));
	return (0);
}
