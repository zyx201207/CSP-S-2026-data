#include<bits/stdc++.h>

using namespace std;

int n, k, cnt;
bool vis[100], vv[100];
vector<int> g[100];

int bfs (int s)
{
    memset (vv, 0, sizeof (vv) );
    queue<int> q, d;
    q.push (s);
    d.push (0);
    while (q.size() )
    {
        int u = q.front(), dis = d.front();
        q.pop();
        d.pop();
        if (vv[u])
            continue;
        vv[u] = 1;
        for (int v : g[u])
        {
            if (vis[v])
                return dis;
            q.push (v);
            d.push (dis + 1);
        }
    }
}

void bfs2 (int s)
{
    queue<int> q;
    q.push (s);
    while (q.size() )
    {
        int u = q.front();
        q.pop();
        if (vv[u])
            continue;
        vv[u] = 1;
        for (int v : g[u])
        {
            if (vis[v])
                q.push (v);
        }
    }
}

int ans = 0x3f3f3f3f;

void dfs (int d)
{
    if (n - d + 1 <= k - cnt)
    {
        for (; d <= n; d++)
            vis[d] = 1;
        memset (vv, 0, sizeof (vv) );
        for (int i = 1; i <= n; i++)
        {
            if (!vv[i])
                bfs2 (i), cnt++;
        }
        if (cnt > 2)
            return;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i])
                continue;
            ans = min (ans, bfs (i) );
        }
        for (; d <= n; d++)
            vis[d] = 0;
        return;
    }
    if (cnt == 0)
    {
        for (; d <= n; d++)
            vis[d] = 1;
        memset (vv, 0, sizeof (vv) );
        for (int i = 1; i <= n; i++)
        {
            if (!vv[i])
                bfs2 (i), cnt++;
        }
        if (cnt > 2)
            return;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i])
                continue;
            ans = min (ans, bfs (i) );
        }
        for (; d <= n; d++)
            vis[d] = 0;
        return;
    }
    dfs (d + 1);
    vis[d] = 1;
    dfs (d + 1);
    vis[d] = 0;
}

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        g[i].clear();
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back (v);
        g[v].push_back (u);
    }
    cnt = 0;
    dfs (1);
    cout << ans << "\n";
}

int main()
{
    freopen ("hub.in", "r", stdin);
    freopen ("hub.out", "w", stdout);
    int c, T;
    cin >> c >> T;
    while (T--)
        solve();
    return 0;
}
