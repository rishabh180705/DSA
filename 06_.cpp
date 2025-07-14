You are given a string s consisting only lowercase alphabets and an integer k. Your task is to find the length of the longest substring that contains exactly k distinct characters.

Note : If no such substring exists, return -1. 

Examples:

Input: s = "aabacbebebe", k = 3
Output: 7
Explanation: The longest substring with exactly 3 distinct characters is "cbebebe", which includes 'c', 'b', and 'e'.
Input: s = "aaaa", k = 2
Output: -1
Explanation: There's no substring with 2 distinct characters.
Input: s = "aabaaab", k = 2
Output: 7
Explanation: The entire string "aabaaab" has exactly 2 unique characters 'a' and 'b', making it the longest valid substring.



class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int i=0;
        int j=0;
        map<char,int> mpp;
        
        int maxi=0;
        while(j<s.size()){
            
            mpp[s[j]]++;
            
            if(mpp.size()==k){
                maxi=max(maxi,j-i+1);
            }
            
            while(mpp.size()>k){
                mpp[s[i]]--;
                
                if(mpp[s[i]]==0){
                    mpp.erase(s[i]);
                }
                i++;
            }
            
            j++;
            
        }
        return maxi==0?-1:maxi;
    }
};



Given a string s, find the length of the longest substring without duplicate characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        int maxi = 0;
        map<char, int> mpp;
        while (j < s.size()) {

            mpp[s[j]]++;

            while (mpp[s[j]] > 1) {
                mpp[s[i]]--;
                i++;
            }
            maxi = max(maxi, j - i + 1);
            j++;
        }
        return maxi;
    }
};