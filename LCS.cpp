#include <bits/stdc++.h>
using namespace std;
#define ll long long

int dp[1005][1005];

int LCS(string a,int n,string b,int m){
    if(n==-1 || m == -1) return 0;
    if(dp[n][m] != -1) return dp[n][m];
    if(a[n] == a[m]){
        int ans = LCS(a,n-1,b,m-1);
        return dp[n][m] = ans+1;
    }
    else{
        ll ans1 = LCS(a,n-1,b,m);
        ll ans2 = LCS(a,n,b,m-1);
        return max(ans1,ans2);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string a,b;
    cin>>a>>b;
    memset(dp,-1,sizeof(dp));
    cout<<LCS(a,a.size()-1,b,b.size()-1)-1<<endl;
    return 0;
}