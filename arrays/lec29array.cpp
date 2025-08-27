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



LeetCode 54 – Maximum Subarray
Given an integer array nums, find the subarray with the largest sum, and return its sum.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=INT_MIN;
        int n = nums.size();
        for(int i=0; i<n; i++){
          int prefix=0;
          for(int j=i; j<n; j++){
            prefix +=nums[j];
            maxi = max(maxi, prefix);
          }
        }
        return maxi;
    }
};

GIVE ME ERROR - Time Limit Exceeded

SOLVE THIS QUESTION USING Kadane’s Algorithm- 

    🔹 What is Kadane’s Algorithm?

Kadane’s Algorithm is a dynamic programming technique to find the maximum subarray sum in a given integer array.

👉 Problem: Given nums, find the contiguous subarray (with at least one element) which has the largest sum.

Example:
nums = [-2,1,-3,4,-1,2,1,-5,4]
Answer = 6 (subarray [4,-1,2,1])

🔹 Why Kadane’s Algorithm?

Naive brute force checks all possible subarrays (O(n²) or O(n³)), which is too slow for large arrays.
Kadane’s Algorithm solves it in O(n) time with a simple loop.

🔹 How does Kadane’s Algorithm work?

The key idea:
At each index i, the maximum subarray ending at i is either:
Start fresh at nums[i]
Extend the previous subarray (current_sum + nums[i])
current_sum = max(nums[i], current_sum + nums[i])
Keep track of the best (max_sum) so far:
max_sum = max(max_sum, current_sum)

🔹 Kadane’s Algorithm (Steps)
Initialize:
current_sum = nums[0]
max_sum = nums[0]
Loop from i = 1 to n-1:
current_sum = max(nums[i], current_sum + nums[i])
max_sum = max(max_sum, current_sum)
Return max_sum.
    
🔹 Example Dry Run
nums = [-2,1,-3,4,-1,2,1,-5,4]
Start: current_sum = -2, max_sum = -2
i=1 → nums[1]=1
current_sum = max(1, -2+1)=1
max_sum = max(-2,1)=1

i=2 → nums[2]=-3
current_sum = max(-3, 1-3)=-2
max_sum=1

i=3 → nums[3]=4
current_sum=max(4,-2+4)=4
max_sum=max(1,4)=4

i=4 → nums[4]=-1
current_sum=max(-1,4-1)=3
max_sum=4

i=5 → nums[5]=2
current_sum=max(2,3+2)=5
max_sum=5

i=6 → nums[6]=1
current_sum=max(1,5+1)=6
max_sum=6

i=7 → nums[7]=-5
current_sum=max(-5,6-5)=1
max_sum=6

i=8 → nums[8]=4
current_sum=max(4,1+4)=5
max_sum=6

✅ Final Answer = 6 ([4,-1,2,1])

🔹 Why does it work?
Because it only keeps useful information:
If the running sum becomes negative, discard it and start fresh.
Negative sums will only reduce future subarray totals.
This greedy + DP approach ensures every subarray is considered implicitly in O(n) time.


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current_sum = nums[0];
        int max_sum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            current_sum = max(nums[i], current_sum + nums[i]);
            max_sum = max(max_sum, current_sum);
        }
        return max_sum;
    }
};

🔹 Summary
Kadane’s Algorithm = Maximum Subarray Sum in O(n).
Works by deciding at each step: extend previous subarray OR start fresh.
Uses dynamic programming (store best subarray ending at i).
Very efficient: O(n) time, O(1) space.

    
53. Maximum Subarray -  leetcode 
Given an integer array nums, find the subarray with the largest sum, and return its sum.
    Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

    
    class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN, prefix = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            prefix += nums[i];
            maxi = max(maxi, prefix);
            if (prefix < 0) {
                prefix = 0;
            }
        }
        return maxi;
    }
};







