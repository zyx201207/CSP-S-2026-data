#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 510, M = 500010;

int n, m, d, q;
int val[M];
vector<PII> G[M];
LL g[N][N];

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios_base::sync_with_stdio(false), cin.tie(0);

    int C;
    cin >> C >> n >> m >> d >> q;
    for (int i = 1; i <= m; i ++ ) cin >> val[i];
    memset(g, 0x3f, sizeof g); for (int i = 1; i <= n; i ++ ) g[i][i] = 0;
    for (int i = 1; i <= n; i ++ )
    {
        int k; cin >> k;
        while (k -- )
        {
            int a, b; cin >> a >> b;
            G[a].push_back({i, b});
        }
    }

    for (int i = 1; i <= m; i ++ )
        for (auto [x, y] : G[i])
            for (auto [a, b] : G[i]) if (x != a)
            {
                g[a][x] = g[x][a] = min(g[a][x], (LL)y + b);
            }

    for (int k = 1; k <= n; k ++ )
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= n; j ++ )
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

    while (q -- )
    {
        int u, v; cin >> u >> v;
        LL res = 1e18;
        for (auto [x, y] : G[u])
            for (auto [a, b] : G[v])
            {
                res = min(res, y + b + g[x][a]);
            }
        cout << res + val[u] + val[v] << "\n";
    }

    return 0;
}
