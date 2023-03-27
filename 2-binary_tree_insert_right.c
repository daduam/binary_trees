#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right-child
 *                            of another node
 *
 * @parent: Pointer to the node to insert the right-child in
 * @value: Value to store in the new node
 * Return: Pointer to the created node,
 *         or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_right;

	if (!parent)
		return (NULL);

	new_right = malloc(sizeof(binary_tree_t));
	if (!new_right)
		return (NULL);

	new_right->n = value;
	new_right->parent = parent;
	new_right->left = NULL;

	new_right->right = parent->right;
	if (parent->right)
		parent->right->parent = new_right;
	parent->right = new_right;

	return (new_right);
}
