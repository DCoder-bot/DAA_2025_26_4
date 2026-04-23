# Experiment 10 - Distinct Subsequences

## Algorithm

1. Let m = length of s, n = length of t.
2. Create a 2D DP table of size (m+1) x (n+1) initialized to 0.
3. Set dp[i][0] = 1 for all i from 0 to m (empty t is a subsequence of any prefix of s in exactly 1 way).
4. For each i from 1 to m and each j from 1 to n:
   - Set dp[i][j] = dp[i-1][j] (skip s[i-1], don't use it).
   - If s[i-1] == t[j-1], add dp[i-1][j-1] to dp[i][j] (use s[i-1] to match t[j-1]).
5. Return dp[m][n] as the number of distinct subsequences.

---

## Time and Space Complexity

**Time Complexity: O(m × n)**
- Two nested loops iterate over all (m+1) × (n+1) cells of the DP table.
- Each cell is computed in O(1).

**Space Complexity: O(m × n)**
- A 2D DP table of size (m+1) × (n+1) is maintained.
- Can be reduced to O(n) using a 1D array with reverse traversal.

---

## Dry Run

**Input:** s = "babgbag", t = "bag"

m = 7, n = 3

**Initial DP table (all zeros, dp[i][0] = 1):**

|   | "" | b | a | g |
|---|----|---|---|---|
| "" | 1 | 0 | 0 | 0 |
| b  | 1 | 0 | 0 | 0 |
| a  | 1 | 0 | 0 | 0 |
| b  | 1 | 0 | 0 | 0 |
| g  | 1 | 0 | 0 | 0 |
| b  | 1 | 0 | 0 | 0 |
| a  | 1 | 0 | 0 | 0 |
| g  | 1 | 0 | 0 | 0 |

**Filling the table row by row:**

- i=1, s[0]='b': j=1 t[0]='b' match → dp[1][1] = dp[0][1] + dp[0][0] = 0+1 = 1
- i=2, s[1]='a': j=2 t[1]='a' match → dp[2][2] = dp[1][2] + dp[1][1] = 0+1 = 1
- i=3, s[2]='b': j=1 t[0]='b' match → dp[3][1] = dp[2][1] + dp[2][0] = 1+1 = 2
- i=4, s[3]='g': j=3 t[2]='g' match → dp[4][3] = dp[3][3] + dp[3][2] = 0+1 = 1
- i=5, s[4]='b': j=1 t[0]='b' match → dp[5][1] = dp[4][1] + dp[4][0] = 2+1 = 3
- i=6, s[5]='a': j=2 t[1]='a' match → dp[6][2] = dp[5][2] + dp[5][1] = 2+3 = 5
- i=7, s[6]='g': j=3 t[2]='g' match → dp[7][3] = dp[6][3] + dp[6][2] = 3+5 = ... 

**Final DP table:**

|   | "" | b | a | g |
|---|----|---|---|---|
| "" | 1 | 0 | 0 | 0 |
| b  | 1 | 1 | 0 | 0 |
| a  | 1 | 1 | 1 | 0 |
| b  | 1 | 2 | 1 | 0 |
| g  | 1 | 2 | 1 | 1 |
| b  | 1 | 3 | 1 | 1 |
| a  | 1 | 3 | 4 | 1 |
| g  | 1 | 3 | 4 | 5 |

**dp[7][3] = 5**

**Output: 5**
