Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

 

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
 

Constraints:

1 <= nums.length <= 50000
1 <= nums[i] <= 10^5
1 <= k <= nums.length


class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int j = 0;
        int i = 0;
        int count = 0;       // current count of odd numbers in window [i..j]
        int total = 0;       // final answer (number of valid subarrays)
        int lastInd = -1;    // stores the index of the last odd number seen

        while (j < nums.size()) {
            if (nums[j] % 2 == 1) count++;  // if nums[j] is odd, increment count
            
            // Shrink window from the left if count > k
            while (count > k) {
                total += j - lastInd;       // add number of subarrays ending before j
                if (nums[i] % 2 == 1) count--;
                i++;
            }

            // Update the position of the last odd number seen
            if (nums[j] % 2 == 1) lastInd = j;

            // Special handling when we're at the end and count == k
            while (k == count && j == nums.size() - 1) {
                total += j - lastInd + 1;
                if (nums[i] % 2 == 1) count--;
                i++;
            }

            j++;
        }

        return total;
    }
};
