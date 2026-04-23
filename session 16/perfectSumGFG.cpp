class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        for(int i =0;i<=n;i++) dp[i][0] = 1;
         for(int i = 1; i <= n; i++) {
            for(int s = 0; s <= target; s++) {
                
                if(arr[i-1] <= s) {
                    dp[i][s] = dp[i-1][s] + dp[i-1][s - arr[i-1]];
                } 
                else {
                    dp[i][s] = dp[i-1][s];
                }
            }
        }
        return dp[n][target];
    }
};