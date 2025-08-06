#include <iostream>
#include <string>
using namespace std;

void naiveStringMatch(string T, string P) {
    int n = T.length();  // Length of text
    int m = P.length();  // Length of pattern
    int comparisons = 0;

    cout << "\n--- Naive Algorithm Tracing ---\n";
    for (int i = 0; i <= n - m; i++) {
        cout << "Checking window starting at index " << i << endl;
        int j = 0;
        while (j < m && T[i + j] == P[j]) {
            comparisons++;
            j++;
        }
        comparisons++; // for the failed comparison
        if (j == m) {
            cout << "Pattern found at index " << i << endl;
        } else {
            cout << "Mismatch at window starting index " << i << endl;
        }
    }

    cout << "Total comparisons: " << comparisons << endl;
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
