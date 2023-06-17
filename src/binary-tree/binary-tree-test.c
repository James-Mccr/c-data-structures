#include <stdio.h>
#include "binary-tree.h"

static unsigned char quiet_pass = 0;

int assert_equal(BinaryTreeNode* actual, BinaryTreeNode* expected)
{
    if (actual->value != expected->value)
    {
        printf("Binary tree value was %d but expected %d\n", actual->value, expected->value);
        return 0;
    }

    if(actual->left != expected->left)
    {
        printf("Binary tree left was %d but expected %d\n", actual->left, expected->left);
        return 0;
    }

    if(actual->right != expected->right)
    {
        printf("Binary tree value was %d but expected %d\n", actual->right, expected->right);
        return 0;
    }
    
    if (!quiet_pass)
    {
        printf("PASS\n");
    }
    
    return 1;
}

void test_add_binary_tree_node_right()
{
    printf("test_add_binary_tree_node_right...");
    BinaryTreeNode* root = create_binary_tree(0);
    BinaryTreeNode* right = add_binary_tree_node_right(root, 1);
    BinaryTreeNode expectedRoot = { 0, 0, right };
    BinaryTreeNode expectedRight = { 1, 0, 0 };

    quiet_pass = 1;
    assert_equal(root, &expectedRoot);
    quiet_pass = 0;
    assert_equal(right, &expectedRight);

    free_binary_tree(root);
}

void test_add_binary_tree_node_left()
{
    printf("test_add_binary_tree_node_left...");
    BinaryTreeNode* root = create_binary_tree(0);
    BinaryTreeNode* left = add_binary_tree_node_left(root, 1);
    BinaryTreeNode expectedRoot = { 0, left, 0 };
    BinaryTreeNode expectedLeft = { 1, 0, 0 };

    quiet_pass = 1;
    assert_equal(root, &expectedRoot);
    quiet_pass = 0;
    assert_equal(left, &expectedLeft);

    free_binary_tree(root);
}

void test_create_binary_tree()
{
    printf("test_create_binary_tree...");
    BinaryTreeNode* actual = create_binary_tree(0);
    BinaryTreeNode expected = { 0, 0, 0 };

    assert_equal(actual, &expected);

    free_binary_tree(actual);
}

void main()
{
    printf("Running binary tree tests...\n");

    test_create_binary_tree();

    test_add_binary_tree_node_left();

    test_add_binary_tree_node_right();
}