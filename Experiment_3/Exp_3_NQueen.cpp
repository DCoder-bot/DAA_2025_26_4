// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool solve(vector<vector<int>> &queens, vector<bool> &colused, int row, int n) {
    if (row == n) {
        return true;
    }

    for (int col = 0; col < n; col++) {
        if (colused[col]) {
            continue;
        }

        bool safestate = true;
        for (auto &q : queens) {
            if (abs(row - q[0]) == abs(col - q[1])) {
                safestate = false;
                break;
            }
        }
        if (!safestate) continue;

        queens.push_back({row, col});
        colused[col] = true;

        if (solve(queens, colused, row + 1, n)) {
            return true;
        }

        queens.pop_back();
        colused[col] = false;
    }

    return false;   
}

int main() {
    int n = 10;
    vector<vector<int>> queens;
    vector<bool> colused(n, false);

    solve(queens, colused, 0, n);

    for (auto &q : queens) {
        cout << "{" << q[0] << "," << q[1] << "}" << endl;
    }

    return 0;
}
