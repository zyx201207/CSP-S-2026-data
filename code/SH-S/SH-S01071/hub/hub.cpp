// 15pts
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 7;
int c, t, n, k, vis[N], dis[N];
vector<int> g[N];
void dfs2(int u, int x)
{
    vis[u] = 1;
    for (int v : g[u])
        if ((x >> v) & 1 && !vis[v])
            dfs2(v, x);
}
bool check(int x)
{
    int ct = 0;
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= n; i++)
        if ((x >> i) & 1 && !vis[i])
            dfs2(i, x), ct++;
    return ct <= 2;
}
void dfs3(int u, int lst)
{
    for (int v : g[u])
        if (v != lst && dis[u] + 1 < dis[v])
            dis[v] = dis[u] + 1, dfs3(v, u);
}
int calc(int x)
{
    memset(dis, 0x3f, sizeof dis);
    for (int i = 1; i <= n; i++)
        if ((x >> i) & 1)
            dis[i] = 0, dfs3(i, 0);
    int res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, dis[i]);
    return res;
}
int dfs(int id, int ct, int mask)
{
    if (ct == k)
    {
        if (check(mask))
            return calc(mask);
        return 1e18;
    }
    if (id > n)
        return 1e18;
    return min(dfs(id + 1, ct, mask), dfs(id + 1, ct + 1, mask | (1 << id)));
}
void solve1() { cout << dfs(1, 0, 0) << endl; }
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            g[i].clear();
        for (int i = 1, u, v; i < n; i++)
            cin >> u >> v, g[u].push_back(v), g[v].push_back(u);
        solve1();
    }
    return 0;
}