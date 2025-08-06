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

// Horspool matching function
int horspoolMatching(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    int shift[256];

    horspoolShiftTable(pattern, shift); // Preprocess shift table

    int j = 0; // starting position in text
    while (j <= n - m) {
        // Compare last character of pattern with current position in text
        if (pattern[m - 1] == text[j + m - 1]) {
            int i = m - 2;
            // Compare remaining characters from right to left
            while (i >= 0 && pattern[i] == text[j + i]) {
                i--;
            }
            if (i == -1) {
                return j; // Match found at position j
            }
        }
        // Shift based on last character of current window
        j = j + shift[(unsigned char)text[j + m - 1]];
    }
    return -1; // No match
}

// Main function
int main() {
    string text, pattern;

    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter pattern: ";
    getline(cin, pattern);

    int pos = horspoolMatching(text, pattern);

    if (pos != -1) {
        cout << "Pattern found at index " << pos << endl;
    } else {
        cout << "Pattern not found" << endl;
    }

    return 0;
}
