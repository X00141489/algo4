//code from https://www.geeksforgeeks.org/merge-sort/
#include <iostream>
using namespace std;
class MergeSort{
void merge(int arr[], int left, int middle, int right) {
	int i, j, k;
	int n1 = middle - left + 1;
	int n2 = right - middle;

	int L[n1], R[n2];

	for (i = 0; i < n1; i++) {
		L[i] = arr[left + i];
	}
	for (j = 0; j < n2;j++) {
		R[j] = arr[middle + 1 + j];
	}

	i = 0; 
	j = 0;
	k = left;


	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}


	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}


	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}


void mergeSort(int arr[], int left, int right) {
	if (left < right) {
		int middle = left + (right - 1) / 2;
		mergeSort(arr, left, middle);
		mergeSort(arr, middle + 1, right);
		merge(arr, left, middle, right);
	}
}


void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		std::cout << ("%d ", A[i]);
	std:: cout << ("\n");
}

/* Driver program to test above functions */
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	cout << ("Given array is \n");
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	cout << ("\nSorted array is \n");
	printArray(arr, arr_size);
	return 0;
}
};