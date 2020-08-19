#include <iostream>
#include <cstdlib>

#include "bst.h"

using namespace std;

BST::BST()
{
    root = NULL;
};

BST::node *BST::CreateLeaf(int key)
{
    node *n = new node;
    n->key = key;

    n->left = NULL;
    n->right = NULL;

    return n;
};

//Add leaf -> This will make sure when you add a new node the traversal is
// start from the root node
void BST::AddLeaf(int key)
{
    AddLeafPrivate(key, root);
};

// Add leaf private
void BST::AddLeafPrivate(int key, node *Ptr)
{
    if (root == NULL)
    {
        root = CreateLeaf(key);
    }
    else if (key < Ptr->key)
    {
        if (Ptr->left != NULL)
        {
            AddLeafPrivate(key, Ptr->left);
        }
        else
        {
            Ptr->left = CreateLeaf(key);
        }
    }
    else if (key > Ptr->key)
    {
        if (Ptr->right != NULL)
        {
            AddLeafPrivate(key, Ptr->right);
        }
        else
        {
            Ptr->right = CreateLeaf(key);
        }
    }
    else
    {
        cout << "The key " << key << " has already been added to the tree" << endl;
    }
};

//print in order
void BST::PrintInOrder()
{
    PrintInOrderPrivate(root);
};

//print in order private
void BST::PrintInOrderPrivate(node *Ptr)
{
    if (root != NULL)
    {
        //1. Go to left
        if (Ptr->left != NULL)
        {
            PrintInOrderPrivate(Ptr->left);
        }
        // 2. Process current node
        cout << Ptr->key << " ";
        // 3. Go to Right
        if (Ptr->right != NULL)
        {
            PrintInOrderPrivate(Ptr->right);
        }
    }
    else
    {
        cout << "The tree is empty" << endl;
    }
};