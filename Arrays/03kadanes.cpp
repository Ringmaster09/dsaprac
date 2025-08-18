#include <iostream>
#include <climits> // for INT_MIN
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int max_so_far = INT_MIN; // stores overall max sum
    int max_ending_here = 0;  // stores current subarray sum

    for (int i = 0; i < n; i++) {
        max_ending_here += arr[i];

        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0; // reset if sum goes negative
    }

    cout << "Maximum subarray sum is " << max_so_far << endl;
    return 0;
}
