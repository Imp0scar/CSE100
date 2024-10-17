#include <iostream>
#define max_int 2147483647

using namespace std;

int left, mid, right, n1, n2, arr;

void Merge(int arr[], int left, int mid, int right){
n1 = (mid - left) + 1;
n2  = right - mid;

int L[n1+1], R[n2+1];
for (int i = 1; i <= n1; i++){
	L[i] = arr[left + i - 1];
}
for (int j = 1; j <= n2; j++){
	R[j] = arr[mid+j];
}
L[n1 + 1] = max_int;
R[n2 + 1] = max_int;

int i = 1;
int j = 1;


for (int k = left; k <= right; k++){
	if(L[i] <= R[j]){
		arr[k] = L[i];
		i++;
		}
	else{
		arr[k] = R[j];
		j++;
		}
}



}

void Merge_sort(int arr[],int left, int right){
	if (left < right){

		int mid = ((left + right) / 2);
		Merge_sort(arr,left,mid);
		Merge_sort(arr,mid+1,right);
		Merge(arr,left,mid,right);
	}


}


int main(){

int n;

cin >> n;
int arr[n];

for (int i = 0; i < n; i++){
	cin >> arr[i];

}

Merge_sort(arr, 0, n-1);

for (int k = 0; k < n; k++){
	cout << arr[k] << ";";

}
	// cout << endl;

return 0;
}

