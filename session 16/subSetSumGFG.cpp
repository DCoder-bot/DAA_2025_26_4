class Solution {
  public:
  bool solve(vector<int> &arr, int i, int sum, int curr,bool &check){
      if(check) return true;
      if(sum == curr) {check = true; return true;}
      if(i>=arr.size()) return false;
      if(sum<curr) return false;
      solve(arr,i+1,sum,curr+arr[i],check);
      solve(arr,i+1,sum,curr,check);
  }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        bool check = false;
     solve(arr,0,sum,0,check);
     return check;
    }
};