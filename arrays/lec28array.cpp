# Problem: Segregate 0s and 1s

**Platform**: GFG  
**Difficulty**: easy  
**Link**: https://www.geeksforgeeks.org/problems/segregate-0s-and-1s5106/1

---

## Problem Statement
Given an array arr consisting of only 0's and 1's in random order. Modify the array in-place to segregate 0s onto the left side and 1s onto the right side of the array.

Examples :

Input: arr[] = [0, 0, 1, 1, 0]
Output: [0, 0, 0, 1, 1]
Explanation:  After segregation, all the 0's are on the left and 1's are on the right. Modified array will be [0, 0, 0, 1, 1].

 
class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        
        int n= arr.size();
        int start=0, end=n-1;
        
        while(start<end){
            if(arr[start] ==0){
                start++; 
            }
           
            else {
                if(arr[end] ==0){
                      swap(arr[start], arr[end]);
                start++, end--;
                }
              
                else {
                    end--;
                }
                
            } 
            
        }
        
    }
};



# Problem: 167. Two Sum II - Input Array Is Sorted

**Platform**: LeetCode  
**Difficulty**: Medium  
**Link**: [Two Sum](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)

---

## Problem Statement
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that
they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.
The tests are generated such that there is exactly one solution. You may not use the same element twice.
Your solution must use only constant extra space.
---

## Example
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

---

 ## Multiple approaches (binary search + hashmap for understanding + two-pointer optimal).

✅ Approach 1: Brute Force (O(n²)) – Not optimal, but for understanding

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        // Check every pair
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (numbers[i] + numbers[j] == target) {
                    // +1 because array is 1-indexed in the problem statement
                    return {i + 1, j + 1};
                }
            }
        }
        return {};
    }
};

❌ Time Complexity: O(n²) (not efficient for large inputs).
✅ Space Complexity: O(1).


✅ Approach 2: Binary Search (O(n log n))
Since the array is sorted, for each element we can search the complement using binary search.

  #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for (int i = 0; i < n; i++) {
            int complement = target - numbers[i];
            int low = i + 1, high = n - 1;
            // Binary search for complement
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (numbers[mid] == complement) {
                    return {i + 1, mid + 1};
                }
                else if (numbers[mid] < complement) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }
        return {};
    }
};

✅ Time Complexity: O(n log n)
✅ Space Complexity: O(1)



  


✅ Approach 3: Two-Pointer (Optimal: O(n))
This is the best approach since array is sorted.
  
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];

            if (sum == target) {
                // return indices in 1-indexed format
                return {left + 1, right + 1};
            }
            else if (sum < target) {
                // If sum is too small, move left pointer to increase sum
                left++;
            }
            else {
                // If sum is too large, move right pointer to decrease sum
                right--;
            }
        }
        return {};
    }
};


✅ Time Complexity: O(n)
✅ Space Complexity: O(1)
🔥 Most efficient solution.

  
  ##  --------- STEP BY STEP dry run of Approach 3 (Two Pointers) ----------- ##

numbers = [2, 7, 11, 15]
target = 9
Initialize pointers:
left = 0 → points to first element (2)

right = 3 → points to last element (15)

Iteration 1:
sum = numbers[left] + numbers[right]

sum = 2 + 15 = 17

17 > 9 → sum is too big, so we move right pointer left.

New state: left = 0, right = 2

Iteration 2:
sum = numbers[left] + numbers[right]

sum = 2 + 11 = 13

13 > 9 → still too big, move right pointer left.

New state: left = 0, right = 1

Iteration 3:
sum = numbers[left] + numbers[right]

sum = 2 + 7 = 9 ✅

Found the target!

Return → [left + 1, right + 1] = [1, 2]

Final Answer:
csharp
Copy
Edit
[1, 2]
💡 Key insight:

If sum > target → decrease right pointer (to reduce sum).

If sum < target → increase left pointer (to increase sum).

This works because the array is sorted.




  # Problem: 1. Two Sum 
**Platform**: LeetCode  
**Difficulty**: easy  
**Link**: [Two Sum](https://leetcode.com/problems/two-sum/)

---

## Problem Statement
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
---

## Example
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

---

  ✅ Approach 1: Brute Force (O(n²)) – Not optimal

  class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i]+nums[j]==target){
                    return {i, j};
                }
            }
        }

        return {};
    }
};





# Problem: --------------- Find Pair Given Difference  ------------

**Platform**: GFG  
**Difficulty**: EASY  
**Link**:https://www.geeksforgeeks.org/problems/find-pair-given-difference1559/1

## Problem Statement
Given an array, arr[] and an integer x, return true if there exists a pair of elements in the array whose absolute difference is x, otherwise, return false.

Examples:
Input: arr[] = [5, 20, 3, 2, 5, 80], x = 78
Output: true
Explanation: Pair (2, 80) have an absolute difference of 78.


✅ Approach 1: Brute Force (O(n²))
Compare every pair using two loops.
Check if abs(arr[i] - arr[j]) == x.
👉 Simple, but not efficient.

#include <bits/stdc++.h>
using namespace std;

bool findPairBrute(vector<int>& arr, int x) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (abs(arr[i] - arr[j]) == x) return true;
        }
    }
    return false;
}

int main() {
    vector<int> arr = {5, 20, 3, 2, 5, 80};
    int x = 78;
    cout << (findPairBrute(arr, x) ? "true" : "false");
}



✅ Approach 2: Sorting + Two Pointers (O(n log n))
Sort the array.
Use two pointers i and j.
If arr[j] - arr[i] == x, return true.
If difference < x → move j ahead.
If difference > x → move i ahead.
👉 More efficient than brute force.


class Solution {
  public:
    bool findPair(vector<int> &arr, int x) {
        
         sort(arr.begin(), arr.end()); 
         int n = arr.size();
         int i=0, j=1;
         
         while(i<n && j<n){
             
             if(i !=j && arr[j] - arr[i] == x){
                 return true;
             }
             else if(arr[j] - arr[i] < x){
                 j++; // Increase difference
             }
             else {
                 i++; // decrease difference 
             }
             
              // Ensure i and j are never equal
            if (i == j) j++;
         }
         return false; // no pair found
         
    }
};


int main() {
    vector<int> arr = {5, 20, 3, 2, 5, 80};
    int x = 78;
    cout << (findPairTwoPointer(arr, x) ? "true" : "false");
}



✅ Approach 3: Hashing (O(n))
Use a hash set to store numbers.
For each number num, check:
If num + x exists, return true.
If num - x exists, return true.
 
👉 Best approach for large arrays.

 #include <bits/stdc++.h>
using namespace std;

bool findPairHashing(vector<int>& arr, int x) {
    unordered_set<int> s;
    for (int num : arr) {
        if (s.count(num + x) || s.count(num - x)) return true;
        s.insert(num);
    }
    return false;
}

int main() {
    vector<int> arr = {5, 20, 3, 2, 5, 80};
    int x = 78;
    cout << (findPairHashing(arr, x) ? "true" : "false");
}


🔎 Summary of Approaches
Brute Force: O(n²), easy but slow.
Sorting + Two Pointers: O(n log n), efficient.
Hashing (unordered_set): O(n), fastest.

