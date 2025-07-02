#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int counter = 0; // Global counter to count number of comparisons

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int a[], int p, int r) {
    int x = a[r]; // pivot
    int i = p - 1;

    for (int j = p; j <= r - 1; j++) {
        counter++;  // Count comparison
        if (a[j] <= x) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[r]);  // Final pivot placement
    return (i + 1);
}

void RQS(int a[], int p, int r) {
    if (p < r) {
        int i = rand() % (r - p + 1) + p;  // Random pivot  //removing this line will lead to fixed output 
        swap(a[i], a[r]);                                  //removing this line will lead to fixed output 
        int q = partition(a, p, r);
        RQS(a, p, q - 1);
        RQS(a, q + 1, r);
    }
}

int main() {
    srand(time(0));

    const int n = 1000;
    int a[n];

 
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }


    RQS(a, 0, n - 1);  // Perform randomized quicksort

    // Output sorted array
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    // Output total comparisons
    cout << "Total comparisons made during sorting: " << counter << endl;

    return 0;
}
