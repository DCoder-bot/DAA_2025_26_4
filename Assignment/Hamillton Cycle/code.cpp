#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> graph;
    vector<int> path;
    vector<bool> visited;

    bool isSafe(int v, int pos) {
        if (!graph[path[pos - 1]][v])
            return false;
        if (visited[v])
            return false;
        return true;
    }

    bool solve(int pos) {
        if (pos == n) {
            return graph[path[pos - 1]][path[0]] == 1;
        }

        for (int v = 1; v < n; v++) {
            if (isSafe(v, pos)) {
                path[pos] = v;
                visited[v] = true;

                if (solve(pos + 1))
                    return true;

                path[pos] = -1;
                visited[v] = false;
            }
        }
        return false;
    }

    bool hamiltonianCycle(vector<vector<int>> &adj) {
        n = adj.size();
        graph = adj;
        path.assign(n, -1);
        visited.assign(n, false);

        path[0] = 0;
        visited[0] = true;

        if (!solve(1)) {
            cout << "No Hamiltonian Cycle exists.\n";
            return false;
        }

        cout << "Hamiltonian Cycle found:\n";
        for (int i = 0; i < n; i++)
            cout << path[i] << " -> ";
        cout << path[0] << "\n";
        return true;
    }
};

int main() {
    int n ;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> adj(n, vector<int>(n, 0));

    cout << "Enter adjacency matrix (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];

    Solution sol;
    sol.hamiltonianCycle(adj);

    return 0;
}