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

cout << pivot << ";";

return i + 1;


}

int Randomized_Select(int arr[], int left, int right, int i){
if (left == right){
	return arr[left];
}

// else{
// 	int i = partition(arr, left, right)
// }

int mid = Partition(arr, left, right);
int k = mid - left + 1;

if (i == k){
	return arr[mid];
}
else if( i < k){
	return Randomized_Select(arr, left, mid-1, i);

}
else{
	return Randomized_Select(arr, mid + 1, right, i - k);
}


}

int main(){

int n;
cin >> n;
int arr[n];

int i;
cin >> i;

for (int j = 0; j < n; j++){
	cin >> arr[j];
}

Randomized_Select(arr, 0, n-1, i);

cout << arr[i-1] << ";";

//Figure out how to print the pivot every iteration randomized select is called.

// for (int p = 0; p < n; p++){
// 	cout << arr[p] << ";"; 
// }


return 0;
}