// Given an array of integers arr[]  and a number k. Return the maximum sum of a subarray of size k.

// Note: A subarray is a contiguous part of any given array.

// Examples:

// Input: arr[] = [100, 200, 300, 400] , k = 2
// Output: 700
// Explanation: arr3  + arr4 = 700, which is maximum.

class Solution {
  public:
    int maximumSumSubarray(vector<int>& arr, int k) {
        // code here
        int windowSum=0;
        int maxi=0;
        for(int i=0;i<arr.size();i++){
            if(i>k-1){
                windowSum-=arr[i-k];
            }
            windowSum+=arr[i];
            maxi=max(windowSum,maxi);
        }
        return maxi;
    }
};