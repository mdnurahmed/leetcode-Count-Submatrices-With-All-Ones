# [leetcode-Count-Submatrices-With-All-Ones](https://leetcode.com/problems/count-submatrices-with-all-ones/submissions/)
My solution for the problem [leetcode-Count-Submatrices-With-All-Ones](https://leetcode.com/problems/count-submatrices-with-all-ones/submissions/).

## Problem Description 
Given a rows * columns matrix mat of ones and zeros, return how many submatrices have all ones.

### Example 1:

#### Input: 
mat = [[1,0,1],
       [1,1,0],
       [1,1,0]]
#### Output: 13
#### Explanation:
There are 6 rectangles of side 1x1.
There are 2 rectangles of side 1x2.
There are 3 rectangles of side 2x1.
There is 1 rectangle of side 2x2. 
There is 1 rectangle of side 3x1.
Total number of rectangles = 6 + 2 + 3 + 1 + 1 = 13.

### Example 2:
#### Input: 
mat = [[0,1,1,0],
       [0,1,1,1],
       [1,1,1,0]]
#### Output: 24
#### Explanation:
There are 8 rectangles of side 1x1.
There are 5 rectangles of side 1x2.
There are 2 rectangles of side 1x3. 
There are 4 rectangles of side 2x1.
There are 2 rectangles of side 2x2. 
There are 2 rectangles of side 3x1. 
There is 1 rectangle of side 3x2. 
Total number of rectangles = 8 + 5 + 2 + 4 + 2 + 2 + 1 = 24.

### Example 3:
#### Input: 
mat = [[1,1,1,1,1,1]]
#### Output: 21

### Example 4:

#### Input: 
mat = [[1,0,1],[0,1,0],[1,0,1]]
#### Output: 5
 

### Constraints:

- 1 <= rows <= 150
- 1 <= columns <= 150
- 0 <= mat[i][j] <= 1

## My Approach 

### Way 1 
We can imagine the 1s stack on top of each other and form pillars . height[i][j] will tell us the hegiht of the pillar at cell (i,j) . 
```
  | |
  | | |  
| | | |
a b c d 
```
Lets solve this problem for each row . Number of rectangle that ends at point d can be of width 1,2,3 or 4 . 
how many reactnagle is possible if fix width = 3 ? It's minimum height among (b,c,d) . 

### Complexity : 
O(M*N*M) time and O(M*N) space. where M is number of rows and N is number columns . Although we can make space complexity O(N) as we need height[][] of previous row at any time only .

## way 2 

Lets think of 2 table - dp[] and left[] . dp[j] will tell us number of submatrices that end at (i,j). left[j] will tell us the index left of (i,j)till which all the values are greater or equal to height[i][j] from (i,j).

```
  | |
  | | |  
| | | |
a b c d 
```

For example , for the above case left[d] = b .

Then number of submatrices from left[j] to j is (j-left[j]+1)*height[i][j] .
All the submatrices that ends at left[j]-1 can also be expanded to j . 
So, dp[j] = dp[left[j]-1] + (j-left[j]+1)*height[i][j] . 

left[] can be calculated at O(N) time using a stack 

### calculating left[] at linear time 

We can calculate  left[] in linear time using a stack . We traverse the heights from right to left . Every value in the stack means its left[] is still to be caculated . Lets assume the stack looks like this - 

- b 
- c 
- d

so that ,

height[b] >= height[c] >= height[d] 

Now comes a, so that height[a] <  height[b] , height[a] < height[c] and height[a] >= height[d] . So we can pop b and c and calculate their left[] as left[b] = left[c] = a . Now a goes in the stack and waits for its left[] to be calculated . Now the stack looks like - 

- a 
- d 

### Complexity : 
O(M*N) time and O(N) space. where M is number of rows and N is number columns . Although we can make space complexity O(N) as we need height[][] of previous row at any time only .



