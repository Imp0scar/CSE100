#include <iostream>
using namespace std;

int Partition(int arr[], int left, int right){
int pivot = arr[right];
int i = left - 1;

for (int j = left; j < right; j++){
	if (arr[j] <= pivot){
		i++;
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}

}
int temps = arr[i +1];
arr[i+1] = arr[right];
arr[right] = temps;

return i + 1;

}

int Randomized_Partition(int arr[], int left, int right){
	int n = (right - left)+1;
	int pivotIndex = rand() % n;

	int temp = arr[right];

	arr[right] = arr[left + pivotIndex];

	arr[left + pivotIndex] = temp;

	return Partition(arr, left, right);
}


void Randomized_QuickSort(int arr[], int left, int right){
	if (left < right){
		int pivot = Randomized_Partition(arr, left, right);
		Randomized_QuickSort(arr, left, pivot-1);
		Randomized_QuickSort(arr, pivot+1, right);
	}


}

int main(){

// int arr[MAX_SIZE];

int n;
cin >> n;
int arr[n];
int i ;
cin >> i;
for (int j = 0; j < n; j++){
	cin >> arr[j];
}
srand(time(NULL));
Randomized_QuickSort(arr, 0, n-1);

for (int p = 0; p < n; p++){
	cout << arr[p] << ";"; 
}


return 0;
}