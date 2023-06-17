#include <stdio.h>
#include <stdlib.h>
#include "binary-tree.h"

BinaryTreeNode* create_binary_tree(int value)
{
    BinaryTreeNode* tree = malloc(sizeof(BinaryTreeNode));
    tree->value = value;
    tree->left = 0;
    tree->right = 0;
    return tree;
}

void free_binary_tree(BinaryTreeNode* tree)
{
    if (tree == 0)
        return;
    free_binary_tree(tree->left);
    free_binary_tree(tree->right);
    free(tree);
}

BinaryTreeNode* add_binary_tree_node_left(BinaryTreeNode* tree, int value)
{
    tree->left = create_binary_tree(value);
}

BinaryTreeNode* add_binary_tree_node_right(BinaryTreeNode* tree, int value)
{
    tree->right = create_binary_tree(value);
}
