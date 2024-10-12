#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n, e;
    cin >> n >> e;
    ll a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = INT_MAX;
            if (i == j) a[i][j] = 0;
        }
    }
    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        a[u][v] = c;
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][k] + a[k][j] < a[i][j])
                {
                    a[i][j] = a[i][k] + a[k][j];
                }
            }
        }
    }

    // Needed to detect Negative Cycle
    // for (int i = 0; i < n; i++)
    // {
    //     if (a[i][i] < 0)
    //     {
    //         cout << "Cycle detected" << endl;
    //         break;
    //     }
    // }
    return 0;
}