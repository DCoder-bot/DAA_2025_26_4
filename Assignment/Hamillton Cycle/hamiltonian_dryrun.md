# Hamiltonian Cycle: Dry Run

---

## Input Graph (N = 5)

### Adjacency Matrix

```
    0  1  2  3  4
0 [ 0  1  0  1  0 ]
1 [ 1  0  1  1  1 ]
2 [ 0  1  0  0  1 ]
3 [ 1  1  0  0  1 ]
4 [ 0  1  1  1  0 ]
```

### Edge List

```
0 -- 1
0 -- 3
1 -- 2
1 -- 3
1 -- 4
2 -- 4
3 -- 4
```

---

## Initial State

```
path    = [0, -1, -1, -1, -1]
visited = [T,  F,  F,  F,  F]
Start vertex fixed at 0, call solve(pos = 1)
```

---

## Trace

---

### solve(pos = 1)

Try vertices v = 1 to 4 for position 1.

| v | graph[path[0]][v] = graph[0][v] | visited[v] | isSafe? |
|---|----------------------------------|------------|---------|
| 1 | graph[0][1] = 1                  | F          | YES     |

**Place v = 1 at pos 1**

```
path    = [0, 1, -1, -1, -1]
visited = [T, T,  F,  F,  F]
```

---

### solve(pos = 2)

Try vertices v = 1 to 4 for position 2.

| v | graph[path[1]][v] = graph[1][v] | visited[v] | isSafe? |
|---|----------------------------------|------------|---------|
| 1 | graph[1][1] = 0                  | —          | NO (no edge) |
| 2 | graph[1][2] = 1                  | F          | YES     |

**Place v = 2 at pos 2**

```
path    = [0, 1, 2, -1, -1]
visited = [T, T, T,  F,  F]
```

---

### solve(pos = 3)

Try vertices v = 1 to 4 for position 3.

| v | graph[path[2]][v] = graph[2][v] | visited[v] | isSafe? |
|---|----------------------------------|------------|---------|
| 1 | graph[2][1] = 1                  | T          | NO (visited) |
| 2 | graph[2][2] = 0                  | —          | NO (no edge) |
| 3 | graph[2][3] = 0                  | —          | NO (no edge) |
| 4 | graph[2][4] = 1                  | F          | YES     |

**Place v = 4 at pos 3**

```
path    = [0, 1, 2, 4, -1]
visited = [T, T, T, F,  T]
```

---

### solve(pos = 4)

Try vertices v = 1 to 4 for position 4.

| v | graph[path[3]][v] = graph[4][v] | visited[v] | isSafe? |
|---|----------------------------------|------------|---------|
| 1 | graph[4][1] = 1                  | T          | NO (visited) |
| 2 | graph[4][2] = 1                  | T          | NO (visited) |
| 3 | graph[4][3] = 1                  | F          | YES     |

**Place v = 3 at pos 4**

```
path    = [0, 1, 2, 4, 3]
visited = [T, T, T, T, T]
```

---

### solve(pos = 5) — Base Case

```
pos == n (5 == 5)
Check closing edge: graph[path[4]][path[0]] = graph[3][0] = 1
```

**Closing edge exists → Hamiltonian Cycle found!**

---

## Final Path

```
path = [0, 1, 2, 4, 3]
```

```
0 -> 1 -> 2 -> 4 -> 3 -> 0
```

---

## Step-by-Step Summary Table

| Step | pos | v placed | path                  | visited           | Action              |
|------|-----|----------|-----------------------|-------------------|---------------------|
| 1    | 1   | 1        | [0, 1, -1, -1, -1]   | [T,T,F,F,F]       | Place               |
| 2    | 2   | 2        | [0, 1, 2, -1, -1]    | [T,T,T,F,F]       | Place               |
| 3    | 3   | 4        | [0, 1, 2, 4, -1]     | [T,T,T,F,T]       | Place               |
| 4    | 4   | 3        | [0, 1, 2, 4, 3]      | [T,T,T,T,T]       | Place               |
| 5    | 5   | —        | [0, 1, 2, 4, 3]      | [T,T,T,T,T]       | Base case: cycle closed |

---

## Backtracking Scenario (when no path works)

If at any `pos` no vertex passes `isSafe()`:

```
path[pos] = -1
visited[v] = false
return false to previous call
```

The previous call then tries its next candidate vertex.
If all vertices at pos = 1 are exhausted without success,
solve() returns false and "No Hamiltonian Cycle exists." is printed.

---

## Time & Space Complexity

| Metric          | Value                                      |
|-----------------|--------------------------------------------|
| Time Complexity | O(N!) — at each position, up to N-1 choices|
| Space (path)    | O(N)                                       |
| Space (visited) | O(N)                                       |
| Space (graph)   | O(N²) — adjacency matrix                   |
| Recursion Stack | O(N)                                       |
| Total Space     | O(N²)                                      |
