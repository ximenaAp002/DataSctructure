// CPP program to implement hashing with chaining
#include <list>
#include <iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
using namespace std;

class Hash
{
	int BUCKET; // No. of buckets

	// Pointer to an array containing buckets
	list<int>* table;
public:
	Hash(int V); // Constructor

	// inserts a key into hash table
	void insertItem(int x);

	// deletes a key from hash table
	void deleteItem(int key);

	// hash function to map values to key
	int hashFunction(int n) {
		int rest;
		rest = n * n;
		string restl = to_string(rest); 

		if (restl.size() == 1 || restl.size() == 2) {
			return rest;
		}
		else if (restl.size() % 2 == 0) {
			string arr[10];
			int tmp = restl.size() / 2;
			for (int i = 0; i < restl.size(); i++) {
				if (i == 0) {
					arr[i] = restl.substr(i, i + 1);
				
				}
				else {
					arr[i] = restl.substr(i, i); 
				}
			}
			string tmp2 = arr[tmp] += arr[tmp - 1];

			return stoi(tmp2);
		}
		else {
			string arr1[10];
			int tmp = (restl.size() / 2) + 1;
			
			for (int i = 0; i < restl.size(); i++) {
				if (i == 0) {
					arr1[i] = restl.substr(i, i + 1);
					cout << arr1[i] << endl;
				}
				else {
					arr1[i] = restl.substr(i, i); 
				
				}
			}
			string tmp2 = arr1[tmp] += arr1[tmp - 1];

			return stoi(tmp2);
		}
		
	}

	void displayHash();
};

Hash::Hash(int b)
{
	this->BUCKET = b;
	table = new list<int>[BUCKET];
}

void Hash::insertItem(int key)
{
	int index = hashFunction(key);
	table[index].push_back(key);
}

void Hash::deleteItem(int key)
{
	// get the hash index of key
	int index = hashFunction(key);

	// find the key in (index)th list
	list <int> ::iterator i;
	for (i = table[index].begin();
		i != table[index].end(); i++) {
		if (*i == key)
			break;
	}

	// if key is found in hash table, remove it
	if (i != table[index].end())
		table[index].erase(i);
}

// function to display hash table
void Hash::displayHash() {
	for (int i = 0; i < BUCKET; i++) {
		cout << i;
		for (auto x : table[i])
			cout << " --> " << x;
		cout << endl;
	}
}

// Driver program
int main()
{
	// array that contains keys to be mapped
	int a[] = { 5, 4, 3, 8, 8, 6, 2, 5, 7,3, 5, 8 ,3, 6, 8 };
	int n = sizeof(a) / sizeof(a[0]);

	// insert the keys into the hash table
	Hash h(80); // 7 is count of buckets in
				// hash table
	for (int i = 0; i < n; i++)
		h.insertItem(a[i]);

	// delete 12 from hash table
	h.deleteItem(12);

	// display the Hash table
	h.displayHash();

	return 0;
}