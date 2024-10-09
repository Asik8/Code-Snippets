#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define py cout<<"YES\n";
#define pn cout<<"NO\n";
ll dp[1005][1005];

bool find_Sum(ll n,ll a[] , ll s)
{
    if(n<0)
    {
        if (s==0) return true;
        else return false;
    }
    if(dp[n][s] != -1) return dp[n][s];
    if(a[n]<=s)
    {
        bool op1 = find_Sum(n-1,a,s-a[n]);
        bool op2 = find_Sum(n-1,a,s);
        return dp[n][s] = op1||op2;
    }
    else return dp[n][s] = find_Sum(n-1,a,s);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,s=0;
    cin>>n;
    ll a[n];
    for (int i=0;i<n;i++)
    {
        cin >>a[i]; 
        s+=a[i];
    }
    if(s%2) pn
    else
    {
        memset(dp,-1,sizeof(dp));
        if(find_Sum(n-1,a,s/2)) py
        else pn
    }
    return 0;
}