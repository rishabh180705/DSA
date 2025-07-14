Given an array of integers A.  There is a sliding window of size B which 

is moving from the very left of the array to the very right. 

You can only see the w numbers in the window. Each time the sliding window moves 

rightwards by one position. You have to find the maximum for each window. 

The following example will give you more clarity.

The array A is [1 3 -1 -3 5 3 6 7], and B is 3.

Window position	Max
———————————-	————————-
[1  3  -1] -3  5  3  6  7	3
1 [3  -1  -3] 5  3  6  7	3
1  3 [-1  -3  5] 3  6  7	5
1  3  -1 [-3  5  3] 6  7	5
1  3  -1  -3 [5  3  6] 7	6
1  3  -1  -3  5 [3  6  7]	7
Return an array C, where C[i] is the maximum value of from A[i] to A[i+B-1].

Note: If B > length of the array, return 1 element with the max of the array.



vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    deque<int> dq;         // Will store indices of useful elements in decreasing order
    vector<int> ans;       // Final result array

    int n = A.size();      // Length of the array

    for (int i = 0; i < n; ++i) {
        // Step 1: Remove indices from the front if they are out of this window
        if (!dq.empty() && dq.front() <= i - B) {
            dq.pop_front();
        }

        // Step 2: Remove all indices from the back whose corresponding values are smaller than A[i]
        // Because they cannot be maximum if A[i] is greater
        while (!dq.empty() && A[dq.back()] < A[i]) {
            dq.pop_back();
        }

        // Step 3: Add current element's index to the deque
        dq.push_back(i);

        // Step 4: If the current window has reached size B, record the max
        if (i >= B - 1) {
            ans.push_back(A[dq.front()]);  // The front of the deque is the max of the current window
        }
    }

    return ans;
}


A = [1, 3, -1, -3, 5, 3, 6, 7]
B = 3

| i | A\[i] | Deque Indices | Deque Values | Window     | Max |
| - | ----- | ------------- | ------------ | ---------- | --- |
| 0 | 1     | \[0]          | \[1]         | -          | -   |
| 1 | 3     | \[1]          | \[3]         | -          | -   |
| 2 | -1    | \[1, 2]       | \[3, -1]     | \[1,3,-1]  | 3   |
| 3 | -3    | \[1, 2, 3]    | \[3, -1, -3] | \[3,-1,-3] | 3   |
| 4 | 5     | \[4]          | \[5]         | \[-1,-3,5] | 5   |
| 5 | 3     | \[4,5]        | \[5, 3]      | \[-3,5,3]  | 5   |
| 6 | 6     | \[6]          | \[6]         | \[5,3,6]   | 6   |
| 7 | 7     | \[7]          | \[7]         | \[3,6,7]   | 7   |
