#include <iostream>
#define max_int 2147483647

using namespace std;

void Matrix_Chain_Order(int arr[], int n, int m[][100], int s[][100]) {
    for (int i = 1; i <= n; i++) {
        m[i][i] = 0;
    }
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n-l+1; i++) {
            int j = i+l-1;
            m[i][j] = max_int;
            for (int k = i; k <= j-1; k++) {
                int q = m[i][k] + m[k+1][j] + arr[i-1]*arr[k]*arr[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void print_optimal_parens(int s[][100], int i, int j) {
    if (i == j) {
        cout << "A" << i-1;
    }
    else {
        cout << "(";
        print_optimal_parens(s, i, s[i][j]);
        print_optimal_parens(s, s[i][j]+1, j);
        cout << ")";
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n+1];
    for (int i = 0; i <= n; i++) {
        cin >> arr[i];
    }
    int m[100][100] = {0};
    int s[100][100] = {0};
    Matrix_Chain_Order(arr, n, m, s);
    cout << m[1][n] << endl;
    print_optimal_parens(s, 1, n);
    cout << endl;
    return 0;
}
