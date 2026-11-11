#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 10;
int c, t, n, k, color[N], cnt, ans = 1e9;
vector <int> g[N];
bool vis[N];
void dfs(int x)
{
    color[x] = cnt;
    for (auto v : g[x])
    {
        if (color[v] == 0 && vis[v])
            dfs(v);
    }
}
bool check()
{
    memset(color, 0, sizeof color);
    cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] && color[i] == 0)
        {
            cnt++;
            dfs(i);
        }
        if (cnt >= 3)
            return 0;
    }
    if (cnt >= 3)
        return 0;
    return 1;
}
int dis(int x, int fa)
{
    if (vis[x])
        return 0;
    int res = 1e9;
    for (auto v : g[x])
    {
        if (v == fa)
            continue;
        res = min(res, dis(v, x) + 1);
    }
    return res;
}
void dfs(int x, int cnt)
{
    if (x == n + 1)
    {
        if (cnt != 0)
            return;
        if (!check())
            return;
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
                res = max(res, dis(i, 0));
        }
        ans = min(res, ans);
        return;
    }
    if (cnt > 0)
    {
        vis[x] = 1;
        dfs(x + 1, cnt - 1);
    }
    if (n - x >= cnt)
    {
        vis[x] = 0;
        dfs(x + 1, cnt);
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            g[i].clear();
        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        ans = 1e9;
        dfs(1, k);
        cout << ans << "\n";
    }
}