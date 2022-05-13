#ifndef Block_h
#define Block_h
#include "TransactionData.h"

// Block Class
class Block
{
private:
    int index;
    size_t blockHash;
    size_t previousHash;
    size_t generateHash();

public:
    // Constuctor
    Block(int idx, TransactionData d, size_t prevHash);

    // Index
    int getIndex();

    // Orijinal Hash
    size_t getHash();

    // Previous Hash
    size_t getPreviousHash();

    // Transaction Data
    TransactionData data;

    // Validate Hash
    bool isHashValid();
};

#endif