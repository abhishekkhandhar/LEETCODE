class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 and nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 1 and nums[j] == nums[j - 1]) {
                    continue;
                }
                int l = j + 1, r = nums.size() - 1;
                while (l < r) {
                    long long a = nums[i], b = nums[j], c = nums[l],
                              d = nums[r];
                    long long sum = a + b + c + d;
                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                        while (l < r and nums[l] == nums[l - 1]) {
                            l++;
                        }
                        while (l < r and nums[r] == nums[r + 1]) {
                            r--;
                        }
                    } else if (sum > target) {
                        r--;
                    } else if (sum < target) {
                        l++;
                    }
                }
            }
        }
        return ans;
    }
};