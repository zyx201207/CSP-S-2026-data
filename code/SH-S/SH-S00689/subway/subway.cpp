#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
long long w[500005];
long long dis[505][505];
vector <pair <long long, long long>> trans[500005];
long long k[505];
vector <pair <long long, long long>> g[505];
int vis[505];
void dijkstra(int st)
{
    priority_queue <pair <long long, long long>, vector <pair <long long, long long>>, greater <pair <long long, long long>>> pq;
    pq.push({0, st});
    dis[st][0] = 0;
    while (!pq.empty())
    {
        auto u = pq.top();
        pq.pop();
        if (vis[u.second])
            continue;
        vis[u.second] = 1;
        for (auto v : g[u.second])
        {
            if (v.second + dis[st][u.second] <= dis[st][v.first])
            {
                dis[st][v.first] = v.second + dis[st][u.second];
                pq.push({dis[st][v.first], v.first});
            }
        }
    }
    return;
}
void init()
{
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= m; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++)
        {
            int u, v;
            cin >> u >> v;
            trans[u].push_back({i, v});
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (auto u : trans[i])
        {
            for (auto v : trans[i])
                dis[u.first][v.first] = min(dis[u.first][v.first], u.second + v.second);
        }
    }
    for (int i = 1; i <= n; i++)
        dis[i][i] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            g[i].push_back({j, dis[i][j]});
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            dis[k][i] = 0x3f3f3f3f3f3f3f3f;
            vis[i] = 0;
    	}
        dis[k][k] = 0;
        dijkstra(k);
    }
    return;
}
long long solve(int a, int b)
{
    long long sum = 0x3f3f3f3f3f3f3f3f;
    for (auto u : trans[a])
    {
        for (auto v : trans[b])
            sum = min(sum, dis[u.first][v.first] + u.second + v.second);
    }
    sum += w[a] + w[b];
    return sum;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    init();
    while (q--)
    {
        int st, nd;
        cin >> st >> nd;
        cout << solve(st, nd) << '\n';
    }
    return 0;
}
