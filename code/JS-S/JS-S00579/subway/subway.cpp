#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, ds, x, y, ans;

struct node
{
    int v, w;
};
int w[500005];
vector<node> g[500005];
int dis[3005];
bool vis[3005][3005];
queue<int>q;
void spfa(int s)
{
    memset(dis, 0x3f, sizeof dis);
    dis[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < g[u].size(); i++)
        {
            int v = g[u][i].v, w = g[u][i].w;
            if (dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                q.push(v);
            }
        }
    }
}

signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> ds;
    for (int i = 1; i <= m; i++)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        for (int j = 1; j <= 2 * k; j++)
        {
            int w;
            cin >> w;
            if (vis[i][j])
            {
                for (int tt = 0; tt < g[i].size(); tt++)
                {
                    if (g[i][tt].v == j) g[i][tt].w += w;
                }
                for (int tt = 0; tt < g[i].size(); tt++)
                {
                    if (g[tt][i].v == j) g[tt][i].w += w;
                }
            }
            else
            {
                vis[i][j] = 1;
                vis[j][i] = 1;
                g[i].push_back({j, w});
                g[j].push_back({i, w});
            }
        }
    }
    memset(dis, 0x3f, sizeof dis);
    int ds;
    cin >> ds;
    while (ds--)
    {
        memset(dis, 0x3f, sizeof dis);
        ans = 0;
        cin >> x >> y;
        spfa(x);
        cout << dis[y] << endl;
    }
    return 0;
}
//Kingsley is gay
//fuck you CCF
//afo on 2026.10.31
