class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        unordered_map<long long, int> mp;
        long long prefix = 0;
        int maxLen = 0;

        for(int i = 0; i < arr.size(); i++) {
            prefix += arr[i];
            if(prefix == k) maxLen = i + 1;
        
        if(mp.find(prefix - k) != mp.end()) {
            maxLen = max(maxLen, i - mp[prefix - k]);
        }
        if(mp.find(prefix) == mp.end()) {
            mp[prefix] = i;
        }
    }
    return maxLen;
    }
};