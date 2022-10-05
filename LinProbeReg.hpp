#ifndef LINPROBEREG_HPP
#define LINPROBEREG_HPP

#include <iostream>
#include <vector>

using namespace std;

class HashTable {
private:
	int TABLE_SIZE;;
	int* table;
	int getHash(int k);
public:
	HashTable(int size);
	void addHash(int k);
	bool inTable(int k);
	void deleteHash(int k);
	void printTable();
	int linearProbe(int k);
};

#endif
