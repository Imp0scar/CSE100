#include <iostream>

#define MAX_INT 2147483647

using namespace std;

int main(int argc,char **argv) {
	int* Sequence;
	int arraySize = 1;

	cin >> arraySize;
	Sequence = new int[arraySize];

	for (int i=0; i <arraySize; i++){
	cin >> Sequence[i];
	}
	int max_num = Sequence[0];
	int min_num = Sequence[0];

	for (int i=1; i < arraySize; i++){
		if (Sequence[i] > max_num){
		max_num = Sequence[i];

		}
		if (Sequence[i] < min_num){
		min_num = Sequence[i];
		}
	}

	cout << max_num << ";" << min_num;

	delete[] Sequence;

	return 0;

}