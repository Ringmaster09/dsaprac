#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &v) {
    int cnt = 0;   // counter
    int el;        // candidate element

    // Step 1: Find candidate using Moore's Voting
    for (int i = 0; i < v.size(); i++) {
        if (cnt == 0) {
            cnt = 1;
            el = v[i];
        }
        else if (v[i] == el) {
            cnt++;
        }
        else {
            cnt--;
        }
    }

    // Step 2: Verify if candidate is really majority
    int cnt1 = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == el) cnt1++;
    }

    if (cnt1 > v.size() / 2) return el;
    return -1;  // no majority element
}

int main() {
    vector<int> arr = {2, 2, 1, 1, 1, 3, 1, 1};
    cout << majorityElement(arr) << endl;
    return 0;
}
