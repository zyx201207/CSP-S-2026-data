// 43min
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int c, n, m, d, q, w[500007], k[507], dis[507][507];
vector<int> a[507], t[507], vc[500007];
unordered_map<int, int> mp[507];
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    memset(dis, 0x3f, sizeof dis);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
        a[i].resize(k[i] + 7), t[i].resize(k[i] + 7);
        for (int j = 1; j <= k[i]; j++)
            cin >> a[i][j] >> t[i][j], mp[i][a[i][j]] = j, vc[a[i][j]].push_back(i);
    }
    for (int i = 1; i <= m; i++)
        for (int x : vc[i])
            for (int y : vc[i])
                if (x != y)
                    dis[x][y] = dis[y][x] = min(dis[x][y], t[x][mp[x][i]] + t[y][mp[y][i]]);
    for (int i = 1; i <= n; i++)
            dis[i][i] = 0;
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    while (q--)
    {
        int u, v, ans = 1e18;
        cin >> u >> v;
        for (int x : vc[u])
            for (int y : vc[v])
                ans = min(ans, t[x][mp[x][u]] + dis[x][y] + t[y][mp[y][v]]);
        cout << w[u] + w[v] + ans << endl;
    }
    return 0;
}