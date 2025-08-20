#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i-1]) {
            return nums[i];
        }
    }
    return -1; // not possible in valid input
}

int main() {
    vector<int> nums = {1,3,4,2,2};
    cout << "Duplicate number: " << findDuplicate(nums) << endl;
    return 0;
}
