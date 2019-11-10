//
//  main.cpp
//
//  Created by Andrew Nguyen on 11/10/19.
//  Copyright © 2019 Andrew Nguyen. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <cstdlib> // Generates random number
#include "BinaryTree.h"
#include "Block.h"

//    Block(long ID, std::string hash, std::string previousHash, long nonce, long timeId);
int main(int argc, const char * argv[]) {
    Block blocks[100];
    Block genenisBlock { 0, "0", "", 0, std::time(0)};
    genenisBlock.generateHash();
    blocks[0] = genenisBlock;
    
    for(int i {1}; i < sizeof(blocks); i++) {
        Block block = {i, "", blocks[i - 1].getHash(), rand(), 0};
        block.generateHash();
        blocks[i] = block;
    }
    
    for(int i {1}; i < sizeof(blocks); i++) {
        Block currBlock {blocks[i]};
        currBlock.setNonce(0);
        currBlock.mining(1);
    }
    
    
//    BinaryTree<int>* binaryTree = new BinaryTree<int>();
//    for (int ii = 1; ii < argc; ii++) {
//        binaryTree->add(atoi(argv[ii]));
//    }
//
//    int search1 = binaryTree->search(9);
//    std::cout << "The level for search1 is " << search1 << std::endl;
//    int search2 = binaryTree->search(12);
//    std::cout << "The level for search2 is " << search2 << std::endl;
}
