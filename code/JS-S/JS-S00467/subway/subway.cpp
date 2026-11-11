#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 500510;

struct node
{
    int v, w;
};

bool operator < (node a, node b)
{
    return a.w > b.w;
}

int c, n, m, d, q;
int w1[maxn], dis[maxn], dp[501][501];
vector<node>g[maxn], g1[501];

void dij(int s)
{
    for (int i = 1; i <= n+m; i++) dis[i] = 1e18;
    priority_queue<node>pq;
    dis[s] = 0;
    pq.push({s,0});
    while(pq.size())
    {
        int u = pq.top().v;
        pq.pop();
        for (node nxt : g1[u])
        {
            int v = nxt.v, w = nxt.w;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                pq.push({v,dis[v]});
            }
        }
    }
}

main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w1[i];
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            int v, t;
            cin >> v >> t;
            g[i+m].push_back({v,t});
            g[v].push_back({i+m,t});
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int x = 0; x < g[i].size(); x++)
        {
            for (int y = x+1; y < g[i].size(); y++)
            {
                int u = g[i][x].v-m, v = g[i][y].v-m, w = g[i][x].w + g[i][y].w;
                g1[u].push_back({v,w});
                g1[v].push_back({u,w});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        dij(i);
        for (int j = 1; j <= n; j++) dp[i][j] = dis[j];
    }
    while(q--)
    {
        int x, y, ans = 1e18;
        cin >> x >> y;
        for (node u : g[x])
        {
            for (node v : g[y])
            {
                ans = min(ans, w1[x]+w1[y]+dp[u.v-m][v.v-m]+u.w+v.w);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
