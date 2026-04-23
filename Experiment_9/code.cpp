class Solution {
  public:
    int minDifference(vector<int>& arr) {
        int n = arr.size();
        int total = 0;
        for(int x : arr) total += x;
        int target = total / 2;
        
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        
        for(int num : arr)
            for(int j = target; j >= num; j--)
                if(dp[j - num])
                    dp[j] = true;
        
        for(int s1 = target; s1 >= 0; s1--)
            if(dp[s1])
                return abs((total - s1) - s1);
        
        return total;
    }
};