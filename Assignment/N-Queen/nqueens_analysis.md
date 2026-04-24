# N-Queens: Dry Run & Complexity Analysis

---

## Dry Run (N = 4)

### Initial State

```
colUsed      = [F, F, F, F]
diagUsed     = [F, F, F, F, F, F, F]   (size = 2*4-1 = 7)
antiDiagUsed = [F, F, F, F, F, F, F]
queenCol     = [-1, -1, -1, -1]
```

---

### Row 0

| col | colUsed[col] | diag[0-col+3] | antiDiag[0+col] | Result |
|-----|-------------|---------------|-----------------|--------|
| 0   | F           | diag[3] = F   | anti[0] = F     | Place  |
| 1   | F           | diag[2] = F   | anti[1] = F     | Place  |
| 2   | ...         | ...           | ...             | Place  |
| 3   | ...         | ...           | ...             | Place  |

**Try col = 0** → Place queen. queenCol = [0, -1, -1, -1]

Mark: colUsed[0]=T, diagUsed[3]=T, antiDiagUsed[0]=T

---

### Row 1 (queen at row 0, col 0)

| col | colUsed[col] | diag[1-col+3] | antiDiag[1+col] | Result |
|-----|-------------|---------------|-----------------|--------|
| 0   | T           | —             | —               | Skip (col clash) |
| 1   | F           | diag[3] = T   | anti[2] = F     | Skip (diag clash) |
| 2   | F           | diag[2] = F   | anti[3] = F     | Place  |
| 3   | F           | diag[1] = F   | anti[4] = F     | Place  |

**Try col = 2** → Place queen. queenCol = [0, 2, -1, -1]

Mark: colUsed[2]=T, diagUsed[2]=T, antiDiagUsed[3]=T

---

### Row 2 (queens at (0,0) and (1,2))

| col | colUsed[col] | diag[2-col+3] | antiDiag[2+col] | Result |
|-----|-------------|---------------|-----------------|--------|
| 0   | T           | —             | —               | Skip (col clash) |
| 1   | F           | diag[4] = F   | anti[3] = T     | Skip (anti-diag clash) |
| 2   | T           | —             | —               | Skip (col clash) |
| 3   | F           | diag[2] = T   | anti[5] = F     | Skip (diag clash) |

No valid column → **Backtrack** to row 1.

Unmark col 2: colUsed[2]=F, diagUsed[2]=F, antiDiagUsed[3]=F

**Try col = 3** → Place queen. queenCol = [0, 3, -1, -1]

Mark: colUsed[3]=T, diagUsed[1]=T, antiDiagUsed[4]=T

---

### Row 2 (queens at (0,0) and (1,3))

| col | colUsed[col] | diag[2-col+3] | antiDiag[2+col] | Result |
|-----|-------------|---------------|-----------------|--------|
| 0   | T           | —             | —               | Skip (col clash) |
| 1   | F           | diag[4] = F   | anti[3] = F     | Place  |
| 2   | F           | diag[3] = T   | anti[4] = T     | Skip   |
| 3   | T           | —             | —               | Skip   |

**Try col = 1** → Place queen. queenCol = [0, 3, 1, -1]

Mark: colUsed[1]=T, diagUsed[4]=T, antiDiagUsed[3]=T

---

### Row 3 (queens at (0,0), (1,3), (2,1))

| col | colUsed[col] | diag[3-col+3] | antiDiag[3+col] | Result |
|-----|-------------|---------------|-----------------|--------|
| 0   | T           | —             | —               | Skip   |
| 1   | T           | —             | —               | Skip   |
| 2   | F           | diag[4] = T   | anti[5] = F     | Skip (diag clash) |
| 3   | T           | —             | —               | Skip   |

No valid column → **Backtrack** to row 2.

*(Backtracking continues... eventually finds first valid solution)*

---

### First Valid Solution Found

```
. Q . .       queenCol = [1, 3, 0, 2]
. . . Q
Q . . .
. . Q .
```

### Second Valid Solution Found

```
. . Q .       queenCol = [2, 0, 3, 1]
Q . . .
. . . Q
. Q . .
```

> For N = 4, total valid configurations = **2**

---

## Time Complexity

### Recursive Tree

At each row, we try up to N columns. With N rows, the naive upper bound is **O(N^N)**.

However, with constraint pruning (column + diagonal checks), the actual branching factor reduces significantly at each level.

| N | Valid Solutions | Nodes Explored (approx) |
|---|----------------|--------------------------|
| 4 | 2              | ~10                      |
| 6 | 4              | ~200                     |
| 8 | 92             | ~2000                    |
| 10| 724            | ~70,000                  |

### Tight Bound

The actual time complexity is:

```
T(N) = O(N!)
```

**Why N! and not N^N?**

- Row 0 has N choices
- Row 1 has at most N-1 choices (one column eliminated)
- Row 2 has at most N-2 choices
- ...and so on

This gives N × (N-1) × (N-2) × ... × 1 = **N!** as the upper bound.

With diagonal pruning, the explored space is significantly less than N! in practice.

### Per-Node Cost

| Operation              | Cost |
|------------------------|------|
| Column check           | O(1) |
| Diagonal check         | O(1) |
| Anti-diagonal check    | O(1) |
| Board construction (on solution) | O(N²) |

Board construction happens only when a complete solution is found (at most N! times).

---

## Space Complexity

| Structure         | Size        | Purpose                        |
|-------------------|-------------|--------------------------------|
| `colUsed`         | O(N)        | Column conflict tracking       |
| `diagUsed`        | O(2N - 1)   | `\` diagonal conflict tracking |
| `antiDiagUsed`    | O(2N - 1)   | `/` diagonal conflict tracking |
| `queenCol`        | O(N)        | Queen placement per row        |
| Recursion stack   | O(N)        | One frame per row              |
| `ans` (output)    | O(S × N²)   | S = number of solutions        |

**Total Space = O(N) auxiliary + O(S × N²) for output**

---

## Comparison: Old vs Optimized

| Aspect              | Old Code (loop check)     | New Code (hash check)         |
|---------------------|---------------------------|-------------------------------|
| Diagonal check      | O(k) per node             | O(1) per node                 |
| Column check        | O(k) per node             | O(1) per node                 |
| Queen tracking      | `vector<vector<int>>`     | `vector<int>` (lighter)       |
| Overall time        | O(N! × N)                 | O(N!)                         |
| Auxiliary space     | O(N) queens + O(N) stack  | O(N) arrays + O(N) stack      |

---

## Summary

| Metric           | Value               |
|------------------|---------------------|
| Time Complexity  | O(N!) with pruning  |
| Space Complexity | O(N) auxiliary      |
| Conflict Check   | O(1) per cell       |
| Output Space     | O(S × N²)           |
