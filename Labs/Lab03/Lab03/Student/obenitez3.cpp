#include <iostream>
#define INT_MIN -2147483647 - 1

using namespace std;

int maxCrossingSubarray(int arr[], int low, int mid, int high){
	// int max_left, max_right, right_sum, left_sum;

	int left_sum = INT_MIN;
	int sum = 0;

	for (int i = mid; i >= low; i --){
		sum += arr[i];
		if (sum > left_sum ){
			left_sum = sum;
			// int max_left = i;
		}
	
	}
	sum = 0;
	int right_sum = INT_MIN;
	for (int i = mid + 1; i <= high; i++){
		sum += arr[i];
		if (sum > right_sum){
			right_sum = sum;
			// int max_right = j;
		}
	}
	return (left_sum + right_sum);

}


int maxSubArray(int arr[], int low, int high){
	if (low == high){
		return (arr[low]);
			}

	int mid = (low + high) / 2;

    int left_max = maxSubArray(arr, low, mid);
    int right_max = maxSubArray(arr, mid + 1, high);
    int crossing_max = maxCrossingSubarray(arr, low, mid, high);

    return max(max(left_max, right_max), crossing_max);
}




int main(){

int n;

cin >> n;
int arr[n];

for (int i = 0; i < n; i++){
	cin >> arr[i];

}

int max_sum = maxSubArray(arr, 0, n-1);

cout << max_sum;

return 0;
}