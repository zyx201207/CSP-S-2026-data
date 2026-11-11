#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int n, m, a[N], mx = -1;
bool vis[N];
void dfs (int step,  int now)
{
    if (step == m)
    {
        mx = max (mx, now);
        return ;
    }
    for (int i = 1; i <= n; ++ i)
    {
        if (!vis[i])
        {
            vis[i] = true;
            if (!now)
                dfs (step + 1, a[i]);
            else
                dfs (step + 1, now & a[i]);
            vis[i] = false;
        }
    }
    return ;
}
int main ()
{
    freopen ("and.in", "r", stdin);
    freopen ("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i)
    {
        cin >> a[i];
        mx = max (mx, a[i]);
    }
    if (m == 1)
    {
        cout << mx;
        return 0;
    }
    if (m == 2)
    {
        mx = -1;
        for (int i = 1; i <= n; ++ i)
        {
            for (int j = i + 1; j <= n; ++ j)
            {
                mx = max (mx, a[i] & a[j]);
            }
        }
        cout << mx;
        return 0;
    }
    if (m == n)
    {
        int k = a[1];
        for (int i = 2; i <= n; ++ i)
            k &= a[i];
        cout << k;
        return 0;
    }
    mx = -1;
    dfs (0, 0);
    cout << mx;
    return 0;
}
