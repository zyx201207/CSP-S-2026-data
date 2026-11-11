#include <bits/stdc++.h>
#define ll long long
#define p pair<int, int>
using namespace std;

const int N = 5e5 + 5, M = 2e4 + 5;
int c, n, m, q, d;
int w[N], k, a[N], t[N];
vector < pair <int, int> > g[N];
int dist[M][M];
bool vis[N];
void dijkstra(int s)
{
    priority_queue <p, vector <p> , greater<p> > qu;
    memset(vis, 0, sizeof(vis));
    dist[s][s] = 0;
    qu.push({0, s});
    //for(int i = 1;i <= n;i++) cout << dist[i] << " ";
    //cout << '\n';
    while(!qu.empty())
    {
        auto [di, u] = qu.top(); qu.pop();
        vis[u] = 1;
        //cout << u << " " << di << '\n';
        int sz = g[u].size();
        for (int i = 0;i < sz;i++)
        {
            int v = g[u][i].first, w = g[u][i].second;
            if(di + w >= dist[s][v]) continue;
            else{
                dist[s][v] = di + w;
                if(!vis[v])qu.push(make_pair(dist[s][v], v));
            }
        }
        //for(int i = 1;i <= n;i++) cout << dist[i] << " ";
        //cout << '\n';
    }
}


signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1;i <= m;i++)
    {
        memset(dist[i], 0x3f, sizeof(dist[i]));
    }
    for (int i = 1;i <= m;i++) cin >> w[i];
    for (int i = 1;i <= n;i++)
    {
        cin >> k;
        for (int j = 1;j <= k;j++) cin >> a[j] >> t[j];
        for (int j = 2;j <= k;j++)
            for(int x = 1;x < j;x++) g[a[j]].push_back({a[x], t[j] + t[x]}),  g[a[x]].push_back({a[j], t[j] + t[x]});
    }
    int xr, yr;
    for (int i = 1;i <= q;i++)
    {
        cin >> xr >> yr;
        if(dist[xr][xr] != 0) dijkstra(xr);
        cout << dist[xr][yr] + w[xr] + w[yr] << '\n';
    }
    return 0;
}
//16:13 wo hao tang, wo bu hui zuo
//qwq
//17:32 writing bao li
//I have no water left, I'm really thirsty
