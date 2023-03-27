#include "binary_trees.h"

/**
 * _depth - Measures the depth of a node in a binary node
 *
 * @node: Pointer to the node to measure the depth of
 * Return: Depth of node, or 0 if tree is NULL
 */
size_t _depth(const binary_tree_t *node)
{
	if (node && node->parent)
		return (1 + _depth(node->parent));
	return (0);
}

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 *
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 * Return: Pointer to the lowest common ancestor node of the two given nodes.
 *         Otherwise NULL.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	size_t i, first_depth, second_depth;
	binary_tree_t *pfirst, *psecond;

	if (!first || !second)
		return (NULL);

	first_depth = _depth(first);
	second_depth = _depth(second);
	pfirst = (binary_tree_t *)first;
	psecond = (binary_tree_t *)second;

	if (first_depth > second_depth)
		for (i = 0; i < first_depth - second_depth; i++)
			pfirst = pfirst->parent;
	else if (second_depth > first_depth)
		for (i = 0; i < second_depth - first_depth; i++)
			psecond = psecond->parent;

	while (pfirst && psecond)
	{
		if (pfirst == psecond)
			return (pfirst);
		pfirst = pfirst->parent;
		psecond = psecond->parent;
	}

	return (NULL);
}
