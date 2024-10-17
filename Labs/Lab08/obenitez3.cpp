#include <iostream>
#define INT_MIN -2147483647 - 1

using namespace std;

int BottomUpCutRod(int price[], int n){
    int r[n+1];
    int s[n+1];
    r[0] = 0;

    for (int j = 1; j <= n; j++){
        int q = INT_MIN;
        for (int i = 1; i <= j; i++){
            if (q < price[i] + r[j-i]){
                q = price[i] + r[j-i];
                s[j] = i;
            }
        }
        r[j] = q;
    }
    return r[n];
}

void printCutRodSolution(int price[], int n){
    int r[n+1], s[n+1];
    r[0] = 0;
    for (int j = 1; j <= n; j++){
        int q = INT_MIN;
        for (int i = 1; i <= j; i++){
            if (q < price[i] + r[j-i]){
                q = price[i] + r[j-i];
                s[j] = i;
            }
        }
        r[j] = q;
    }

    while (n > 0){
        cout << s[n] << " ";
        n = n - s[n];
    }
    cout << "-1" << endl;
}

int main() {
    int n;
    cin >> n;

    int price[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> price[i];
    }

    int max_revenue = BottomUpCutRod(price, n);
    cout << max_revenue << endl;
    printCutRodSolution(price, n);

    return 0;
}
