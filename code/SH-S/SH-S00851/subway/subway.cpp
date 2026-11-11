#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505;
const int M = 5e5 + 10;
int c, n, m, d, q, w[M], dis[N][N];
bool vis[N];
struct Node
{
    int v, w;
};
struct Point
{
    int u, d;
    bool operator<(const Point &rhs) const
    {
        return d < rhs.d;
    }
};

vector<Node> f[M];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dis[i][j] = 1e18;
    for (int i = 1; i <= n; i++)
        dis[i][i] = 0;
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            int a, t;
            cin >> a >> t;
            f[a].push_back({i, t});
            for (auto v : f[a])
            {
                dis[i][v.v] = min(v.w + t, dis[i][v.v]);
                dis[v.v][i] = min(v.w + t, dis[v.v][i]);
            }
        }
    }
    for  (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    while (q--)
    {
        int s, t, ans = 1e18;
        cin >> s >> t;
        for (auto u : f[s])
            for (auto v : f[t])
                ans = min(ans, dis[u.v][v.v] + u.w + v.w);
        cout << ans + w[s] + w[t] << "\n";
    }
}