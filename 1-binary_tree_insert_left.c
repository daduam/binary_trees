#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node
 *
 * @parent: Pointer to the node to insert the left-child in
 * @value: Value to store in the new node
 * Return: Pointer to the created node,
 *         or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_left;

	if (!parent)
		return (NULL);
	new_left = malloc(sizeof(binary_tree_t));
	if (!new_left)
		return (NULL);
	new_left->n = value;
	new_left->parent = parent;
	new_left->right = NULL;
	new_left->left = parent->left;
	if (parent->left)
		parent->left->parent = new_left;
	parent->left = new_left;
	return (new_left);
}
