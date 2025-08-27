LeetCode 416 – Partition Equal Subset Sum problem.
I’ll give you 3 different approaches (from brute force → optimized DP → bitset trick).


🔹 Approach 1: Brute Force (Recursion / Backtracking)
We try all subsets to see if any subset sums to total_sum / 2.

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total_sum = 0;
        for (int num : nums) total_sum += num;

        if (total_sum % 2 != 0) return false;
        int target = total_sum / 2;

        return canMake(nums, 0, target);
    }

    bool canMake(vector<int>& nums, int i, int target) {
        if (target == 0) return true;  // found subset
        if (i >= nums.size() || target < 0) return false;

        // choice: include or skip
        return canMake(nums, i + 1, target - nums[i]) ||
               canMake(nums, i + 1, target);
    }
};


✅ Simple & easy to understand
❌ Exponential time O(2^n) → slow for large input


🔹 Approach 2: Dynamic Programming (Subset Sum Problem)
We convert it into subset sum:
“Is there a subset with sum = total_sum / 2?”
We use a 1D DP array to optimize.


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total_sum = 0;
        for (int num : nums) total_sum += num;

        if (total_sum % 2 != 0) return false;
        int target = total_sum / 2;

        vector<bool> dp(target + 1, false);
        dp[0] = true; // sum 0 always possible (empty set)

        for (int num : nums) {
            for (int j = target; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }
        return dp[target];
    }
};


✅ Time O(n * target) (much faster)
✅ Works well within constraints (n ≤ 200, sum ≤ 20000)
❌ Needs DP knowledge


🔹 Approach 3: Bitset Optimization (Super Fast)
We use a bitset to track possible sums.

#include <bitset>
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total_sum = 0;
        for (int num : nums) total_sum += num;

        if (total_sum % 2 != 0) return false;
        int target = total_sum / 2;

        bitset<10001> bits(1); // max sum constraint (200*100=20000 safe)
        for (int num : nums) {
            bits |= (bits << num);
        }
        return bits[target];
    }
};


✅ Super fast (O(n * sum/wordsize))
✅ Short & elegant
❌ Uses bit tricks (less intuitive)


🔹 Summary
Approach 1 (Recursion) → Good for understanding, slow.
Approach 2 (DP) → Standard, efficient, most common in interviews.
Approach 3 (Bitset) → Very elegant, fastest in practice.
