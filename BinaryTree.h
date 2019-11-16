//
//  BinaryTree.h
//  hw5
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
    void printPreOrder();
    void printBreadthFirst();
    
private:
    void add(T inputData, TreeNode<T> *childNode);
    int search(T inputData, TreeNode<T> *childNode);
    void printPreOrder(TreeNode<T> *childNode);
    void printBreadthFirst(TreeNode<T> *childNode);
    
};

template<typename T>
inline BinaryTree<T>::BinaryTree() {
    root = nullptr;
}

template<typename T>
inline void BinaryTree<T>::add(T inputData) {
    if (root == nullptr) {
        TreeNode<T>* node = new TreeNode<T>();
        node->data = inputData;
        root = node;
    } else {
        add(inputData, root);
    }
}

template<typename T>
inline int BinaryTree<T>::search(T inputData) {
    if (root == nullptr) {
        return 0;
    }
    else {
        search(inputData, root);
    }
}

template<typename T>
inline void BinaryTree<T>::printPreOrder() {
    if (root != nullptr) {
        printPreOrder(root);
    }
}

template<typename T>
inline void BinaryTree<T>::printBreadthFirst() {
    if (root != nullptr) {
        printPreOrder(root);
    }
}

template<typename T>
inline void BinaryTree<T>::add(T inputData, TreeNode<T> *childNode) {
    if (inputData.getNonce() < childNode->data.getNonce()) {
        if (childNode->left == nullptr) {
            TreeNode<T>* node = new TreeNode<T>();
            node->data = inputData;
            childNode->left = node;
        } else {
            add(inputData, childNode->left);
        }
    }
    else {
        if (childNode->right == nullptr) {
            TreeNode<T>* node = new TreeNode<T>();
            node->data = inputData;
            childNode->right = node;
        } else {
            add(inputData, childNode->right);
        }
    }
}

template<typename T>
inline int BinaryTree<T>::search(T inputData, TreeNode<T>* childNode) {
    int returnVal = -1;
    if (inputData == childNode->data) {
        return 1;
    } else if (inputData < childNode->data) {
        if (childNode->left != nullptr) {
            returnVal = search(inputData, childNode->left);
        }
    } else {
        if (childNode->right != nullptr) {
            returnVal = search(inputData, childNode->right);
        }
    }
    
    if (returnVal == -1) return returnVal;
    else return returnVal + 1;
}

template<typename T>
inline void BinaryTree<T>::printPreOrder(TreeNode<T>* childNode) {
    if(childNode == nullptr) return;
    std::cout
    << childNode->data.getId()
    << ":"
    << childNode->data.getNonce()
    << ":"
    << childNode->data.getHash()
    << std::endl;
    
    printPreOrder(childNode->left);
    printPreOrder(childNode->right);
    
}

template<typename T>
inline void BinaryTree<T>::printBreadthFirst(TreeNode<T> *childNode) {
    int h = height(childNode);
    for (int i = 1; i <= h; i++)
        printGivenLevel(childNode, i);
}

template<typename T>
void printLvl(TreeNode<T> *childNode, int level) {
    if (childNode == NULL) return;
    if (level == 1) {
        std::cout
        << childNode->data.getId()
        << ":"
        << childNode->data.getNonce()
        << ":"
        << childNode->data.getHash()
        << std::endl;
    }
    else if (level > 1) {
        printLvl(childNode->left, level - 1);
        printLvl(childNode->right, level - 1);
    }
}

template<typename T>
int height(TreeNode<T> node) {
    if (node == NULL) return 0;
    else {
        int lheight = height(node->left);
        int rheight = height(node->right);
        
        if (lheight > rheight) return(lheight + 1);
        else return(rheight + 1);
    }
}


 /* BinaryTree_h */