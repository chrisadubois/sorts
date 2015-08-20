#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
using namespace std;
//Christopher DuBois CSS 342 Professor Dimpsey Winter Quarter 15 UWB

void MergeSort(vector<int> &toSort, int first, int last);
void merge(vector<int>& ar, int first, int mid, int last);

void IterativeMergeSort(vector<int> &toSort, int first, int last);
void merger(vector<int> &toSort, vector<int> &temp, int first, int mid, int last);

void QuickSort(vector<int> &toSort, int start, int end);
void sortFirstMiddleLast(vector<int>& a, int first, int mid, int last);

void BubbleSort(vector<int> &toSort, int low, int high);

void InsertSort(vector<int> &toSort, int low, int high);


void MergeSort(vector<int> &toSort, int first, int last)
{
	if (first < last)
	{
		int middle = (first + last) / 2;
		MergeSort(toSort, first, middle);
		MergeSort(toSort, middle + 1, last);
		merge(toSort, first, middle, last);
	}
}

void merge(vector<int> &toSort, int first, int mid, int last)
{
	int size = last - first + 1;
	int first1 = first;
	int first2 = mid + 1;
	int last1 = mid;
	int last2 = last;
	vector<int> temp = vector<int>(size);
	int current = 0;

	while ((first1 <= last1) && (first2 <= last2))
	{
		if (toSort[first1] < toSort[first2])
		{
			temp[current] = toSort[first1];
			first1++;
		}
		else
		{
			temp[current] = toSort[first2];
			first2++;
		}
		current++;
	}
	while (first1 <= last1)
	{
		temp[current] = toSort[first1];
		first1++;
		current++;
	}
	while (first2 <= last2)
	{
		temp[current] = toSort[first2];
		first2++;
		current++;
	}

	for (current = 0; current < size; current++)
	{
		toSort[first] = temp[current];
		first++;
	}
}

void IterativeMergeSort(vector<int> &toSort, int first, int last)
{
	int size = ++last;
	vector<int> temp(size);
	bool copy = false;//copy is used to alternate the sort to copy back and forth
	for (int width = 1; width < size; width = 2 * width)
	{
		for (int i = 0; i < size; i = i + (2 * width))
		{
			int left = i;
			int mid = min(i + width, size);
			int right = min(i + 2 * width, size);
			if (!copy)
			{
				merger(toSort, temp, left, mid, right);
			}
			else
			{
				merger(temp, toSort, left, mid, right);
			}
		}
		if (!copy)
		{
			copy = true;
		}
		else
		{
			copy = false;
		}
	}
	if (copy)
	{
		merger(temp, toSort, first, last / 2, size);
	}
}

void merger(vector<int> &toSort, vector<int>& temp, int first, int mid, int last)
{
	int left = first;
	int right = mid;
	int add = first;
	while (left < mid || right < last)//if either subarray have things in them
	{
		if (left < mid && right < last)//if both subarrays have things in them
		{
			if (toSort[left] < toSort[right])
			{
				temp[add++] = toSort[left++];
			}
			else
			{
				temp[add++] = toSort[right++];
			}
		}
		else if (left == mid)//if the first half of the subarray is empty (the left one)
		{
			temp[add++] = toSort[right++];
		}
		else if (right == last)//if the second half of the subarray is empty (the right one)
		{
			temp[add++] = toSort[left++];
		}
	}
}

void QuickSort(vector<int>& a, int first, int last)
{

	if ((last - first) < 5)
	{
		InsertSort(a, first, last);
		return;
	}
	int mid = (first + last) / 2;
	sortFirstMiddleLast(a, first, mid, last);
	int pivotVal = a[mid];
	swap(a[mid], a[last - 1]);
	int left = first + 1;
	int right = last - 2;
	bool done = false;
	while (!done)
	{
		while (a[left] < pivotVal)
		{
			left++;
		}
		while (a[right] > pivotVal)
		{
			right--;
		}
		if (right > left)//left < right)
		{
			swap(a[left], a[right]);
			left++;
			right--;
		}
		else
		{
			done = true;
		}
	}
	//now to take our pivot in the right place in the middle
	swap(a[left], a[last - 1]);
	QuickSort(a, first, left - 1);
	QuickSort(a, left + 1, last);
}

void sortFirstMiddleLast(vector<int>& a, int first, int mid, int last)
{
	if (a[first] > a[last])
	{
		swap(a[first], a[last]);
	}
	if (a[first] > a[mid])
	{
		swap(a[first], a[mid]);
	}
	if (a[mid] > a[last])
	{
		swap(a[mid], a[last]);
	}
	//now mid is the pivot but these will be swapped
}


void BubbleSort(vector<int> &toSort, int low, int high)
{
	for (int i = 0; i < high + 1; i++)
	{
		for (int j = 0; j < high; j++)
		{
			if (toSort[j] > toSort[j + 1])
			{
				swap(toSort[j], toSort[j + 1]);
			}
		}
	}
}

void InsertSort(vector<int> &toSort, int low, int high)
{
	int i, j;
	for (i = low + 1; i < high + 1; i++)//high + 1 just because of the command args
	{
		int temp = toSort.at(i);
		for (j = i - 1; j >= low && toSort[j] > temp; j--)
		{
			toSort[j + 1] = toSort[j];
		}
		toSort[j + 1] = temp;
	}
}