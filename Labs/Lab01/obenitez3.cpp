#include <iostream>

using namespace std;


int main(int argc,char **argv){

int key, i, j, n;

// cout << "Enter the amount of elements you want to sort: ";
cin >> n;

// cout << "Enter the elements you want to sort: ";
int amount[n];

for (int i =0; i < n; i++){
	cin >> amount[i];
}

for (int i = 1; i < n; i++){
		key = amount[i];
		j = i - 1;

		while(j >= 0 && amount[j] > key){
			amount[j + 1] = amount[j];
			j = j - 1;
			
		}
		amount[ j + 1] = key;
		for (int k = 0; k <= i; k++){
			cout << amount[k] << ";"; 
		}
		cout << endl;
	}


	return 0;

}