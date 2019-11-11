//
//  Block.cpp
//
//  Created by Andrew Nguyen on 11/10/19.
//  Copyright © 2019 Andrew Nguyen. All rights reserved.
//

#include <stdio.h>
#include "Block.h"
#include <iostream>
#include <string>
#include "sha256.h"

// Constructors
Block::Block() {
    ID = 0.0;
    hash = "";
    previousHash = "";
    nonce = 0.0;
    timeId = 0.0;
};

Block::Block(long id, std::string previousHash, long nonce, long timeId) {
    this->ID = id;
    this->previousHash = previousHash;
    this->nonce = nonce;
    this->timeId = timeId;
};

Block::Block(long id, std::string hash, std::string previousHash, long nonce, long timeId) {
    this->ID = id;
    this->hash = hash;
    this->previousHash = previousHash;
    this->nonce = nonce;
    this->timeId = timeId;
};

// Getters
long Block::getId() {
    return ID;
};

std::string Block::getHash() {
    return hash;
};

std::string Block::getPrevHash() {
    return previousHash;
};


long Block::getNonce() {
    return nonce;
};


long Block::getTimeId() {
    return timeId;
};


// Setters
void Block::setId(long ID){
    this->ID = ID;
};

void Block::setHash(std::string hash){
    this->hash = hash;
};


void Block::setPrevHash(std::string prevHash) {
    this->previousHash = prevHash;
};


void Block::setNonce(long nonce) {
    this->nonce = nonce;
};


void Block::setTimeId(long timeId) {
    this->timeId = timeId;
};


// Methods
std::string Block::generateHash() {
    std::string strId = std::to_string(this->ID);
    std::string strNonce = std::to_string(this->nonce);
    std::string strTimeId = std::to_string(this->timeId);
    std::string combine = strId + strNonce + strTimeId;
//    std::size_t str_hash = std::hash<std::string>{}(combine);
    return sha256(combine);
};

void Block::mining(int difficulty) {
    std::string diff {""};
    for(int i {0}; i < difficulty; i++) {
        diff += "0";
    }
    
    while(true) {
        std::string newHash {generateHash()};
        if(newHash.substr(0, difficulty) == diff) {
            hash = newHash;
            break;
        }
        this->nonce += 1;
    }
}
