#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 510;
const int MAXM = 5e5 + 10;
int w[MAXM];
vector<pair<int, int>> p[MAXM];
ll f[MAXN][MAXN];
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; ++i) cin >> w[i];
    for(int i = 1, k, u, t; i <= n; ++i)
    {
        cin >> k;
        while (k--)
        {
            cin >> u >> t;
            p[u].push_back({i, t});
        }
    }
    memset(f, 0x3f, sizeof f);
    for(int i = 1; i <= n; ++i) f[i][i] = 0;
    for(int i = 1; i <= m; ++i)
    {
        for(int x = 0; x < p[i].size(); ++x)
        {
            for(int y = x + 1; y < p[i].size(); ++y)
            {
                f[p[i][x].first][p[i][y].first] = min(f[p[i][x].first][p[i][y].first], 0ll + p[i][x].second + p[i][y].second);
                f[p[i][y].first][p[i][x].first] = min(f[p[i][x].first][p[i][y].first], 0ll + p[i][x].second + p[i][y].second);
            }
        }
    }
    for(int k = 1; k <= n; ++k)
    {
        for(int u = 1; u <= n; ++u)
        {
            for(int v = 1; v <= n; ++v)
            {
                f[u][v] = min(f[u][v], f[u][k] + f[v][k]);
            }
        }
    }
    int x, y;
    while (q--)
    {
        cin >> x >> y;
        ll ans = inf;
        for(auto u : p[x])
        {
            for(auto v : p[y])
            {
                ans = min(ans, f[u.first][v.first] + u.second + v.second);
            }
        }
        cout << ans + w[x] + w[y] << '\n';
    }
    return 0;
}