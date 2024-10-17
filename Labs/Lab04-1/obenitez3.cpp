#include <iostream>
using namespace std;


void Max_Heapify(int arr[], int n, int i){
int largest = i;
int l = (2 * i) + 1; 
int r = (2 * i) + 2; 

	// int l = left(i);
	// int r = right(i);
	
	if ( l < n && arr[l] > arr[largest]){
		largest = l;
	}
	// else{
		// largest = r;
	// }
	if (r < n && arr[r] > arr[largest]){
		largest = r;
	}
	if (largest != i){
		int temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		Max_Heapify(arr, n, largest);
	}

}


void Build_Max_Heap(int arr[], int n){
	// int n = arr.size();
	for (int i = n / 2 - 1; i >= 0; i--){
		Max_Heapify(arr, n, i);
	}

	// for (int i = n-1; i >= 0; i--){
	// 	int temps = arr[0];
	// 	arr[0] = arr[i];
	// 	arr[i] = temps;
	// 	Max_Heapify(arr, i, 0);
	// }
}

void Heap_Sort(int arr[], int n){
	Build_Max_Heap(arr, n);
	for (int i = n-1; i >= 0; i--){
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		Max_Heapify(arr, i, 0);
	}
}


int main(){

int n;
cin >> n;
int arr[n];

for (int i = 0; i < n; i++){
	cin >> arr[i];
}

Heap_Sort(arr, n);

for (int i = 0; i < n; i++){
	cout << arr[i] << ";"; 
}

return 0;
}