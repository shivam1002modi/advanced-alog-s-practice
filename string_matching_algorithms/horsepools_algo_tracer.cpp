#include <iostream>
#include <string>
using namespace std;

// Function to create the shift table
void horspoolShiftTable(string pattern, int shift[]) {
    int m = pattern.length();

    // Initialize all shifts to pattern length
    for (int i = 0; i < 256; i++) {
        shift[i] = m;
    }

    // For each character in pattern (except last), calculate shift
    for (int i = 0; i < m - 1; i++) {
        shift[(unsigned char)pattern[i]] = m - 1 - i;
    }
}

// Horspool matching function with tracing
int horspoolMatching(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    int shift[256];
    int comparisons = 0;

    horspoolShiftTable(pattern, shift); // Preprocess shift table

    cout << "\n--- Horspool Tracing ---\n";
    int j = 0; // starting position in text
    while (j <= n - m) {
        cout << "Checking window starting at index " << j << endl;

        // Compare last character of pattern with current position in text
        comparisons++;
        if (pattern[m - 1] == text[j + m - 1]) {
            int i = m - 2;
            // Compare remaining characters from right to left
            while (i >= 0 && pattern[i] == text[j + i]) {
                comparisons++;
                i--;
            }
            if (i == -1) {
                cout << "Match found at index " << j << endl;
                cout << "Total comparisons: " << comparisons << endl;
                return j; // Match found
            }
        }
        int shiftValue = shift[(unsigned char)text[j + m - 1]];
        cout << "Mismatch, shifting by " << shiftValue << "\n";
        j = j + shiftValue;
    }

    cout << "Pattern not found\n";
    cout << "Total comparisons: " << comparisons << endl;
    return -1; // No match
}

// Main function
int main() {
    string text, pattern;

    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter pattern: ";
    getline(cin, pattern);

    horspoolMatching(text, pattern);

    return 0;
}
