#ifndef BSTREGMETHOD_HPP
#define BSTREGMETHOD_HPP

#include <iostream>
using namespace std;

struct BST {
	int val;
	int repeat;

	BST* right;
	BST* left;
};

class HashTable {
	private:
		BST** hashTable;
		int TABLE_SIZE;
		int num;
		int collision;
		unsigned int getHash(int x);
	public:
		BST* lookUpList(int num);
		HashTable(int size);
		void addNum(int num);
		void deleteNum(int num);
		bool inTable(int num);
		/*
		int getSize() {return TABLE_SIZE;};
		int getNum() {return num;};
		int getCollision() {return collision;};
		*/

};

#endif
