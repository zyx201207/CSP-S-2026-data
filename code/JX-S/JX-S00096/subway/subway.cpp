#include <bits/stdc++.h>

using namespace std;
#define int long long
struct node
{
    int v, w;
};
vector<node> g[500010];
int w[500010], k[510], a[510][50010], t[510][20010], vis[510][20010], ef[500010][2], vis1[5000010], d[500010], c, n, m, dd, q;
void dijkstra(int s)
{
    memset(d, 0x3f, sizeof(d));
    memset(vis, false, sizeof(vis));
    priority_queue<pair<int, int> > q;
    q.push({0, s}), d[s] = 0;
    while (!q.empty())
    {
        int x = q.top().second;
      //  cout << x << " " << x / m << " " << x % m << " " << -q.top().first << endl;
        q.pop();
        if (vis1[x]) continue;
        vis1[x] = true;
        for (int i = 0; i < g[x].size(); ++i)
        {
            if (d[g[x][i].v] > d[x] + g[x][i].w)
            {
                d[g[x][i].v] = d[x] + g[x][i].w, q.push({-d[g[x][i].v], g[x][i].v});
            }
        }
    }
}
signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> dd >> q;
    for (int i = 1; i <= m; ++i) cin >> w[i];
 //   cout << w[6] << endl;
    if (n == 2)
    {
        for (int i = 1; i <= n; ++i)
        {
            cin >> k[i];
            for (int j = 1; j <= k[i]; ++j) cin >> a[i][j] >> t[i][j];
            for (int j = 1; j <= k[i]; ++j) ef[a[i][j]][i] = j;
        }
        int ans = 1e18;
        for (int i = 1; i <= m; ++i)
        {
            if (ef[i][1] && ef[i][2]) ans = min(ans, t[1][ef[i][1]] + t[2][ef[i][2]]);
        }
        while (q--)
        {
            int x, y;
            cin >> x >> y;
            if (ef[x][1] && ef[y][1]) cout << w[x] + w[y] + t[1][ef[x][1]] + t[1][ef[y][1]] << endl;
            else if (ef[x][2] && ef[y][2]) cout << w[x] + w[y] + t[2][ef[x][2]] + t[2][ef[y][2]] << endl;
            else
            {
                if (ef[x][1]) cout << w[x] + w[y] + t[1][ef[x][1]] + t[2][ef[y][2]] + ans << endl;
                else cout << w[x] + w[y] + t[2][ef[x][2]] + t[1][ef[y][1]] + ans << endl;
            }
        }
        return 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> k[i];
        for (int j = 1; j <= k[i]; ++j)
        {
            cin >> a[i][j] >> t[i][j];
            vis[a[i][j]][i] = t[i][j];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= k[i]; ++j)
        {
            for (int de = j + 1; de <= k[i]; ++de) g[a[i][j] + i * m].push_back({a[i][de] + i * m, 0}), g[a[i][de] + i * m].push_back({a[i][j] + i * m, 0});
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (vis[i][j])
            {
                for (int k = j + 1; k <= n; ++k)
                {
                    if (k != j && vis[i][k])
                    {
                       // if (j == 1 && k == 3 && i == 5) cout << vis[i][k] + vis[i][j] << endl;
                        g[i + k * m].push_back({i + j * m, vis[i][k] + vis[i][j]});
                        g[i + j * m].push_back({i + k * m, vis[i][k] + vis[i][j]});
                    }
                }
            }
        }
    }
    while (q--)
    {
        int x, y, ans = 1e9;
        cin >> x >> y;
        for (int i = 1; i <= n; ++i)
        {
            if (vis[x][i])
            {
                dijkstra(x + i * m);
                for (int j = 1; j <= n; ++j)
                {

                  //     cout << w[y] + d[j * m + y] << endl;
                        ans = min(ans, w[x] + w[y] + d[j * m + y] + vis[y][j] + vis[x][i]);

                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
