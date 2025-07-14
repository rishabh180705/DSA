Given a word pat and a text txt. Return the count of the occurrences of anagrams of the word in the text.

Example 1:

Input: txt = "forxxorfxdofr", pat = "for"
Output: 3
Explanation: for, orf and ofr appears in the txt, hence answer is 3.
Example 2:

Input: txt = "aabaabaa", pat = "aaba"
Output: 4
Explanation: aaba is present 4 times in txt.


class Solution {
  public:
    int search(string &pat, string &txt) {
        // Step 1: Create a frequency map of the pattern
        map<char, int> mpp;
        int k = pat.size();  // Window size is the length of the pattern

        for (auto ch : pat) {
            mpp[ch]++;
        }

        int count = mpp.size();  // Number of unique characters to match
        int total = 0;           // Total number of anagrams found
        int i = 0, j = 0;        // Window pointers

        // Step 2: Start sliding window
        while (j < txt.size()) {

            // If current character is part of the pattern, reduce its freq
            if (mpp.find(txt[j]) != mpp.end()) {
                mpp[txt[j]]--;
                if (mpp[txt[j]] == 0) {
                    count--;  // One character fully matched
                }
            }

            // Step 3: When window size equals pattern length
            if (j - i + 1 == k) {
                // If all characters matched, we found an anagram
                if (count == 0) {
                    total++;
                }

                // Slide the window from the left
                if (mpp.find(txt[i]) != mpp.end()) {
                    // If the left character was fully matched, increase count
                    if (mpp[txt[i]] == 0) {
                        count++;
                    }
                    mpp[txt[i]]++;  // Restore frequency for outgoing char
                }

                i++;  // Shrink the window from left
            }

            j++;  // Expand the window from right
        }

        return total;  // Return total number of anagrams found
    }
};
