#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, s=0;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++) 
    {
        cin>>a[i];
        s+=a[i];
    }
    bool dp[n+1][s+1];
    dp[0][0] = true;
    for(int i=1;i<=s;i++) dp[0][i] = false;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=s;j++)
        {
            if(a[i-1]<=j) dp[i][j] = dp[i-1][j-a[i-1]] || dp[i-1][j];
            else dp[i][j] = dp[i-1][j]; 
        }
    }
    ll ans = INT_MAX;
    for(int j=0;j<=s/2;j++) 
    {
        if(dp[n][j])
        {
            ans = min(ans,(llabs(j-(s-j))));
        }
    }
    cout<<ans<<endl;
    return 0;
}