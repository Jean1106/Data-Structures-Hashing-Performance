# include "BSTRegMethod.hpp"
# include <iostream>
# include <math.h>
# include <string>
# include <fstream>
# include <ctime>

using namespace std;

HashTable::HashTable(int size) {
	TABLE_SIZE = size;
	hashTable = new BST*[TABLE_SIZE];
	num = 0;
	collision = 0;
	for(int i = 0; i < size; i++)
		hashTable[i] = nullptr;
}

//----------------------------------------------------------------------------

unsigned int HashTable::getHash(int x) {
  //return x % TABLE_SIZE;

int z  = floor(x / TABLE_SIZE);
return z % TABLE_SIZE;
}

//----------------------------------------------------------------------------

BST* search(BST* find, int key) {
  if(find == NULL) {
    return find;
  }
  if(find->val == key) {
    return find;
  }
  if(key < find->val) {
     return search(find->left, key);
  }

	return search(find->right, key);

}

 BST* HashTable::lookUpList(int num){
	 	BST* curr = search(hashTable[getHash(num)], num);
			if(curr == NULL) return NULL;
		return curr;
}

//----------------------------------------------------------------------------

bool HashTable::inTable(int num){
	BST* temp = lookUpList(num);
	if(temp == NULL) {
		return false;
	}

	return true;
}

//----------------------------------------------------------------------------

BST* addHelper(BST* curr, int key) {
	if(curr == nullptr) {
		BST* newNode = new BST;
		newNode->val = key;
		newNode->right = NULL;
		newNode->left = NULL;
		return newNode;
	}
	else if(curr->val < key) {
		curr->right = addHelper(curr->right, key);
	}
	else if(curr->val > key) {
		curr->left = addHelper(curr->left, key);
	}
	return curr;
}



void HashTable::addNum(int num) {
	if(!inTable(num)) {
		int index = getHash(num);
		hashTable[index] = addHelper(hashTable[index], num);
	}
	else {
		lookUpList(num)->repeat++;
	}
}

//----------------------------------------------------------------------------
BST* minValue(BST* temp) {
	if(temp->left == NULL) return temp;
	return minValue(temp->left);
}

BST* deleteHelper(BST *currNode, int key) {

BST* Temp;

  if(currNode == NULL)
  {
    return NULL;
  }
  else if(key < currNode->val)
  {
    currNode->left = deleteHelper(currNode->left, key);
  }
  else if(key > currNode->val)
  {
    currNode->right = deleteHelper(currNode->right, key);
  }
  // We found the node with the value
  else
  {
    //TODO Case : No child
    if(currNode->left == NULL && currNode->right == NULL) {
    delete currNode;
    currNode = NULL;
    }
    //TODO Case : Only right child
    else if(currNode->left == NULL) {
    Temp = currNode;
    currNode = currNode->right;
    delete Temp;
    }
    //TODO Case : Only left child
    else if(currNode->right == NULL) {
    Temp = currNode;
    currNode = currNode->left;
    delete Temp;

    }
    //TODO Case: Both left and right child
    else {
      BST* nn = minValue(currNode->right);
      currNode->val = nn->val;
      currNode->right = deleteHelper(currNode->right, nn->val);
    }
   }
    return currNode;
}

void HashTable::deleteNum(int num){
	int index = getHash(num);
	BST* temp = hashTable[index];
	if(inTable(num)) {
		hashTable[index] = deleteHelper(temp, num);
	}
	else {
		cout << "Number does not exist in table" << endl;
	}
}

//----------------------------------------------------------------------------
int main(int argc, char const *argv[])
{


ifstream datafile;
datafile.open(argv[1]);

string userInput;
string key;
bool shouldIQuit = false;
string numbers;
HashTable ht(10009);
int counter = 0;
int loadFactor = 10009 * 1 ;
int inArray[loadFactor];
int i = 0;



while (getline(datafile, numbers, ',') && i < loadFactor)
{
	// add load factor variable, if counter is greater than load factor then break
		inArray[i] = stoi(numbers);
		ht.addNum(inArray[i]);
		cout << inArray[i] << endl;
		i++;

//    for (int i = 0)

//  while ()
	//cout << numbers << endl;

	counter ++;

}
datafile.close();

cout << endl << "count: " << counter << endl;



while (shouldIQuit == false)
	{
		cout << "Would you like to insert(0), find(1), delete(2) a key, print(3) the table, or exit" << endl;

		getline(cin, userInput);
		switch (stoi(userInput))
		{
					case 0:
						{
						//	cout << "Enter the key you would like to find" << endl;
						int sTime[100];
						int totTime = 0;
						int count = 0;
						double standTop = 0;
						double averageTime = 0;
						double standDev = 0;

							clock_t start;
							start = clock();

							for (int j = 0 ; j < 100; j++)
							{
								clock_t start;
								start = clock();

								ht.addNum(inArray[j]);

								sTime[j] = (clock() - start / (double)(CLOCKS_PER_SEC ))/1000;
								totTime = totTime + sTime[j];

								cout << "time for this run for " << j << " was: "<< sTime[j] << endl;

								count ++;
							}

						//	int time_elapse = (clock() - start / (double)(CLOCKS_PER_SEC ))/1000;
						//	cout << time_elapse << endl;

							cout << endl << "count: " << count << endl;
							cout << "Total Time:  " << totTime << endl << endl;
							averageTime = totTime / 100;
							for(int k = 0; k < 100; k++) {
								standTop = standTop + pow((sTime[k] - averageTime), 2);
							}
							standDev = sqrt(standTop / (100-1));

							cout << "Average Time:  " << averageTime << endl;
							cout << "Standard Deviation:  + or -  " << standDev << endl << endl;


							break;
						}

					//	ht.insert(stoi(key));


					case 1:
					{
					//	cout << "Enter the key you would like to find" << endl;
					int sTime[100];
					int totTime = 0;
					int count = 0;
					double standTop = 0;
					double averageTime = 0;
					double standDev = 0;

						clock_t start;
						start = clock();

						for (int j = 0 ; j < 100; j++)
						{
							clock_t start;
							start = clock();

							ht.lookUpList(inArray[j]);

							sTime[j] = (clock() - start / (double)(CLOCKS_PER_SEC ))/1000;
							totTime = totTime + sTime[j];

							cout << "time for this run for " << j << " was: "<< sTime[j] << endl;

							count ++;
						}

					//	int time_elapse = (clock() - start / (double)(CLOCKS_PER_SEC ))/1000;
					//	cout << time_elapse << endl;

						cout << endl << "count: " << count << endl;
						cout << "Total Time:  " << totTime << endl << endl;
						averageTime = totTime / 100;
						for(int k = 0; k < 100; k++) {
							standTop = standTop + pow((sTime[k] - averageTime), 2);
						}
						standDev = sqrt(standTop / (100-1));

						cout << "Average Time:  " << averageTime << endl;
						cout << "Standard Deviation:  + or -  " << standDev << endl << endl;


						break;
					}

					case 2:
					{
						int sTime[100];
						int totTime = 0;
						int count = 0;
						double standTop = 0;
						double averageTime = 0;
						double standDev = 0;

							clock_t start;
							start = clock();

							for (int j = 0 ; j < 100; j++)
							{
								clock_t start;
								start = clock();

								ht.deleteNum(inArray[j]);

								sTime[j] = (clock() - start / (double)(CLOCKS_PER_SEC ))/1000;  //time in microseconds
								totTime = totTime + sTime[j];

								cout << "time for this run for " << j << " was: "<< sTime[j] << endl;

								count ++;
							}

						//	int time_elapse = (clock() - start / (double)(CLOCKS_PER_SEC ))/1000;
						//	cout << time_elapse << endl;

							cout << endl << "count: " << count << endl;
							cout << "Total Time:  " << totTime << endl << endl;
							averageTime = totTime / 100;
							for(int k = 0; k < 100; k++) {
								standTop = standTop + pow((sTime[k] - averageTime), 2);
							}
							standDev = sqrt(standTop / (100-1));

							cout << "Average Time:  " << averageTime << endl;
							cout << "Standard Deviation:  + or -  " << standDev << endl << endl;


							break;
					}

					case 3:
					{
						cout << "The hash table is printing..." << endl;
						//ht.printHashTable();
						break;
					}

					case 4:
					{
						cout << "Exiting.." << endl;
						shouldIQuit = true;
						break;
					}





		}



	}



	return 0;
} // main end
