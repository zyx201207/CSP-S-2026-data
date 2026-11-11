#include <iostream>
#include <vector>
#include <cstring>
#define int long long
using namespace std;
const int N = 505, M = 5005;
int c, n, m, D, q, x, y, tot, k[N], a[N][M], l[M], r[M];
int w[N], t[N][M], d[M][M];
vector<pair<int, int>> s[M];
vector<pair<int, int>> e[M];
signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> c >> n >> m >> D >> q;
    for (int i = 1; i <= m; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
        cin >> a[i][1] >> t[i][1];
        tot++;
        s[a[i][1]].push_back({tot, t[i][1]});
        for (int j = 2; j <= k[i]; j++)
        {
            cin >> a[i][j] >> t[i][j];
            tot++;
            e[tot].push_back({tot - 1, 0});
            e[tot - 1].push_back({tot, 0});
            s[a[i][j]].push_back({tot, t[i][j]});
        }
    }
                /*
    for (int i = 1; i <= tot; i++)
    {
        for (auto [v, w] : e[i])
            cout << v << ' ' << w << '\n';
        cout << '\n';
    }
*/
    for (int i = 1; i <= m; i++)
        for (auto [id1, t1] : s[i])
            for (auto [id2, t2] : s[i])
                if (id1 != id2)
                    e[id1].push_back({id2, t1 + t2});
    for (int i = 1; i <= m; i++)
    {
        l[i] = tot + 1;
        for (auto [id, t0] : s[i])
        {
            tot++;
            e[tot].push_back({id, t0});
            e[id].push_back({tot, t0});
        }
        r[i] = tot;
    }
    /*
    for (int i = 1; i <= tot; i++)
    {
        for (auto [v, w] : e[i])
            cout << v << ' ' << w << '\n';
        cout << '\n';
    }
    */
    memset(d, 0x3f, sizeof d);
    for (int i = 1; i <= tot; i++)
        d[i][i] = 0;
    for (int u = 1; u <= tot; u++)
    {
        for (auto [v, w] : e[u])
            d[u][v] = d[v][u] = w;
    }
    for (int k = 1; k <= tot; k++)
        for (int i = 1; i <= tot; i++)
            for (int j = 1; j <= tot; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    /*
    for (int i = 1; i <= tot; i++)
    {
            for (int j = 1; j <= tot; j++)
                cout << d[i][j] << ' ';
            cout << '\n';
    }
    */
    for (int i = 1; i <= q; i++)
    {
        cin >> x >> y;
        int ans = w[x] + w[y], mn = 1e18;
        for (int j = l[x]; j <= r[x]; j++)
            for (int k = l[y]; k <= r[y]; k++)
                mn = min(mn, d[j][k]);
        ans += mn;
        cout << ans << '\n';
    }
    return 0;
}
