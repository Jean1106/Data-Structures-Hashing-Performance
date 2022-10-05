#include "LinProbeFloor.hpp"
#include <iostream>
# include <fstream>
# include <ctime>
# include <math.h>

using namespace std;

HashTable::HashTable(int size) {
	TABLE_SIZE = size;
	table = new int[TABLE_SIZE];
	for (int i=0; i<TABLE_SIZE; i++)
		table[i] = -1;
}

int HashTable::getHash(int k) {
	int z = floor(k / TABLE_SIZE);
	return z % TABLE_SIZE;
}

int HashTable::linearProbe(int k) {
	for (int i=k+1; i!=k; i++) {
		if (i >= TABLE_SIZE) {
			i = -1;
			continue;
		}
		if (table[i] == -1) return i;
	}
	return -1;
}

bool HashTable::inTable(int k) {
	for (int i = 0; i < TABLE_SIZE; i++)
		if (table[i] == k) return true;

	return false;
}

void HashTable::addHash(int k) {
	if(!inTable(k)) {
		int index = getHash(k);
		if (table[index] >= 0)
			index = linearProbe(index);
		if (index >= 0)	table[index] = k;
		else cout << "Couldn't fit it :(\n";
	}
	else {
		cout << "Number already in Table" << endl;
	}
}

void HashTable::deleteHash(int k) {
	if(inTable(k)) {
		for(int i = 0; i < TABLE_SIZE; i++) {
			if (table[i] == k) table[i] = -1;
		}
	}
	else {
		cout << "Number not in Table" << endl;
	}
}


void HashTable::printTable() {
	for (int i = 0; i < TABLE_SIZE; i++)
		cout << table[i] << ", ";
	cout << endl;
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
int loadFactor = 10009 * .1 ;
int inArray[loadFactor];
int i = 0;



while (getline(datafile, numbers, ',') && i < loadFactor)
{
	// add load factor variable, if counter is greater than load factor then break
		inArray[i] = stoi(numbers);
		ht.addHash(inArray[i]);
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

								ht.addHash(inArray[j]);

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

							ht.inTable(inArray[j]);

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

								ht.deleteHash(inArray[j]);

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
