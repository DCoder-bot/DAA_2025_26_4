#include<iostream>
using namespace std;
#include <vector>
class Solution {
public:
    bool check(vector<vector<char>>& board, vector<vector<bool>>& visited, string& word, int i, int j, int b) {
        if(b == word.size()){
            return true;
        }
        if(i<0|| j< 0||i>=board.size()|| j>=board[0].size() || board[i][j]!= word[b] || visited[i][j]){
            return false;
        }
        visited[i][j] = true;

        if(check(board,visited,word,i+1,j,b+1)) {
            visited[i][j] = false;   
            return true;
        }

        if(check(board,visited,word,i-1,j,b+1)) {
            visited[i][j] = false;
            return true;
        }

        if(check(board,visited,word,i,j+1,b+1)) {
            visited[i][j] = false;
            return true;
        }

        if(check(board,visited,word,i,j-1,b+1)) {
            visited[i][j] = false;
            return true;
        }

        visited[i][j] = false;
        return false;

    }   
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n,false));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(check(board, visited, word, i, j, 0))
                    return true;
            }
        }

        return false;

    }
};