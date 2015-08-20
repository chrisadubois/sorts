#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
// windows.h is specific for windows. For Linux please use
// #include <stdlib.h>
// #include <sys/time.h>
#include <windows.h>
#include "SortImpls.h"
using namespace std;
void PrinArray(const vector<int> &array, string name);
void InitArray(vector<int> &array, int randMax);
bool isValid(string sortName);
bool isValid(int sortSize);

int main(int argc, char* argv[])
{
	int console;
	if (argc <= 1)
	{
		cout << "Try again, use the command prompt AND pass in arguments." << endl;
		Sleep(1000);
		return -1;
	}
	if (argc != 3)
	{
		cout << "Usage: Sorter SortType ArraySize";
		return -1;
	}
	string sort_name = string(argv[1]);
	int size = atoi(argv[2]);
	//
	bool goodSortName = isValid(sort_name);
	bool goodSize = isValid(size);
	bool done = goodSortName && goodSize;
	int newSize = size;
	string newSortName = sort_name;
	if (!done) 
		{
			cout << endl;
			cout << "You typed..." << newSortName << " " << newSize << endl;
			cout << endl;
			cout << "Run Sorter again with the proper arguments. (Sorter SortType SortSize)" << endl;
			cout << "SortTypes are: BubbleSort, InsertSort, MergeSort, IterativeMergeSort, Quicksort" << endl;
			cout << "Valid SortSizes have to be greater than 0" << endl;
			Sleep(1000);
			return -1;
		}
		if (done)
		{
			cout << "You typed..." << newSize << " " << newSortName << endl;
		}
	if (size <= 0) {
		cerr << "array size must be positive" << endl;
		return -1;
	}
	srand(1);
	vector<int> items(newSize);
	InitArray(items, newSize);
	cout << "Sort employed: " << newSortName << endl;
	cout << "initial:" << endl;
	PrinArray(items, string("items"));
	// GetTickCount is windows specific.
	// For linux use gettimeofday. As shown::
	// struct timeval startTime, endTime;
	// gettimeofday(&startTime, 0);
	// Place logic to determine and call function of interest here.
	// Do not call all of them
	int begin;
	string s1, s2, s3, s4, s5;
	s1 = "IterativeMergeSort";
	s2 = "MergeSort";
	s3 = "QuickSort";
	s4 = "InsertSort";
	s5 = "BubbleSort";
	if (newSortName == s1)
	{
		begin = GetTickCount();
		IterativeMergeSort(items, 0, newSize - 1);
	}
	if (newSortName == s2)
	{
		begin = GetTickCount();
		MergeSort(items, 0, newSize - 1);
	}
	if (newSortName == s3)
	{
		begin = GetTickCount();
		QuickSort(items, 0, newSize - 1);
	}
	if (newSortName == s4)
	{
		begin = GetTickCount();
		InsertSort(items, 0, newSize - 1);
	}
	if (newSortName == s5)
	{
		begin = GetTickCount();
		BubbleSort(items, 0, newSize - 1);
	}
	int end = GetTickCount();
	// Linux timer:
	// gettimeofday(&endTime, 0);
	cout << "sorted:" << endl;
	PrinArray(items, string("item"));
	int elapsed_secs = end - begin;
	// Linux elapsed time
	// int elapsed_secs = elapsed( startTime, endTime)
	cout << "Time (ms): " << elapsed_secs << endl;
	cout << "Sort complete. Goodbye!\n";
	cin >> console;
	return 0;
}
// array initialization with random numbers
void InitArray(vector<int> &array, int randMax)
{
	int size = array.size();
	for (int i = 0; i < size;)
	{
		int tmp = (randMax == -1) ? rand() : rand() % randMax;
		bool hit = false;
		for (int j = 0; j < i; j++)
		{
			if (array[j] == tmp)
			{
				hit = true;
				break;
			}
		}
		if (hit)
		{
			continue;
		}
		array[i] = tmp;
		i++;
	}
}
// Function to Print Array
void PrinArray(const vector<int> &array, string name)
{
	int size = array.size();
	for (int i = 0; i < size; i++)
		cout << name << "[" << i << "] = " << array[i] << endl;
}
// Function to calculate elapsed time is using gettimeofday
// int elapsed( timeval &startTime, timeval &endTime )
// {
// return ( endTime.tv_sec - startTime.tv_sec ) * 1000000
// + ( endTime.tv_usec - startTime.tv_usec );
// }


bool isValid(int sortSize)
{
	if (sortSize >= 0)
	{
		return true;
	}
	else
	{
		/*cout << endl;
		cout << "Your Sort Name was wrong, you typed... " << sortSize << endl;
		cout << "Please try again, one or more of the arguments were invalid.\n";
		cout << "The options are...\n";
		cout << "BubbleSort, InsertSort , MergeSort,\nIterativeMergeSort, or QuickSort.\n\n";
		cout << "Enter the type of sort exactly as listed then press space and enter\nhow large of an array you would like sorted.\n";
		cout << "Remember, arrays can only be sorted in size above 0.\n";*/
		return false;
	}
}

bool isValid(string sortName)
{
	string s1, s2, s3, s4, s5;
	s1 = "IterativeMergeSort";
	s2 = "MergeSort";
	s3 = "QuickSort";
	s4 = "InsertSort";
	s5 = "BubbleSort";
	string arg = sortName;
	if (arg == s1)
	{
		return true;
	}
	if (arg == s2)
	{
		return true;
	}
	if (arg == s3)
	{
		return true;
	}
	if (arg == s4)
	{
		return true;
	}
	if (arg == s5)
	{
		return true;
	}
	else
	{
		/*cout << endl;
		cout << "Your Sort Name was wrong, you typed... " << sortName << endl;
		cout << "Please try again, one or more of the arguments were invalid.\n";
		cout << "The options are...\n";
		cout << "BubbleSort, InsertSort , MergeSort,\nIterativeMergeSort, or QuickSort.\n\n";
		cout << "Enter the type of sort exactly as listed then press space and enter\nhow large of an array you would like sorted.\n";
		cout << "Remember, arrays can only be sorted in size above 0.\n";*/
		return false;
	}
}

