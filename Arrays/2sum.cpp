string twoSumTwoPointer(vector<int>& arr, int target) {
    sort(arr.begin(), arr.end()); // sort first
    int left = 0, right = arr.size() - 1;

    while(left < right) {
        int sum = arr[left] + arr[right];
        if(sum == target) return "YES";
        else if(sum < target) left++;
        else right--;
    }
    return "NO";
}
