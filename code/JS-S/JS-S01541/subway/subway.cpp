#include <bits/stdc++.h>
#define int long long
#define x0 rp
#define x1 Rp
#define y0 rP
#define y1 RP
#define endl '\n'
#define pll pair <int , int>
#define LLMI (int)(-1e18)
#define LLMA (int)(1e18)
using namespace std;
const int N = 5e2 + 5, M = 5e5 + 5;
int w[M], k[N], a[N][N], t[N][M];
vector <int> ve[M];
vector <pll> g[N];
int dis[N][N];
signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i ++) cin >> w[i];
    for (int i = 1; i <= n; i ++)
    {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j ++)
        {
            cin >> a[i][j] >> t[i][a[i][j]];
            ve[a[i][j]].push_back(i);
        }
    }
    for (int x = 1; x <= n; x ++)
    {
        for (int y = 1; y <= n; y ++)
        {
            dis[x][y] = LLMA;
            if (x == y) dis[x][y] = 0;
        }
    }
    for (int i = 1; i <= m; i ++)
    {
        for (auto u : ve[i])
        {
            for (auto v : ve[i])
            {
                if (u == v) continue;
                dis[u][v] = min(dis[u][v], t[u][i] + t[v][i]);
                dis[v][u] = dis[u][v];
            }
        }
    }
    for (int z = 1; z <= n; z ++)
    {
        for (int x = 1; x <= n; x ++)
        {
            for (int y = 1; y <= n; y ++)
            {
                if (x == y) continue;
                dis[x][y] = min(dis[x][y], dis[x][z] + dis[z][y]);
            }
        }
    }
    for (int i = 1; i <= q; i ++)
    {
        int s, e;
        cin >> s >> e;
        int ans = LLMA;
        for (auto u : ve[s])
        {
            for (auto v : ve[e])
            {
                ans = min(ans, t[u][s] + t[v][e] + dis[v][u]);
            }
        }
        cout << w[s] + w[e] + ans << endl;
    }
    return 0;
}
