// Given an array arr[]  and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.

// Note: If a window does not contain a negative integer, then return 0 for that window.

// Examples:

// Input: arr[] = [-8, 2, 3, -6, 10] , k = 2
// Output: [-8, 0, -6, -6]
// Explanation:
// Window [-8, 2] First negative integer is -8.
// Window [2, 3] No negative integers, output is 0.
// Window [3, -6] First negative integer is -6.
// Window [-6, 10] First negative integer is -6.
// Input: arr[] = [12, -1, -7, 8, -15, 30, 16, 28] , k = 3
// Output: [-1, -1, -7, -15, -15, 0] 
// Explanation:
// Window [12, -1, -7] First negative integer is -1.
// Window [-1, -7, 8] First negative integer is -1.
// Window [-7, 8, -15] First negative integer is -7.
// Window [8, -15, 30] First negative integer is -15.
// Window [-15, 30, 16] First negative integer is -15.
// Window [30, 16, 28] No negative integers, output is 0.


class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
         queue<pair<int, int>> qt;
        int j = 0;
        vector<int> ans;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] < 0) qt.push({arr[i], i});

            // Only process once the window is of size k
            if (i - j + 1 == k) {
                // Check if front of queue is within current window
                if (!qt.empty() && qt.front().second >= j) {
                    ans.push_back(qt.front().first);
                } else {
                    ans.push_back(0);
                }

                // Remove the front element if it is going out of the window
                if (!qt.empty() && qt.front().second == j) {
                    qt.pop();
                }

                // Slide the window
                j++;
            }
        }

        return ans;
    }
};