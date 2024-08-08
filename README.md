# Maximum Number of Operations With the Same Score II
Given an array of integers called nums, you can perform any of the following operation while nums contains at least 2 elements:

Choose the first two elements of nums and delete them.
Choose the last two elements of nums and delete them.
Choose the first and the last elements of nums and delete them.
The score of the operation is the sum of the deleted elements.

Your task is to find the maximum number of operations that can be performed, such that all operations have the same score.

Return the maximum number of operations possible that satisfy the condition mentioned above.

Leetcode link: [https://leetcode.com/problems/merge-intervals/description/](https://leetcode.com/problems/maximum-number-of-operations-with-the-same-score-ii/description/)
 
**Examples:**</br>
**Example 1:**</br>
Input: nums = [3,2,1,2,3,4]</br>
Output: 3</br>
Explanation: We perform the following operations:
- Delete the first two elements, with score 3 + 2 = 5, nums = [1,2,3,4].
- Delete the first and the last elements, with score 1 + 4 = 5, nums = [2,3].
- Delete the first and the last elements, with score 2 + 3 = 5, nums = [].
We are unable to perform any more operations as nums is empty.

**Example 2:**</br>
Input:nums = [3,2,6,1,4]</br>
Output: 2</br>
Explanation: We perform the following operations:
- Delete the first two elements, with score 3 + 2 = 5, nums = [6,1,4].
- Delete the last two elements, with score 1 + 4 = 5, nums = [6].
It can be proven that we can perform at most 2 operations.</br>

**Constraints:**</br>
- ```2 <= nums.length <= 2000```
- ```1 <= nums[i] <= 1000```
 

**Scoring**</br>
- Solutions must pass all test cases, including edge cases; tests used for grading/scoring may not be the same tests provided as examples.
- Fast execution times will be rewarded, but solutions must, first and foremost, be correct and complete.
- If more than three languages are submitted, the fastest solution from each of the top three will be considered.

**Submission**
- All solutions must be submitted either via an MR into this GitHub repo or through email by August 18th at 23:59:59


