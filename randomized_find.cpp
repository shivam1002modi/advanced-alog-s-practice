#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to swap two elements
void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

// Function to partition the array around a pivot
int partition(int a[], int left, int right) {
    int pivot = a[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[right]);
    return i + 1;
}

// Randomized Find function to get kth smallest element
int randomizedFind(int a[], int left, int right, int k) {
    if (left <= right) {
        // Step 1: pick random number y from s
        int randomIndex = rand() % (right - left + 1) + left;
        swap(a[randomIndex], a[right]);

        // Step 2: partition around y
        int pos = partition(a, left, right); // pos is index of y
        int numOnLeft = pos - left; // how many elements < y

        // Step 3: check conditions
        if (numOnLeft == k - 1) {
            return a[pos]; // y is the kth smallest
        }
        else if (numOnLeft > k - 1) {
            // find in left part
            return randomizedFind(a, left, pos - 1, k);
        }
        else {
            // find in right part
            return randomizedFind(a, pos + 1, right, k - numOnLeft - 1);
        }
    }

    return -1; // base case if not found
}

int main() {
    srand(time(0)); // for randomness

    int a[] = {2, 8, 3, 9, 7, 16, 4};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 5;

    int ans = randomizedFind(a, 0, n - 1, k);

    cout << "The " << k << "th smallest element is: " << ans << endl;

    return 0;
}
