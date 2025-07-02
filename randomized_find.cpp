#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j <= right - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[right]);
    return (i + 1);
}

int randomizedFind(int arr[], int left, int right, int k) {
    if (left <= right) {
        int pivotIndex = rand() % (right - left + 1) + left;
        swap(arr[pivotIndex], arr[right]);

        int q = partition(arr, left, right);
        int count = q - left + 1;

        if (count == k) {
            return arr[q];
        } else if (k < count) {
            return randomizedFind(arr, left, q - 1, k);
        } else {
            return randomizedFind(arr, q + 1, right, k - count);
        }
    }

    return -1; // In case of invalid input
}

int main() {
    srand(time(0));

    int arr[] = {2, 8, 3, 9, 7, 16, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 5;

    int result = randomizedFind(arr, 0, n - 1, k);

    cout << "The " << k << "th smallest element is: " << result << endl;

    return 0;
}
