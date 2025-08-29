// Q no 01 (leetcode ) -  Trapping Rain Water
// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
Example - 
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.


✅ Approach 1 
// Solution : 
class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size(), water = 0;
        int leftMax = 0, rightMax = 0, maxHeight = height[0], index = 0;
        // let ( maxHeight = height[0])
        // index =  index of maxHeight building

        // find max height of building
        for (int i = 1; i < n; i++) {
            if (height[i] > maxHeight) {
                maxHeight = height[i];
                index = i; // this index value define index of  maxHeight
            }
        }

        // left to maxHeight buiding (left part)
        for (int i = 0; i < index; i++) {
            if (leftMax > height[i]) {
                water += leftMax - height[i];
            } else {
                // if your left building height less than current building
                // (height[i]) then water will be not store and so make current
                // building
                // as a next leftMax building
                leftMax = height[i];
            }
        }

        // right to maxHeight buiding (right part)
        for (int i = n - 1; i > index; i--) {
            if (rightMax > height[i]) {
                water += rightMax - height[i];
            } else {
                rightMax = height[i];
            }
        }

        return water;
    }
};


✅ Approach 2 - using (two-pointer)

// idea -
// Keep two pointers left and right at array ends and two running maxima leftMax and rightMax.
// Whichever side has the smaller height determines how much water that side can trap (because water level is
// limited by the smaller of the two sides). Move that pointer inward, update its max, and add trapped
// water = max(0, leftMax - height[left]) or max(0, rightMax - height[right]). Repeat until the pointers meet.

    class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0; // edge case

        int left = 0;            // start of array
        int right = n - 1;       // end of array
        int leftMax = 0;         // max height seen so far from left side
        int rightMax = 0;        // max height seen so far from right side
        int water = 0;           // accumulated trapped water

        // Process until the two pointers meet
        while (left < right) {
            // Always move the side with the smaller height:
            // because the trapped water depends on the minimum boundary.
            if (height[left] <= height[right]) {
                // If current left bar is higher than any seen before from left,
                // it becomes the new left boundary (no water added).
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                } else {
                    // Otherwise, water can be trapped above this bar
                    // equal to the difference between leftMax and current height.
                    water += leftMax - height[left];
                }
                ++left; // move left pointer inward
            } else {
                // Symmetric logic for the right side
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                } else {
                    water += rightMax - height[right];
                }
                --right; // move right pointer inward
            }
        }

        return water;
    }
};


// Q no - 02     ---------Triplet Sum in Array  - gfg (medium) -----------
// Given an array arr[] and an integer target, determine if there exists
// a triplet in the array whose sum equals the given target.
// Return true if such a triplet exists, otherwise, return false.

// example -
// Input: arr[] = [1, 4, 45, 6, 10, 8], target = 13
// Output: true 
// Explanation: The triplet {1, 4, 8} sums up to 13.


✅ Approach 1 
✅ This works in O(n³) brute-force time.
👉 You can optimize using sorting + two-pointer technique to O(n²).

class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
        // Code Here
        
        int n = arr.size();
        for(int i = 0; i < n - 2; i++) {
            for(int j = i + 1; j < n - 1; j++) {
                for(int k = j + 1; k < n; k++) {
                    if(arr[i] + arr[j] + arr[k] == target) {
                        return true;
                    }
                }
            }
        }
        return false;
        
    }
};


✅ Approach 2
// sorting + two-pointer approach
// ⏱ Complexity:
// Sorting: O(n log n)
// Outer loop: O(n)
// Inner two-pointer: O(n)
// 👉 Total = O(n²)

class Solution {
public:
    bool hasTripletSum(vector<int> &arr, int target) {
        int n = arr.size();
        sort(arr.begin(), arr.end()); // sort the array first

        // Fix one element and use two-pointer for the rest
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = arr[i] + arr[left] + arr[right];
                
                if (sum == target) {
                    return true;  // triplet found
                }
                else if (sum < target) {
                    left++;  // need bigger sum
                } else {
                    right--; // need smaller sum
                }
            }
        }
        return false; // no triplet found
    }
};


    











