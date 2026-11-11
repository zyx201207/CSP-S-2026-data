#include <bits/stdc++.h>
using namespace std;
int check(int x, int y, int l)
{
    return max(x, max((x + y) / 2 - x + 1, l - y));
}
vector <int> g[1000005];
int depth[1000005];
int fa[1000005];
int vis[1000005];
int dis[1000005];
void dfs(int point, int fa, int mask)
{
    vis[point] = 1;
    for (auto u : g[point])
    {
        if ((mask & (1 << (u - 1))) == 0 || u == fa)
            continue;
        if (!vis[u])
            dfs(u, point, mask);
    }
    return;
}
void dfs2(int point, int fax)
{
    depth[point] = depth[fax] + 1;
    fa[point] = fax;
    for (auto u : g[point])
    {
        if (u == fax)
            continue;
        if (depth[u] == 0)
            dfs2(u, point);
    }
    return;
}
int get_lca(int x, int y)
{
    if (depth[x] > depth[y])
        swap(x, y);
    while (depth[x] != depth[y])
        y = fa[y];
    while (x != y)
    {
        x = fa[x];
        y = fa[y];
    }
    return x;
}
int n, k;
int check2(int mask)
{
    dfs2(1, 0);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        vis[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        if ((mask & (1 << (i - 1))) && (!vis[i]))
        {
            cnt++;
            dfs(i, 0, mask);
        }
    }
    if (cnt > 2)
        return 0x3f3f3f3f;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        dis[i] = 0x3f3f3f3f;
        for (int j = 1; j <= n; j++)
        {
            if ((mask & (1 << (j - 1))))
                dis[i] = min(dis[i], depth[j] + depth[i] - depth[get_lca(i, j)] * 2);
        }
        ans = max(ans, dis[i]);
    }
    return ans;
}
int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    if (1 <= c && c <= 3)
    {
        while (t--)
        {
            cin >> n >> k;
            int ans = n;
            for (int i = 1; i <= n; i++)
            {
                depth[i] = 0;
                g[i].clear();
                fa[i] = 0;
            }
            for (int i = 1; i <= n - 1; i++)
            {
                int u, v;
                cin >> u >> v;
                g[u].push_back(v);
                g[v].push_back(u);
            }
            for (int i = 1; i < (1 << n); i++)
            {
                int cnt = 0;
                for (int j = 0; j < n; j++)
                {
                    if (i & (1 << j))
                        cnt++;
                }
                if (cnt != k)
                    continue;
                ans = min(ans, check2(i));
            }
            cout << ans << endl;
        }
    }
    if (13 <= c && c <= 14)
    {
        while (t--)
        {
            int n, k;
            cin >> n >> k;
            for (int i = 1; i <= n - 1; i++)
            {
                int x, y;
                cin >> x >> y;
            }
            int l = (n + 1) / 2;
            if (k == 1)
                cout << (((n + 3) / 2 - k) % 2 == 0 ? ((n + 3) / 2 - k) / 2 : ((n + 3) / 2 - k) / 2 + 1) << endl;
            else
            {
                int ans = 2000000;
                for (int i = -4; i <= 4; i++)
                {
                    for (int j = -4; j <= 4; j++)
                    ans = min(ans, check(l / 4 + i,  l / 4 * 3 + j, l));
                }
                cout << ans - k / 4 << endl;
            }
        }
    }
    return 0;
}
