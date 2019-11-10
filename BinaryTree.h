//
//  BinaryTree.h
//
//  Created by Andrew Nguyen on 11/10/19.
//  Copyright © 2019 Andrew Nguyen. All rights reserved.
//

#pragma once
#include "TreeNode.h"
template <typename T>
class BinaryTree
{
public:
    TreeNode<T>* root;
    BinaryTree();
    
    void add(T inputData);
    void remove(T inputData);
    int search(T inputData);
    
private:
    void add(T inputData, TreeNode<T> *childNode);
    int search(T inputData, TreeNode<T>* childNode);
    
};

template<typename T>
inline BinaryTree<T>::BinaryTree()
{
    root = nullptr;
}

template<typename T>
inline void BinaryTree<T>::add(T inputData)
{
    if (root == nullptr)
    {
        TreeNode<T>* node = new TreeNode<T>();
        node->data = inputData;
        root = node;
    }
    else
    {
        add(inputData, root);
    }
}

template<typename T>
inline int BinaryTree<T>::search(T inputData)
{
    if (root == nullptr)
    {
        return 0;
    }
    else
    {
        search(inputData, root);
    }
}

template<typename T>
inline void BinaryTree<T>::add(T inputData, TreeNode<T> *childNode)
{
    if (inputData < childNode->data)
    {
        if (childNode->left == nullptr)
        {
            TreeNode<T>* node = new TreeNode<T>();
            node->data = inputData;
            childNode->left = node;
        }
        else
        {
            add(inputData, childNode->left);
        }
    }
    else
    {
        if (childNode->right == nullptr)
        {
            TreeNode<T>* node = new TreeNode<T>();
            node->data = inputData;
            childNode->right = node;
        }
        else
        {
            add(inputData, childNode->right);
        }
    }
}

template<typename T>
inline int BinaryTree<T>::search(T inputData, TreeNode<T>* childNode)
{
    int returnVal = -1;
    if (inputData == childNode->data)
    {
        return 1;
    }
    else if (inputData < childNode->data)
    {
        if (childNode->left != nullptr)
        {
            returnVal = search(inputData, childNode->left);
        }
    }
    else
    {
        if (childNode->right != nullptr)
        {
            returnVal = search(inputData, childNode->right);
        }
    }
    
    if (returnVal == -1)
    {
        return returnVal;
        
    }
    else
    {
        return returnVal + 1;
    }
}
 /* BinaryTree_h */
