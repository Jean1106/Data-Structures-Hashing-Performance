# include "hashcuckoo.hpp"
# include <iostream>
# include <math.h>
# include <string>
# include <fstream>

using namespace std;

HashCuckoo::HashCuckoo(int size)
{
  tableSize = size;
  limit = 2*tableSize;
  table = new int[tableSize];
  table2 = new int[tableSize];
  numCollision = 0;
  for(int i=0;i<tableSize;i++)
  {
    table[i] = -1;
    table2[i] = -1;
  }
}

int HashCuckoo::hashValue(int function, int key)
{
  /*
    switch (function)
    {
        case 1: return key%tableSize;
        case 2: return (key/tableSize)%tableSize;
    }

    */

    if (function == 1)
      {
        return key%tableSize;
      }
    if (function == 2)
      {
        return (key/tableSize)%tableSize;
      }
    else
      {
        return 0;
      }

}

bool HashCuckoo::cuckooSearch(int key)
{
    int index1 = hashValue(1,key);
    int index2 = hashValue(2,key);

    if(table[index1] == key)
      {
          return true;
      }
    if (table2[index2] == key)
      {
          return true;
      }
    else
      {
          return false;
      }
}

bool HashCuckoo:: placeInArr(int tableId, int key, int count)
{
    if(count>=limit)
    {
       cout<< "the key " << key<< " ";
       return false;
    }
    int index = hashValue(tableId, key);
    int * tab;
    if(tableId ==1)
      tab = table;
    else
      tab = table2;

    if(tab[index] == -1)
    {
      tab[index] = key;
      return true;
    }


    //if(tab[index] != -1)
    //{
        int temp = tab[index];
        tab[index] = key;
        tableId = (tableId==1) ? 2:1;
        return placeInArr(tableId, temp, count+1);
    //}

}

void HashCuckoo::cuckooInsert(int key)
{

    if (cuckooSearch(key) == false) // if the key is not found anywhere in either tables
      {
          placeInArr(1, key, 0);
      }
    else
      {
        cout << "already in the table " << endl;
      }


}


void HashCuckoo::cuckooDelete(int key)
{
  int index1 = hashValue(1, key);
  int index2 = hashValue(2, key);


  if (cuckooSearch(key) == true)
  {
    if(table[index1]== key)
    {
      table[index1]=-1;
      cout<< key << " was successfully deleted" << endl;
      return;
    }

    if(table2[index2]== key)
    {
      table2[index2]=-1;
      cout<< key << "was successfully deleted" << endl;
      return;
    }

  }

  else
  {
    cout << "item: " << key << "was not in the table." << endl;
  }

}

void HashCuckoo::cuckooPrint()
{
    /*for (int i = 0; i < tableSize; i++)
      {
        cout << table[i] << endl;
      }
    for (int i = 0; i < tableSize; i++)
      {
        cout << table2[i] << endl;
      }*/

      for (int i = 0; i < tableSize; i++)
      {
          cout << i<<": "<< table[i] << ", "<<table2[i]<<endl;
      }
}

int main(int argc, char const *argv[])
{
  /* int a[] = {9, 2, 17, 12, 19, 57, 46, 78, 96};
  int x = 7;

  HashCuckoo hashh(x);
  for (int i = 0; i < x; i++)
    {
        hashh.cuckooInsert(a[i]);
    }
  cout << "here is the hash table" << endl;

  hashh.cuckooPrint();
  cout << endl;

  int searchingNumber = 19;
  if (hashh.cuckooSearch(searchingNumber == false))
      {
        cout << "the number " << searchingNumber << "has not been found." << endl;
      }
  hashh.cuckooDelete(searchingNumber);
  cout << "After the deletion the new list is: " << endl;
  hashh.cuckooPrint();
  */


  ifstream datafile;
  datafile.open(argv[1]);

  string userInput;
  string key;
  bool shouldIQuit = false;
  string numbers;
  HashCuckoo ht(10009);
  int counter = 0;
  int loadFactor = 10009 * 1;
  int inArray[loadFactor];
  int i = 0;



  while (getline(datafile, numbers, ',') && i < loadFactor)
  {
  	// add load factor variable, if counter is greater than load factor then break
  		inArray[i] = stoi(numbers);
  		ht.cuckooInsert(inArray[i]);
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

  								ht.cuckooInsert(inArray[j]);

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

  							ht.cuckooSearch(inArray[j]);

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

  								ht.cuckooDelete(inArray[j]);

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
