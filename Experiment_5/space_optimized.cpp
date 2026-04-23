// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;

int main() {
    int n = 4;
    int arr[n] = {2,3,5,6};
    int sum = 5;
    
    vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
    for(int i = 0;i<=n;i++)dp[i][0] = 1;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=sum;j++){
            if(arr[i-1]<=j){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<dp[n][sum];
    
    
    return 0;
}