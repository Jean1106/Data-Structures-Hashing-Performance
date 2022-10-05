#include <iostream>
#ifndef hashmodlinkedlist_H
#define hashmodlinkedlist_H

using namespace std;


struct LLNode{
  int key;
  LLNode* next;
};

class HashTable{

  private:
      LLNode* *table;
      int tableSize;
      int numCollision;
  public:
       HashTable(int key);
      int hashSumMod(int key);
      void insert(int key);
      void LLdelete(int key);
      bool search(int key);
      void printHashTable();


};

#endif
