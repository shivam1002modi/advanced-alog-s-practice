#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Swapping function
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function
int partition(int a[], int p, int r) {
    int x = a[r];     // pivot element
    int i = p - 1;

    for (int j = p; j <= r - 1; j++) {
        if (a[j] <= x) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return (i + 1);
}

// Randomized Quick Sort
void RQS(int a[], int p, int r) {
    if (p < r) {
        int i = rand() % (r - p + 1) + p; // random index from p to r
        swap(a[i], a[r]);
        int q = partition(a, p, r);
        RQS(a, p, q - 1);
        RQS(a, q + 1, r);
    }
}

// Main driver
int main() {
    srand(time(0));

    const int n = 1000;
    int a[n];

    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }

    RQS(a, 0, n - 1);

    // Output to confirm sorting
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
