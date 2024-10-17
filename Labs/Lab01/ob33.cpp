#include <iostream>

using namespace std;

int key, j;

void Insertion_Sort (int arr[], int n){
	for (int i = 1; i < n; i++){
		key = arr[i];
		j = i - 1;

		while(j >= 0 && arr[j] > key){
			arr[j + 1] = arr[j];
			j = j - 1;
			
		}
		arr[ j + 1] = key;
		for (int k = 0; k <= i; k++){
			cout << arr[k] << ";"; 
		}
		cout << endl;
	}
	

	}
int main(){

// int amount;
// cin>> amount

int arr[] = {5, 3, 2, 1, 6, 4};

int n = sizeof(arr) / sizeof(arr[0]);
 
    Insertion_Sort(arr, n);
 	
    return 0;
}