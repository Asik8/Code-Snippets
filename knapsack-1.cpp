#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
vector <ll> v(n),w(n);
const int N=1e5+20;
int dp[N];



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (auto& x:v) cin >>x;       
        for (auto& x:w) cin >>x;       
    }
    return 0;
}