#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 24, M = 524;
int c, n, m, d, q;
int a[N];
int f[M][M];
vector<pair<int, int> > g[N];
signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    memset(f, 0x3f, sizeof(f));
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> a[i];
    for(int i = 1; i <= n; i++)
    {
        f[i][i] = 0;
        int k;
        cin >> k;
        for(int j = 1; j <= k; j++)
        {
            int u, w;
            cin >> u >> w;
            g[u].push_back({i, w});
        }
    }
    for(int i = 1; i <= m; i++)
    {
        for(auto uw : g[i])
        {
            int u = uw.first, w1 = uw.second;
            for(auto vw : g[i])
            {
                int v = vw.first, w2 = vw.second;
                if(u == v) continue;
                f[u][v] = f[v][u] = min(f[u][v], w1 + w2);
            }
        }
    }
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            if(i != k)
                for(int j = 1; j <= n; j++)
                    if(i != j && k != j)
                        f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        int ans = 1e18;
        for(auto uw : g[x])
        {
            int u = uw.first, w1 = uw.second;
            for(auto vw : g[y])
            {
                int v = vw.first, w2 = vw.second;
                ans = min(ans, f[u][v] + w1 + w2);
            }
        }
        cout << ans + a[x] + a[y] << "\n";
    }
    return 0;
}
