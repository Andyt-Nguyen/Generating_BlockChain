//
//  Block.h
//
//  Created by Andrew Nguyen on 11/10/19.
//  Copyright © 2019 Andrew Nguyen. All rights reserved.
//
#ifndef Block_h
#define Block_h
#include <iostream>
#include <string>

class Block {
private:
    long ID;
    std::string hash;
    std::string previousHash;
    long nonce;
    long timeId;
    
public:
    // Constructor
    Block();
    Block(long ID, std::string previousHash, long nonce, long timeId);
    Block(long ID, std::string hash, std::string previousHash, long nonce, long timeId);
    
    // Getters
    long getId();
    std::string getHash();
    std::string getPrevHash();
    long getNonce();
    long getTimeId();
    
    // Setters
    void setId(long);
    void setHash(std::string);
    void setPrevHash(std::string);
    void setNonce(long);
    void setTimeId(long);
    
    // Methods
    std::string generateHash();
    void mining(int difficulty);
    
};

#endif /* Block_h */
