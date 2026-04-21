# 1. Why is Binary Search efficient?

Binary Search works in O(log n) time. It repeatedly divides the search space into half, reducing work drastically. However, it works only for sorted arrays. Because in only sorted arrays, it can be certain whether the supposed target is on the left half or right half of the middle of search space.

Example:
1 million elements → ~20 steps only

Hence, it scales extremely well.

---

# 2. Subset Sum: Hard to Solve, Easy to Verify

Subset problem is defined as finding the subset where sum of all elements is exactly equal to target from the input list. 

Solving:
Requires checking all subsets → O(2^n) by bractracking or using Dynamic Approach for psuedo-polynomial time of O(n*target) where n is size of array and target is target given.

Verifying:
verifying only requires to check whether resultant subarray sum equal to target or not and does not involving any other operation → O(m) here 'm' is size of resultant subarray.

Thus, solving is exponential but verification is fast.

---

# 3. TSP Infeasibility

TSP means finding the shortest loop around a given graph component where each vertice is visited exactly once. it is infeasible as to finding solution requires calculating the distance travelled for each valid loop possible, for n verticles we can find the total valid loops to be n! and as we know, n! is extremely fast growing graph and thus for even small inputs, this is not feasible. 

TSP has O(n!) complexity.

At ~15 cities:
Number of routes becomes extremely large → computation exceeds time limit.
---

# 4. Solving vs Verifying

Solving:
It is finding solution from scatch that involves uncertainty of the partial solution correctness until fully complete. in other words, as there is no sure way of knowing whether the pseudo solution a program has find while in operation is correct or not until it has found complete solution, it requires finding all possible routes or solution subsets till complete to verify each one.  
Example: Solving Sudoku  

Verifying:
Verifying is easy as program only has to check whether the given solution meet's the requirement/constraits or not, verifying doesn't involve findling the best optimal solution. but only whether the given solution is correct within constraits/requirements of the problem or not.  
Example: Checking completed Sudoku  

Verification is always faster.

---

# 5. Why NP-Complete is hardest?

- All NP problems reduce to NP-Complete problems  
- If one NP-Complete problem is solved efficiently → all NP become easy  

Thus they represent the hardest problems in NP.