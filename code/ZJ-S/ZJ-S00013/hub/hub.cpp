#include <bits/stdc++.h>

using namespace std;

const int N = 1000010, M = N * 2;

int n, k;
int h[N], e[M], ne[M], idx;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

namespace sub1
{
    int dis[15][15];
    bool st[15], vis[15];
    void dfs(int u, int fa, int x, int d)
    {
        dis[x][u] = d;
        for (int i = h[u]; ~i; i = ne[i])
        {
            int j = e[i];
            if (j == fa) continue;
            dfs(j, u, x, d + 1);
        }
    }
    void dfs2(int u)
    {
        vis[u] = true;
        for (int i = h[u]; ~i; i = ne[i])
        {
            int j = e[i];
            if (st[j] && !vis[j]) dfs2(j);
        }
    }

    void solve()
    {
        for (int i = 1; i <= n; i ++ ) dfs(i, -1, i, 0);

        int res = 1e9;
        for (int i = 0; i < (1 << n); i ++ ) if (__builtin_popcount(i) == k)
        {
            for (int i = 1; i <= n; i ++ ) st[i] = vis[i] = false;
            for (int j = 0; j < n; j ++ ) if (i >> j & 1) st[j + 1] = true;
            int cnt = 0; for (int i = 1; i <= n; i ++ ) if (!vis[i] && st[i]) cnt ++ , dfs2(i);
            if (cnt > 2) continue;

            int tmp = 0;
            for (int i = 1; i <= n; i ++ ) if (!st[i])
            {
                int t = 1e9;
                for (int j = 1; j <= n; j ++ ) if (st[j]) t = min(t, dis[i][j]);
                tmp = max(tmp, t);
            }
            res = min(res, tmp);
        }
        cout << res << "\n";
    }
}

namespace sub2
{
    bool check(int x)
    {
        int m = n / 2;
        if (k == 1) return x * 2 >= m - 1;
        else return x * 4 >= m - k + 2;
    }
    void solve()
    {
        if (k == n)
        {
            cout << "0\n";
            return;
        }
        int l = 1, r = n;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        cout << l << "\n";
    }
}

int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    ios_base::sync_with_stdio(false), cin.tie(0);

    int C, T; cin >> C >> T;
    while (T -- )
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i ++ ) h[i] = -1; idx = 0;
        for (int i = 1; i < n; i ++ )
        {
            int a, b; cin >> a >> b;
            add(a, b), add(b, a);
        }
        if (C <= 3) sub1::solve();
        else if (C == 13 || C == 14) sub2::solve();
    }

    return 0;
}
