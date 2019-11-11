//
//  TreeNode.h
//
//  Created by Andrew Nguyen on 11/10/19.
//  Copyright © 2019 Andrew Nguyen. All rights reserved.
//

#pragma once

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode<T>();
};
template<typename T>
inline TreeNode<T>::TreeNode()
{
    this->left = nullptr;
    this->right = nullptr;
}

 /* TreeNode_h */
