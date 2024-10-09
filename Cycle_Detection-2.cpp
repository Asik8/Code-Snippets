#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
bool vis[N];
vector<int> v[N];
int parent[N];
bool f;
void dfs(int p)
{
    vis[p] = true;
    for (int child : v[p])
    {
        if (vis[child] && child != parent[p])
        {
            f = true;
        }
        if (!vis[child])
        {
            parent[child] = p;
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
    memset(parent, -1, sizeof(parent));
    f = false;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    if (f)
        cout << "Cycle detected";
    else
        cout << "Cycle not detected";
    return 0;
}