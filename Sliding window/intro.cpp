Sliding window helps reduce time complexity from O(n²) to O(n) for many problems involving subarrays / substrings / contiguous elements.

Step 1: Understand the Concept
Fixed-size window → e.g. size k

Dynamic-size window → adjust left/right pointers based on condition

// Fixed-size sliding window example
for (int i = 0; i < n; i++) {
  windowSum += arr[i];
  if (i >= k - 1) {
    maxSum = max(maxSum, windowSum);
    windowSum -= arr[i - (k - 1)];
  }
}
