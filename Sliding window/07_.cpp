Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 

Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.
 

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        // Step 1: Build frequency map for string `t`
        map<char, int> mpp;
        for (char ch : t) mpp[ch]++;

        // Number of unique characters in `t` that need to be matched in `s`
        int required = mpp.size();

        // Number of characters that have met their required frequency in current window
        int formed = 0;

        // Sliding window pointers
        int left = 0, right = 0;

        // Track the window length and start index of the minimum window found
        int minLen = INT_MAX;
        int start = 0;

        // Map to count characters in the current window
        map<char, int> window;

        // Step 2: Expand the window
        while (right < s.size()) {
            char c = s[right];
            window[c]++;

            // If character frequency in window matches target frequency
            if (mpp.count(c) && window[c] == mpp[c]) {
                formed++;
            }

            // Step 3: Try to shrink the window from the left while it's valid
            while (left <= right && formed == required) {
                // Update the minimum window
                if ((right - left + 1) < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Remove character at `left` from window and move `left` forward
                char removeChar = s[left];
                window[removeChar]--;

                // If it's a required character and we drop below needed frequency
                if (mpp.count(removeChar) && window[removeChar] < mpp[removeChar]) {
                    formed--;
                }

                left++; // shrink the window
            }

            // Expand the window
            right++;
        }

        // Step 4: Return the smallest valid window, or empty string if not found
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
