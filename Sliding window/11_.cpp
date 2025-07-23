Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
Example 3:

Input: s = "abc"
Output: 1
 

Constraints:

3 <= s.length <= 5 x 10^4
s only consists of a, b or c characters.


class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> freq(3, 0);  // To track frequency of 'a', 'b', and 'c'
        int i = 0, j = 0;
        int total = 0;

        // Traverse the string with the right pointer j
        while (j < s.size()) {
            freq[s[j] - 'a']++;  // Increment the frequency of current character

            // Check if current window [i..j] contains at least one of each 'a', 'b', and 'c'
            while (freq[0] != 0 && freq[1] != 0 && freq[2] != 0) {
                // If window is valid, then all substrings from [i..j] to [i..end] are valid
                // There are (s.size() - j) such substrings
                total += s.size() - j;

                // Try to reduce the window from the left to find other valid windows
                freq[s[i] - 'a']--;  // Remove s[i] from the window
                i++;  // Move the left pointer forward
            }

            j++;  // Move the right pointer forward
        }

        return total;
    }
};
