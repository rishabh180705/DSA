Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 10^4
-1000 <= nums[i] <= 1000
-10^7 <= k <= 10^7


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;         // Tracks the current prefix sum
        int cnt = 0;         // Total count of subarrays with sum == k
        int n = nums.size(); // Length of the input array
        
        unordered_map<int, int> mp;  // Stores frequency of each prefix sum

        for (int i = 0; i < n; i++) {
            sum += nums[i];  // Compute current prefix sum
            
            // Case 1: Entire subarray from index 0 to i has sum == k
            if (sum == k)
                cnt++;       // Increment count for this subarray
            
            // Case 2: Check if there is a prefix sum such that:
            // sum - k = some previous prefix sum (rem)
            // If yes, then a subarray exists between that point and current index
            int rem = sum - k;
            if (mp.find(rem) != mp.end()) {
                cnt += mp[rem]; // Add the number of times that prefix occurred
            }

            // Update the frequency of the current prefix sum
            mp[sum]++;
        }

        return cnt;  // Return total count of valid subarrays
    }
};


Given an array arr[] containing integers and an integer k, your task is to find the length of the longest subarray where the sum of its elements is equal to the given value k. If there is no subarray with sum equal to k, return 0.

Examples:

Input: arr[] = [10, 5, 2, 7, 1, -10], k = 15
Output: 6
Explanation: Subarrays with sum = 15 are [5, 2, 7, 1], [10, 5] and [10, 5, 2, 7, 1, -10]. The length of the longest subarray with a sum of 15 is 6.
Input: arr[] = [-5, 8, -14, 2, 4, 12], k = -5
Output: 5
Explanation: Only subarray with sum = -5 is [-5, 8, -14, 2, 4] of length 5.
Input: arr[] = [10, -10, 20, 30], k = 5
Output: 0
Explanation: No subarray with sum = 5 is present in arr[].

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int maxLen = 0;                     // To store the maximum length found
        long long sum = 0;                  // Running prefix sum
        unordered_map<int, int> mpp;        // Stores first occurrence of each prefix sum

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];                 // Add current element to running sum

            // Case 1: If prefix sum == k, entire subarray [0...i] is valid
            if (sum == k) {
                maxLen = max(i + 1, maxLen);
            }

            // Case 2: Check if (sum - k) has been seen before
            // If yes, subarray from that index+1 to i has sum = k
            int rem = sum - k;
            if (mpp.find(rem) != mpp.end()) {
                int len = i - mpp[rem];     // Length of the found subarray
                maxLen = max(maxLen, len);  // Update maxLen if longer
            }

            // Store the first occurrence of the prefix sum
            // Only insert if not already present (we want the earliest index)
            if (mpp.find(sum) == mpp.end()) {
                mpp[sum] = i;
            }
        }

        return maxLen;  // Return the maximum subarray length found
    }
};
