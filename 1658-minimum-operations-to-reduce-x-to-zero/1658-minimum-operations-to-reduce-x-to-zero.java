class Solution {
    public int minOperations(int[] nums, int x) {

        int n = nums.length;

        // Calculate total sum of the array
        int totalSum = 0;

        for (int num : nums) {
            totalSum += num;
        }

        // Instead of removing elements with sum x,
        // find the longest subarray that we can keep.
        int target = totalSum - x;

        // x is larger than the total sum,
        // so it is impossible.
        if (target < 0) {
            return -1;
        }

        // target = 0 means we have to remove everything.
        if (target == 0) {
            return n;
        }

        int left = 0;
        int sum = 0;

        // Length of the longest subarray
        // whose sum is target.
        int maxLength = -1;

        for (int right = 0; right < n; right++) {

            sum += nums[right];

            // Since all numbers are positive,
            // shrink the window if the sum is too large.
            while (sum > target) {
                sum -= nums[left];
                left++;
            }

            // Found a valid subarray.
            if (sum == target) {
                maxLength =
                    Math.max(
                        maxLength,
                        right - left + 1
                    );
            }
        }

        // No subarray with sum = target exists.
        if (maxLength == -1) {
            return -1;
        }

        // Keep the longest possible subarray,
        // so remove the fewest elements.
        return n - maxLength;
    }
}