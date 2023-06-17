// Author: James M
// 17/06/2023
// Header for binary tree structure

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct binary_tree_node
{
	int value;
	struct binary_tree_node* left;
	struct binary_tree_node* right;
} BinaryTreeNode;

BinaryTreeNode* create_binary_tree(int value);

void free_binary_tree(BinaryTreeNode* tree);

BinaryTreeNode* add_binary_tree_node_left(BinaryTreeNode* tree, int value);

BinaryTreeNode* add_binary_tree_node_right(BinaryTreeNode* tree, int value);

#endif