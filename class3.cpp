#include<iostream>
#include<vector>
using namespace std;

int solveUsingRecursion(int n, int k){
    // base case
    if(n==1) return k;

    if(n==2) return (k+k*(k-1));


    int ans = (solveUsingRecursion(n-1, k) + solveUsingRecursion(n-2, k))*(k-1);

    return ans;
}

int solveUsingMem(int n, int k, vector<int>&dp){
    // base case

    if(n==1) return k;
    if(n==2) return (k+k*(k-1));

    // already exists
    if(dp[n] != -1) return dp[n];

    dp[n] = (solveUsingMem(n-1, k, dp)+solveUsingMem(n-2, k, dp))*(k-1);

    return dp[n];
}

int solveUsingTabulation(int n, int k){
    // vector<int> dp(n+1, -1);
    // dp[1] = k;
    // dp[2] = (k + k*(k-1));

    // for(int i=3; i<=n; i++){
    //     dp[i] = (dp[i-1]+dp[n-2])*(k-1);
    // }
    // return dp[n];

    int prev2 = k;
    int prev1 = (k+k*(k-1))*(k-1);
    int curr = 0;
    for(int i=3; i<=n; i++){
        curr = (prev2+prev1)*(k-1);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main(){
    int n = 5;
    int k=3;

    vector<int> dp(n+1, -1);

    // int ans = solveUsingMem(n, k, dp);
    int ans = solveUsingTabulation(n,k);
    cout<<ans;

    return 0;
}