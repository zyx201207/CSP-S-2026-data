#include <bits/stdc++.h>
using namespace std;

struct node { int v, w; };
const int N = 5e5 + 5, M = 1e3 + 5;
int w[N], k[N], a[M][M];
int c, n, m, d, q;
int x, y;
int ans = 1e9;
bool vis[N];
vector<node> g[N];

void dfs(int u, int d)
{
    if (u == y)
    {
        ans = min(ans, d);
        return;
    }
    for (node sy : g[u])
    {
        if (vis[sy.v] || u == sy.v) continue;
        vis[sy.v] = true;
        dfs(sy.v, d + sy.w);
        vis[sy.v] = false;
    }
    return;
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++)
        {
            cin >> x >> y;
            a[i][x] = y;
            for (int k = 1; k <= m; k++)
            {
                if (a[i][k] == 0 || j == k) continue;
                int dis = a[i][k] + a[i][x];
                g[j].push_back({k, dis});
                g[k].push_back({j, dis});
            }
        }
    }
    while (q--)
    {
        cin >> x >> y;
        memset(vis, false, sizeof(vis));
        dfs(x, 0);
        cout << ans + w[x] + w[y] << "\n";
    }
    return 0;
}
