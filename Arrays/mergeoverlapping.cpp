#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals) {
    vector<vector<int>> ans;

    if (intervals.empty()) return ans;

    // Step 1: Sort intervals by start time
    sort(intervals.begin(), intervals.end());

    // Step 2: Start with the first interval
    ans.push_back(intervals[0]);

    // Step 3: Loop through the rest
    for (int i = 1; i < intervals.size(); i++) {
        int start = intervals[i][0];
        int end = intervals[i][1];

        // If current interval overlaps with the last one in ans
        if (start <= ans.back()[1]) {
            // Merge by extending the end
            ans.back()[1] = max(ans.back()[1], end);
        } 
        else {
            // No overlap → just add the interval
            ans.push_back(intervals[i]);
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> intervals = {{1,3}, {2,6}, {8,10}, {15,18}};

    vector<vector<int>> result = mergeIntervals(intervals);

    cout << "Merged Intervals: " << endl;
    for (auto it : result) {
        cout << "[" << it[0] << "," << it[1] << "] ";
    }
    cout << endl;

    return 0;
}
