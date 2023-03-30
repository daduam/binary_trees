#include "binary_trees.h"

/**
 * find_minimum - Find node with smallest value in subtree
 *
 * @root: Pointer to the root of the subtree
 * Return: Node with smallest value in subtree
 */
bst_t *find_minimum(bst_t *root)
{
	if (!root->left)
		return (root);
	return (find_minimum(root->left));
}

/**
 * delete_node - Removes a node from the tree
 *
 * @root: Pointer to the root of the tree
 * @node: Pointer to node to remove
 * Return: Pointer to new root of tree after removing node
 */
bst_t *delete_node(bst_t *root, bst_t *node)
{
	bst_t *parent, *tmp;

	parent = node->parent;
	if (!node->left)
	{
		if (parent && parent->left == node)
			parent->left = node->right;
		else if (parent)
			parent->right = node->right;
		if (node->right)
			node->right->parent = parent;
		tmp = node->right;
		free(node);
		return (parent ? root : tmp);
	}
	if (!node->right)
	{
		if (parent && parent->left == node)
			parent->left = node->left;
		else if (parent)
			parent->right = node->left;
		if (node->left)
			node->left->parent = parent;
		tmp = node->left;
		free(node);
		return (parent ? root : tmp);
	}
	tmp = find_minimum(node->right);
	node->n = tmp->n;
	return (delete_node(root, tmp));
}

/**
 * _bst_remove - bst_remove recursive helper
 *
 * @root: Pointer to the root node of the tree where you will remove a node
 * @node: Pointer to current node of the tree
 * @value: Value to remove in the tree
 * Return: Value removed from the tree, or NULL
 */
bst_t *_bst_remove(bst_t *root, bst_t *node, int value)
{
	if (!node)
		return (NULL);
	if (value == node->n)
		return (delete_node(root, node));
	if (value < node->n)
		return (_bst_remove(root, node->left, value));
	return (_bst_remove(root, node->right, value));
}

/**
 * bst_remove - Removes a node from a Binary Search Tree
 *
 * @root: Pointer to the root node of the tree where you will remove a node
 * @value: Value to remove in the tree
 * Return: Pointer to the new root node of the tree after
 *         removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (!root)
		return (NULL);
	return (_bst_remove(root, root, value));
}
