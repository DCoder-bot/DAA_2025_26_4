#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<string>> ans;
    vector<bool> colUsed, diagUsed, antiDiagUsed;

    void solve(vector<int> &queenCol, int row, int n) {
        if (row == n) {
            vector<string> board(n, string(n, '.'));
            for (int r = 0; r < n; r++)
                board[r][queenCol[r]] = 'Q';
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (colUsed[col] || diagUsed[row - col + n - 1] || antiDiagUsed[row + col])
                continue;

            queenCol[row] = col;
            colUsed[col] = diagUsed[row - col + n - 1] = antiDiagUsed[row + col] = true;

            solve(queenCol, row + 1, n);

            colUsed[col] = diagUsed[row - col + n - 1] = antiDiagUsed[row + col] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        colUsed.assign(n, false);
        diagUsed.assign(2 * n - 1, false);
        antiDiagUsed.assign(2 * n - 1, false);
        vector<int> queenCol(n, -1);

        solve(queenCol, 0, n);
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;

    Solution sol;
    vector<vector<string>> result = sol.solveNQueens(n);

    cout << "\nAll Valid Configurations:\n";
    for (int i = 0; i < result.size(); i++) {
        cout << "Solution " << i + 1 << ":\n";
        for (auto &row : result[i]) {
            cout << row << "\n";
        }
        cout << "\n";
    }

    cout << "Total valid configurations for N=" << n << ": " << result.size() << "\n";

    return 0;
}