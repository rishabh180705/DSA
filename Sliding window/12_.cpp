992. Subarrays with K Different Integers

Hard

Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
Example 2:

Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
 

Constraints:

1 <= nums.length <= 2 * 104
1 <= nums[i], k <= nums.length


class Solution {
public:

    // Helper function to count the number of subarrays with at most 'k' distinct integers
    long long solve(vector<int>& nums, int k) {
        map<int, int> mpp;  // Map to store frequency of elements in the current window
        int i = 0, j = 0;   // Sliding window pointers
        long long count = 0;

        while (j < nums.size()) {
            mpp[nums[j]]++;  // Include nums[j] in the current window

            // If we have more than 'k' distinct integers in the window, shrink it from the left
            while (mpp.size() > k) {
                mpp[nums[i]]--;  // Decrease the frequency of nums[i]
                if (mpp[nums[i]] == 0) {
                    mpp.erase(nums[i]);  // Remove it from the map if frequency becomes 0
                }
                i++;  // Shrink the window from the left
            }

            // Now the window [i..j] has at most 'k' distinct integers
            // So, all subarrays ending at j and starting from i to j are valid
            count += j - i + 1;

            j++;  // Move the right pointer forward
        }

        return count;
    }

    // Main function to return the number of subarrays with exactly k distinct integers
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // Number of subarrays with exactly k distinct integers
        // = (Number with at most k distinct) - (Number with at most k-1 distinct)
        return solve(nums, k) - solve(nums, k - 1);
    }
};
