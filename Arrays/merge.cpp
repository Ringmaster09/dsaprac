#include <bits/stdc++.h>
using namespace std;

// Function to merge two halves
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    int i = left, j = mid + 1;

    // merge two sorted halves
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // add remaining elements
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= right) {
        temp.push_back(arr[j]);
        j++;
    }

    // copy back to original array
    for (int k = left; k <= right; k++) {
        arr[k] = temp[k - left];
    }
}

// Recursive Merge Sort function
void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);      // sort left half
    mergeSort(arr, mid + 1, right); // sort right half
    merge(arr, left, mid, right);   // merge them
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    int n = arr.size();

    mergeSort(arr, 0, n - 1);

    cout << "Sorted Array: ";
    for (int x : arr) cout << x << " ";
    return 0;
}
