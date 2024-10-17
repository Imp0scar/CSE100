#include <iostream>

using namespace std;

class record {
public:
    int key[11];

    record() {
        for (int i = 1; i <= 10; i++)
            key[i] = 0;
    }
};

// Global variables that can be accessed anywhere. Not recommended for serious programming.
record* A;
int* C;
record* B;
int k = 4;
int arraySize;

void countSort(int r) {
	// initializes C to have k number of indexes that are all 0.
    for (int i = 0; i < k; i++)
        C[i] = 0;

    // counts the number of occurences of digit r in the key of each record.
    for (int j = 1; j <= arraySize; j++)
        C[A[j].key[r]] = C[A[j].key[r]] + 1;

    // C[i] = C[i] plus the previous C[i] which is C[i-1]. so we sum up the previous C[i] until we get to k.
    for (int i = 1; i < k; i++)
        C[i] = C[i] + C[i - 1];

    // sorts the records based on the digit r
    for (int j = arraySize; j >= 1; j--) {
        B[C[A[j].key[r]]] = A[j];
        C[A[j].key[r]] = C[A[j].key[r]] - 1;
    }

    // copies sorted records back into A so we can output A later
    for (int j = 1; j <= arraySize; j++)
        A[j] = B[j];
}

void radixSort() {
	// for loop to sort based on each digit in the key from least significant to most significant
    for (int r = 10; r >= 1; r--)
        countSort(r);
}

int main() {
    // Read input
    cin >> arraySize;
    A = new record[arraySize + 1];
    B = new record[arraySize + 1];
    C = new int[k];

    for (int i = 1; i <= arraySize; i++)
        for (int j = 1; j <= 10; j++)
            cin >> A[i].key[j];

    // Sort
    radixSort();

    // Output
    for (int i = 1; i <= arraySize; i++) {
        for (int j = 1; j <= 10; j++)
            cout << A[i].key[j] << ";";
        cout << "\n";
    }
    // cout << "\n";

    // Clean up
    delete[] A;
    delete[] B;
    delete[] C;

    return 1;
}