#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+20;
ll dp[N];

ll maxWeight(ll n, ll w, ll weight[], ll val[])
{
    if(n<0 || w==0) return 0;
    if(dp[n] != -1) return dp[n];
    if(weight[n]<= w)
    {
        ll op1 = maxWeight(n-1,w-weight[n],weight,val)+val[n];
        ll op2 = maxWeight(n-1,w,weight,val);
        return dp[n] = max(op1,op2); 
    }
    else return maxWeight(n-1,w,weight,val);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,w;
    cin>>n>>w;
    ll val[n],weight[n];
    for (int i=0;i<n;i++) cin >>val[i];       
    for (int i=0;i<n;i++) cin >>weight[i];  
    memset(dp,-1,sizeof(dp));
    cout<<maxWeight(n-1,w,weight,val)<<endl;     
    return 0;
}