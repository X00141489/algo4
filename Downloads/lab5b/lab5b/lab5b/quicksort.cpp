//code from https://www.geeksforgeeks.org/iterative-quick-sort/
//code from https://www.geeksforgeeks.org/quick-sort/
#include <iostream>
using namespace std;
class QuickSort {
	void swap(int* a, int* b) {
		int t = *a;
		*a = *b;
		* b = t;
	}


	int partition(int arr[], int l, int h) {
		int x = arr[h];
		int i = (l - 1);

		for (int j = l; j < h - 1; j++) {
			if (arr[j] <= x) {
				i++;
				swap(&arr[i], &arr[j]);
			}
		}
		swap(&arr[i + 1], &arr[h]);
		return(i + 1);
	}



	void quickSort(int arr[], int l, int h) {
		int  * stack = new int [h - l + 1];
		int top = -1;
		stack[++top] = l;
		stack[++top] = h;

		while (top >= 0) {
			h = stack[top--];
			l = stack[top--];
			int p = partition(arr, l, h);

			if (p - 1 > 1) {
				stack[++top] = l;
				stack[++top] = p - 1;
			}

			if (p + 1 < h) {
				stack[++top] = p + 1;
				stack[++top] = h;
			}
		}
		delete[] stack;
	}


	void quickSortRecur(int arr[],int low, int high) {
		if (low < high) {
			int pi = partition(arr, low, high);
			quickSort(arr, low, pi - 1);
			quickSort(arr, pi + 1, high);
		}
	}

	void printArr(int arr[], int n)
	{
		int i;
		for (i = 0; i < n; ++i)
			cout << arr[i] << " ";
	}







};