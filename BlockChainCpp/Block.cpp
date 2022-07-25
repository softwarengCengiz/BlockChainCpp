#include <stdio.h>
#include <string>
#include "Block.h"
#include "TransactionData.h"

// Constructor with params
Block::Block(int idx, TransactionData d, size_t prevHash)
{ 
    index = idx;
    data = d;
    previousHash = prevHash;
    blockHash = generateHash();
}

// private fonksiyonlar
int Block::getIndex()
{
    return index;
}

//Mevcut blok i�in hash �retir
//Nesildeki �ncekiHash'i i�erir
size_t Block::generateHash()
{
    // creating string of transaction data
    std::string toHashS = std::to_string(data.amount) + data.receiverKey + data.senderKey + std::to_string(data.timestamp);

    // Birle�tirmek i�in 2 hash
    std::hash<std::string> tDataHash; 
    std::hash<std::string> prevHash; // �nceki hash'i yeniden hash eder (kombinasyon i�in)

    return tDataHash(toHashS) ^ (prevHash(std::to_string(previousHash)) << 1);
}

// Public fonksiyonlar
size_t Block::getHash()
{
    return blockHash;
}

size_t Block::getPreviousHash()
{
    return previousHash;
}

bool Block::isHashValid()
{
    return generateHash() == getHash();
}