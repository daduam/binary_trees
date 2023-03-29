#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 *
 * @tree: Double pointer to the root node of the BST to insert the value
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (!tree)
		return (NULL);
	if (!(*tree))
		return (*tree = binary_tree_node(NULL, value));
	if (value > (*tree)->n)
	{
		if ((*tree)->right)
			return (bst_insert(&((*tree)->right), value));
		return ((*tree)->right = binary_tree_node(*tree, value));
	}
	if (value < (*tree)->n)
	{
		if ((*tree)->left)
			return (bst_insert(&((*tree)->left), value));
		return ((*tree)->left = binary_tree_node(*tree, value));
	}
	return (NULL);
}
