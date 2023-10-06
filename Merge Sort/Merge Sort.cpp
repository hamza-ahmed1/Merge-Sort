// Merge Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
void merge(int arr[], int start, int mid, int end)
{
	//creating an array 
	int left = mid - start + 1;
	int right = end - mid;

	
	int* leftarr = new int[left];
	int* rightarr = new int[right];


	//copy element in temprory arrays:
	for (int i = 0; i < left; i++)
	{
		leftarr[i] = arr[start + i];
	}
	for (int i = 0; i < right; i++)
	{
		rightarr[i] = arr[mid+1+ i];
	}

	int i = 0;
	int j = 0;//for right and left array:
	int k = start;
	while (i<left && j<right)

	{
		if (leftarr[i] <= rightarr[j]) {
			arr[k] = leftarr[i];
			i++;
		}
		else
		{
			arr[k] = rightarr[j];
			j++;
		}
			k++;
	}

	//filling remaining element of both array:
	while (i<left)
	{
		arr[k] = leftarr[i];
		i++;
		k++;
	}

	while (j<right)
	{
		arr[k] = rightarr[j];
		j++;
		k++;
	}

	//clean up memory
	// Clean up memory
	delete[] leftarr;
	delete[] rightarr;

}

void mergesort(int arr[], int start, int end) {

	//if start==end or > end then return

	if (start < end) {

		int mid = start + (end - start) / 2;
		mergesort(arr, start, mid);
		mergesort(arr, mid + 1, end);
		merge(arr, start, mid, end);

	}
		

}

int main()
{
	int array[5] = { 5,3,1,7,2 };
	mergesort(array, 0, 4);
	for (int i = 0; i < 5; i++)
	{
		cout << array[i] << "   ";
	}
}


