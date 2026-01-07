#include "rb.h"
using ptr = RedBlackTree::ptr;

RedBlackTree::RedBlackTree(){}

const ptr RedBlackTree::getRoot() const
{ 
    return root; 
}

ptr RedBlackTree::insert(int data)
{
    ptr newnodePtr = new node(data);
    if (!root) {
        root = newnodePtr;
        root->color = 0; // set root color as black
        return newnodePtr;
    }
    insert(root, newnodePtr);
    return newnodePtr;
}

// auxiliary function to perform RBT insertion of a node
// you may assume start is not nullptr
void RedBlackTree::insert(ptr start, ptr newnodePtr)
{
    // choose direction
    if (newnodePtr->data < start->data) {
        if (start->left == nullptr) {
            start->left = newnodePtr;
            newnodePtr->parent = start;
            newnodePtr->color = 1;
            fixup(newnodePtr);
            return;
        }
    // recurse down the tree
        insert(start->left, newnodePtr);
    } else {
        if (start->right == nullptr) {
            start->right = newnodePtr;
            newnodePtr->parent = start;
            newnodePtr->color = 1;
            fixup(newnodePtr);
            return;
        }
        insert(start->right, newnodePtr);
    }

    return;
}

// Credits to Adrian Schneider
void RedBlackTree::printRBT(ptr start, const std::string& prefix, bool isLeftChild) const
{
    if (!start) return;

    std::cout << prefix;
    std::cout << (isLeftChild ? "|--" : "|__" );
    // print the value of the node
    std::cout << start->data << "(" << start->color << ")" << std::endl;
    // enter the next tree level - left and right branch
    printRBT(start->left, prefix + (isLeftChild ? "│   " : "    "), true);
    printRBT(start->right, prefix + (isLeftChild ? "│   " : "    "), false);
}

// Function performing right rotation
// of the passed node
void RedBlackTree::rightrotate(ptr loc)
{
    ptr y = loc->left;
    loc->left = y->right;
    if (y->right != nullptr)
        y->right->parent = loc;
    y->parent = loc->parent;
    if (loc->parent == nullptr)
        root = y;
    else if (loc == loc->parent->right)
        loc->parent->right = y;
    else
        loc->parent->left = y;
    y->right = loc;
    loc->parent = y;
}

// Function performing left rotation
// of the passed node
void RedBlackTree::leftrotate(ptr loc)
{
    ptr y = loc->right;
    loc->right = y->left;
    if (y->left != nullptr)
        y->left->parent = loc;
    y->parent = loc->parent;
    if (loc->parent == nullptr)
        root = y;
    else if (loc == loc->parent->left)
        loc->parent->left = y;
    else
        loc->parent->right = y;
    y->left = loc;
    loc->parent = y;
}

// This function fixes violations
// caused by RBT insertion
void RedBlackTree::fixup(ptr loc)
{
    while (loc != root && loc->parent->color == 1) {
        if (loc->parent == loc->parent->parent->left) {
            ptr uncle = loc->parent->parent->right;
            if (uncle != nullptr && uncle->color == 1) {
                loc->parent->color = 0;
                uncle->color = 0;
                loc->parent->parent->color = 1;
                loc = loc->parent->parent;
            } else {
                if (loc == loc->parent->right) {
                    loc = loc->parent;
                    leftrotate(loc);
                }
                loc->parent->color = 0;
                loc->parent->parent->color = 1;
                rightrotate(loc->parent->parent);
            }
        } else {
            ptr uncle = loc->parent->parent->left;
            if (uncle != nullptr && uncle->color == 1) {
                loc->parent->color = 0;
                uncle->color = 0;
                loc->parent->parent->color = 1;
                loc = loc->parent->parent;
            } else {
                if (loc == loc->parent->left) {
                    loc = loc->parent;
                    rightrotate(loc);
                }
                loc->parent->color = 0;
                loc->parent->parent->color = 1;
                leftrotate(loc->parent->parent);
            }
        }
    }
    root->color = 0;
}

// Function to print inorder traversal
// of the fixated tree
void RedBlackTree::inorder(ptr start) const
{
    if (!start)
        return;
    
    inorder(start->left);
    std::cout << start->data << " ";
    inorder(start->right);
}