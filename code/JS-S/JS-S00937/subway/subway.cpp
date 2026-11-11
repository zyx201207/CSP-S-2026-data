#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

#define int long long

using namespace std;
constexpr int INF = 100000000000000000LL;

struct edge
{
    int v, w;
};

signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    vector<int> w(m + 1);
    for (int i = 1; i <= m; ++i)
        cin >> w[i];
    vector<vector<edge>> g(m + 1);
    for (int i = 1; i <= n; ++i)
    {
        int k;
        cin >> k;
        for (int j = 1; j <= k; ++j)
        {
            int a, t;
            cin >> a >> t;
            g[a].push_back({i, t});
        }
    }
    vector<vector<int>> dis(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; ++i)
        dis[i][i] = 0;
    for (int i = 1; i <= m; ++i)
    {
        int sz = g[i].size();
        for (int j = 0; j < sz; ++j)
        {
            for (int k = j + 1; k < sz; ++k)
            {
                int u = g[i][j].v;
                int v = g[i][k].v;
                int nd = min(dis[u][v], g[i][j].w + g[i][k].w);
                dis[u][v] = dis[v][u] = nd;
            }
        }
    }
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    for (int i = 1; i <= q; ++i)
    {
        int x, y;
        cin >> x >> y;
        int ans = INF;
        for (auto &&j : g[x])
        {
            for (auto &&k : g[y])
            {
                ans = min(ans, dis[j.v][k.v] + j.w + k.w + w[x] + w[y]);
            }
        }
        cout << ans << "\n";
    }
}

// xie wan zhe ti ba di yi ti chong xin bian yi yi xia