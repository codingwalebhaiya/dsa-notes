// Q no 42 (leetcode ) -  Trapping Rain Water
// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
Example - 
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

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
