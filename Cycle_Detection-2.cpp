#include <bits/stdc++.h>
using namespace std;
#define py cout<<"YES\n";
#define pn cout<<"NO\n";
const int N = 1e5 + 5;
bool vis[N];
vector<int> v[N];
int par[N];
bool f;
void dfs(int p)
{
    vis[p] = true;
    for (int child : v[p])
    {
        if (vis[child] && child != par[p]) f = true;
        if (!vis[child])
        {
            par[child] = p;
            dfs(child);
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    memset(par, -1, sizeof(par));
    f = false;
    for (int i = 0; i < n; i++)
        if (!vis[i]) dfs(i);
    if (f) py
    else pn
    return 0;
}