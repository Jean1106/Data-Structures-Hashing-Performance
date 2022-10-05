#include <iostream>
#ifndef hashmodlinkedlist_H
#define hashmodlinkedlist_H

using namespace std;


class HashCuckoo{

  private:
      int *table;
      int *table2;
      int tableSize;
      int numCollision;
      int limit;

      bool placeInArr(int tableId, int key, int count);
  public:
      HashCuckoo(int size);
      int hashValue(int function, int key);
      void cuckooInsert(int key);
      void cuckooDelete(int key);
      bool cuckooSearch(int key);
      void cuckooPrint();


};

#endif
