# include "hashmodlinkedlist.hpp"
# include <iostream>
# include <string>
# include <fstream>
# include <ctime>
# include <sstream>
# include <math.h>

using namespace std;

HashTable::HashTable(int size)
{
  tableSize = size;
  table = new LLNode*[tableSize];
  numCollision = 0;
  for(int i=0;i<tableSize;i++)
  {
    table[i] = NULL;
  }
}

int HashTable :: hashSumMod(int key)
{
//int index  = key % tableSize;
//return index;

int index  = floor(key / tableSize);
return index % tableSize;

}

bool HashTable :: search(int key)
{
    int index = hashSumMod(key);   // create variable "index" and make it equal to where it belongs in the array

    LLNode* temp = table[index]; // temp will traverse that array index of linked list

    while(temp) // while temp exists if the key is found return true, otherwise return false if not found
    {
        if(temp->key == key)
        {
          return true;
        }
        temp = temp->next;
    }
    return false;
}

void HashTable :: insert(int key)
{
  int index = hashSumMod(key);
  //LLNode* temp = table[index];

    if(!search(key))
    {
      if(table[index]!= NULL)
      {
        numCollision++;
      }
      LLNode * nn  = new LLNode;
      nn->key = key;
      nn-> next = table[index];
      table[index] = nn;
    }
}


void HashTable :: LLdelete(int key)
{
  int index = hashSumMod(key);
  if(search(key) == true)
  {
    if(table[index]->key == key)
    {
      LLNode* temp  = table[index];
      table[index] = table[index]->next;
      delete temp;
      return;
    }

    LLNode* curr = table[index];
    LLNode* prev = NULL;

    while(curr!= NULL)
    {
      if(curr->key == key)
      {
        prev->next = curr->next;
        delete curr;
        return;
      }
      prev = curr;
      curr = curr->next;
    }

  }

  else
    {
      cout << "cannot delete, not in table" << endl;
    }
}
  void HashTable::printHashTable()
  {
    LLNode * temp;
    for (int i = 0; i < tableSize; i++)
      {
        cout << i << "," ;
        temp = table[i];

        while (temp != NULL)
          {
            cout << temp -> key << " " ;
            temp = temp-> next;

          }
          cout << endl;
      }
  }

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
  		ht.insert(inArray[i]);
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

  								ht.insert(inArray[j]);

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

  							ht.insert(inArray[j]);

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

  								ht.LLdelete(inArray[j]);

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
