//code from https://www.tutorialspoint.com/cplusplus-program-to-find-kth-smallest-element-by-the-method-of-partitioning-the-array
#include <iostream>
using namespace std;
class parta {

	void swap(int* a, int* b) {
		int t;
		t = *a;
		*a = *b;
		*b = t;
	}


	int CreatePartition(int a[], int l, int h) {
		int pi, in, i;
		in = l;
		pi = h;
		for (i = l; i < h; i++) {
			if (a[i] < a[pi]) {
				swap(&a[i], &a[in]);
				in++;
			}
		}
		swap(&a[pi], &a[in]);
		return in;
	}


	int Partition(int a[], int low, int high, int k) {
		int p_in;
		if (low < high) {
			p_in = CreatePartition(a, low, high);
			if (p_in == k - 1) {
				return k - 1;
			}
			else if (p_in > k - 1) {
				Partition(a, low, p_in - 1, k);
			}
			else{
				Partition(a, p_in + 1, high, k);
			}
		}
	}

	int main() {
		int n, i, k, k_k;
		cout << "\nEnter the number array elements: ";
		cin >> n;
		int a[n];
		for (i = 0; i < n; i++) {
			cout << "Enter element " << i + 1 << ": ";
			cin >> a[i];
		}
		cout << "\nEnter the k for the kth smallest element: ";
		cin >> k;
		k_k = Partition(a, 0, n - 1, k);
		cout << "\nThe kth smallest element: " << a[k_k];
		return 0;
	}

};