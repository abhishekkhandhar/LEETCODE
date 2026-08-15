class Solution {
    public int longestSubsequence(int[] nums) {
        int tot = 0, n = nums.length;
        boolean nonZero = false;

        for (int x : nums) {
            nonZero |= x > 0;
            tot ^= x;
        }

        if (!nonZero) return 0;
        return tot == 0 ? n - 1 : n; 
    }
}