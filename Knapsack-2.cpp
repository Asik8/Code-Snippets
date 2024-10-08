#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define py cout<<"YES\n";
#define pn cout<<"NO\n";
ll dp[1005][1005];

bool SubsetSum(ll n, ll a[], ll s)
{
    if(n<0)
    {
        if(s==0) return true;
        else return false;
    }
    if(dp[n][s] != -1) return dp[n][s];
    if(a[n]<=s)
    {
        bool op1 = SubsetSum(n-1,a,s-a[n]);
        bool op2 = SubsetSum(n-1,a,s);
        return dp[n][s] = op1 || op2;
    }
    else return dp[n][s] = SubsetSum(n-1,a,s);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll a[n];
    for (int i=0;i<n;i++) cin >>a[i]; 
    ll s;
    cin>>s;   
    memset(dp,-1,sizeof(dp)); 
    if(SubsetSum(n-1,a,s)) py
    else pn
    return 0;
}