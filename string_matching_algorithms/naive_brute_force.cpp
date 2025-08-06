#include <iostream>
#include <string>
using namespace std;

void naiveStringMatch(string T, string P) {
    int n = T.length();  // Length of text
    int m = P.length();  // Length of pattern

    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        // Check for pattern match
        while (j < m && T[i + j] == P[j]) {
            j++;
        }
        if (j == m) {
            cout << "Pattern found at index " << i << endl;
        }
    }
}

int main() {
    string T, P;
    cout << "Enter Text: ";
    getline(cin, T);
    cout << "Enter Pattern: ";
    getline(cin, P);

    naiveStringMatch(T, P);
    return 0;
}
