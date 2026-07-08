class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, maxLen = 0;
        auto expand = [&](int l, int r) {
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }
            // step back to last valid palindrome
            l++; r--;
            int len = r - l + 1;
            if (len > maxLen) {
                maxLen = len;
                start = l;
            }
        };
        for (int i = 0; i < n; i++) {
            expand(i, i);     // odd length
            expand(i, i + 1); // even length
        }
        return s.substr(start, maxLen);
    }
};