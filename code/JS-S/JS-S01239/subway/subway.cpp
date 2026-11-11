#include<bits/stdc++.h>

using namespace std;

const int MAXN = 5e3 + 5, MAXM = 5e5 + 5;

struct node
{
    int v, w;
    bool operator < (const node &ver) const
    {
        return w > ver.w;
    }
};

bool vis[MAXN];
int dis[MAXN][MAXN];
vector<node> h[MAXN];
vector<node> g[MAXN + MAXM];

void dijkstra (int s)
{
    memset (vis, 0, sizeof (vis) );
    memset (dis[s], 0x3f, sizeof (dis[s]) );
    priority_queue<node> q;
    q.push ({s, dis[s][s] = 0});
    while (q.size() )
    {
        int u = q.top().v;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (auto t : h[u])
        {
            int v = t.v, w = t.w;
            if (dis[s][u] + w < dis[s][v])
            {
                dis[s][v] = dis[s][u] + w;
                q.push ({v, dis[s][v]});
            }
        }
    }
}

vector<int> c[MAXM], tt[MAXM];
int w[MAXM], k[MAXN];
vector<int> a[MAXN], t[MAXN];

int main()
{
    freopen ("subway.in", "r", stdin);
    freopen ("subway.out", "w", stdout);
    ios::sync_with_stdio (false);
    cin.tie (0);
    int C, n, m, d, q;
    cin >> C >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++)
        {
            int x, y;
            cin >> x >> y;
            a[i].push_back (x);
            t[i].push_back (y);
            c[x].push_back (i);
            tt[x].push_back (y);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < k[i]; j++)
        {
            g[i].push_back ({a[i][j] + n, t[i][j]});
            g[a[i][j] + n].push_back ({i, t[i][j]});
        }
    }
    for (int i = 1 + n; i <= m + n; i++)
    {
        for (int j = 0; j < g[i].size(); j++)
        {
            int u = g[i][j].v;
            for (int l = j + 1; l < g[i].size(); l++)
            {
                int v = g[i][l].v;
                int ww = g[i][j].w + g[i][l].w;
                h[u].push_back ({v, ww});
                h[v].push_back ({u, ww});
            }
        }
    }
    for (int i = 1; i <= n; i++)
        dijkstra (i);
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        int minn = 0x3f3f3f3f;
        for (int i = 0; i < c[x].size(); i++)
        {
            for (int j = 0; j < c[y].size(); j++)
            {
                minn = min (minn, dis[c[x][i]][c[y][j]] + tt[x][i] + tt[y][j]);
            }
        }
        cout << w[x] + w[y] + minn << "\n";
    }
    return 0;
}
