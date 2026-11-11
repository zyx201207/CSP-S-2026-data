#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;

const int N = 5e2 + 7, M = 5e5 + 7, D = 21;
int c, n, m, d, q, k[N], p[M], ans, dis[N + M], disn[N][N];
bool vis[N + M];
vector<int> a[N], t[N], aa[M], tt[M];

struct edge
{
    int v, w;
};
vector<edge> e[M + N];

void dijkstra(int s)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    memset(dis, 0x3f, sizeof dis);
    memset(vis, 0, sizeof vis);
    dis[s] = 0;
    while (!pq.empty())
    {
        int now = pq.top().second;
        pq.pop();
        if (vis[now])
            continue;
        for (edge u : e[now])
        {
            if (!vis[u.v] && u.w + dis[now] < dis[u.v])
                dis[u.v] = u.w + dis[now], pq.push({u.w + dis[now], u.v});
        }
    }
}

signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; ++i)
        cin >> p[i];
    for (int i = 1; i <= n; ++i)
    {
        cin >> k[i];
        for (int j = 1; j <= k[i]; ++j)
        {
            int x, y;
            cin >> x >> y;
            a[i].push_back(x);
            t[i].push_back(y);
            aa[x].push_back(i);
            tt[x].push_back(y);
            e[x].push_back({m + i, y});
            e[m + i].push_back({x, y});
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        dijkstra(m + i);
        for (int j = 1; j <= n; ++j)
            disn[i][j] = dis[m + j];
    }
    while (q--)
    {
        int s, t, ans = 1e13;
        cin >> s >> t;
        for (int i = 0; i < aa[s].size(); ++i)
            for (int j = 0; j < aa[t].size(); ++j)
                ans = min(ans, p[s] + p[t] + tt[s][i] + tt[t][j] + disn[aa[s][i]][aa[t][j]]);
        cout << ans << endl;
    }
}