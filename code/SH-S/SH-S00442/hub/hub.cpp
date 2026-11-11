#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 9;
int n, k, h[N], ne[N << 1], e[N << 1], idx;
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int depth[N], f[N], dp[N], d[N], rt, maxdepth[N], maxd, sz[N], ans, maxl[N], maxll[N][2], jump[N][20];
void dfs1(int u, int fa)
{
    jump[u][0] = fa;
    for (int i = 1; i <= 17; i++)
        jump[u][i] = jump[jump[u][i - 1]][i - 1];
    depth[u] = depth[fa] + 1;
    maxdepth[u] = depth[u];
    for (int i = h[u]; ~i; i = ne[i])
    {
        int v = e[i];
        if (v == fa)
            continue;
        dfs1(v, u);
        int len = maxdepth[v] - depth[u];
        if (len >= maxll[u][0])
        {
            maxll[u][1] = maxll[u][0];
            maxll[u][0] = len;
        }
        else
            maxll[u][1] = max(maxll[u][1], len);
        maxdepth[u] = max(maxdepth[v], maxdepth[u]);
    }
}
void dfs3(int u, int fa)
{
    for (int i = h[u]; ~i; i = ne[i])
    {
        int v = e[i];
        if (v == fa)
            continue;
        maxl[v] = maxl[u] + 1;
        int len = maxll[u][0];
        if (len == 1 + maxdepth[v] - depth[v])
            len = maxll[u][1];
        maxl[v] = max(maxl[v], 1 + len);
        dfs3(v, u);
    }
}
void dfs(int u, int fa)
{
    dp[u] = 0;
    d[u] = 0;
    if (maxdepth[u] - depth[u] < maxd)
        return;
    sz[u] = 1;
    d[u] = -1;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int v = e[i];
        if (v == fa)
            continue;
        dfs(v, u);
        if (!d[v])
            d[u] = u;
        dp[u] += dp[v];
        if (d[u] == -1)
            d[u] = d[v];
        else
            d[u] = u;
        sz[u] += sz[v];
    }
    if (d[u] == u)
        dp[u] = sz[u];
}
void dfs2(int u, int fa)
{
    f[u] = 0;
    if (maxdepth[u] - depth[u] < maxd)
        return;
    f[u] = sz[u];
    int cnt = 0;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int v = e[i];
        if (v == fa)
            continue;
        dfs2(v, u);
        if (!d[v])
            continue;
        cnt++;
        int vv = d[v];
        int ss = depth[vv] - depth[v] - 2 * maxd;
        if (ss > 0)
        {
            for (int j = 17; j >= 0; j--)
                if (ss >> j & 1)
                    vv = jump[vv][j];
        }
        if (vv)
            f[u] = min(f[u], sz[u] - sz[v] + sz[vv]);
        f[u] = min(f[u], sz[u] - sz[v] + f[v]);
    }
    if (maxl[u] <= maxd)
        ans = min(ans, f[u]);
    if (cnt != 2 || maxl[u] >= maxd)
        return;
    int son[2];
    for (int i = h[u]; ~i; i = ne[i])
    {
        int v = e[i];
        if (v == fa)
            continue;
        son[--cnt] = v;
    }
    int res = maxd - maxl[u];
    int cur = dp[son[0]] + dp[son[1]];
    int dist[2] = {depth[d[son[0]]] - depth[u], depth[d[son[1]]] - depth[u]};
    if (dist[0] > maxd + 1)
    {
        cur += dist[0] - maxd - 1;
        dist[0] = maxd + 1;
    }
    if (dist[1] > maxd + 1)
    {
        cur += dist[1] - maxd - 1;
        dist[1] = maxd + 1;
    }
    cur += max(min(dist[0], dist[1]) - res, 0);
    ans = min(ans, cur);
}
bool check()
{
    if (maxdepth[rt] - depth[rt] <= maxd)
        return true;
    dfs(rt, 0);
    ans = n;
    dfs2(rt, 0);
    return ans <= k;
}
int dist[19][19];
void solve()
{
    maxll[0][0] = maxll[0][1] = -1;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 17; j++)
            jump[i][j] = 0;
        maxll[i][0] = maxll[i][1] = 0;
        dp[i] = 0;
        maxdepth[i] = 0;
        depth[i] = 0;
        h[i] = -1;
        f[i] = 0;
        sz[i] = 0;
        d[i] = 0;
    }
    rt = idx = 0;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
        d[u]++;
        d[v]++;
    }
    if (n <= 10)
    {
        memset(dist, 0x3f, sizeof(dist));
        for (int i = 1; i <= n; i++)
            dist[i][i] = 0;
        for (int i = 0; i < idx; i++)
            dist[e[i]][e[i ^ 1]] = 1;
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        int ans = n;
        for (int i = 1; i < 1 << n; i++)
        {
            if (__builtin_popcount(i) > k)
                continue;
            int cnt = __builtin_popcount(i);
            for (int j = 0; j < idx; j += 2)
            {
                int u = e[j], v = e[j ^ 1];
                if ((i >> (u - 1) & 1) && (i >> (v - 1) & 1))
                    cnt--;
            }
            if (cnt > 2)
                continue;
            int cur = 0;
            for (int j = 1; j <= n; j++)
            {
                int ss = n;
                for (int k = 1; k <= n; k++)
                    if (i >> (k - 1) & 1)
                        ss = min(ss, dist[j][k]);
                cur = max(cur, ss);
            }
            ans = min(ans, cur);
        }
        printf("%d\n", ans);
        return;
    }
    if (n == k)
    {
        printf("0\n");
        return;
    }
    for (int i = 1; i <= n; i++)
        if (d[i] == 1)
            rt = i;
    dfs1(rt, 0);
    maxl[rt] = 0;
    dfs3(rt, 0);
    int l = 1, r = n - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        maxd = mid;
        if (check())
            r = mid - 1;
        else
            l = mid + 1;
    }
    printf("%d\n", l);
}
int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, t;
    scanf("%d%d", &c, &t);
    while (t--)
        solve();
}
