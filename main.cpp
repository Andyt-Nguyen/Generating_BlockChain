//
//  main.cpp
//
//  Created by Andrew Nguyen on 11/10/19.
//  Copyright © 2019 Andrew Nguyen. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "BinaryTree.h"
#include "Block.h"

int main(int argc, const char * argv[]) {
    const int BLOCK_LENGTH = 5;
    Block blocks[BLOCK_LENGTH];
    Block genenisBlock { 0, "0", "", 0, std::time(0)};
    genenisBlock.setHash(genenisBlock.generateHash());
    blocks[0] = genenisBlock;
    
    // Part 1: Block-Chain
    for(int i {1}; i < BLOCK_LENGTH; i++) {
        Block block = {i, "", blocks[i - 1].getHash(), rand(), 0};
        block.setHash(block.generateHash());
        blocks[i] = block;
    }
    
    // Part 2: Mining Block Chain
    for(int i {1}; i < BLOCK_LENGTH; i++) {
        Block* currBlock {&blocks[i]};
        currBlock->setNonce(0);
        currBlock->mining(1);
        currBlock->setPrevHash(blocks[i-1].getHash());
    }
    
    // Part 3: Put blocks into BinaryTree
    BinaryTree<Block>* binaryTree = new BinaryTree<Block>();
    for (int i = 1; i < BLOCK_LENGTH; i++) {
        binaryTree->add(blocks[i]);
    }
    
    // Part 4: Depth-First: PreOrder (L->R)
    binaryTree->printPreOrder();
    
    // Part 4: Breadth First (L->R)
    binaryTree->printBreadthFirst();
}

