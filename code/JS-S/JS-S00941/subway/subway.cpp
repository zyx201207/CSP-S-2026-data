#include <bits/stdc++.h>
using namespace std;

#define int long long

struct node
{
    int v, w;
};

struct Node
{
    int u, d;
};

int c, n, m, dd, Q, k[505], w[500005], d[5500005], tot;
vector<node> g[500005];
priority_queue<Node> q;

bool operator<(Node a, Node b) { return a.d > b.d; }

void Dijkstra(int s, int t)
{
    memset(d, 0x3f, sizeof d);
    d[s] = 0; q.push({s, d[s]});
    while (!q.empty())
    {
        int u = q.top().u, D = q.top().d; q.pop();
        if (D > d[u]) continue;
        for (int i = 0;i < g[u].size();i++)
        {
            int v = g[u][i].v, w = g[u][i].w;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                q.push({v, d[v]});
            }
        }
    }
}

signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> c >> n >> m >> dd >> Q;
    for (int i = 1;i <= m;i++) cin >> w[i];
    for (int i = 1;i <= n;i++)
    {
        cin >> k[i];
        int a[500005], t[500005];
        for (int j = 1;j <= k[i];j++)
        {
            cin >> a[j] >> t[j];
            g[a[j]].push_back({m+i, t[j]});
            g[m+i].push_back({a[j], t[j]});
        }
    }
    while (Q--)
    {
        int u, v; cin >> u >> v;
        Dijkstra(u, v);
        cout << d[v] + w[u] + w[v] << "\n";
    }
    return 0;
}
