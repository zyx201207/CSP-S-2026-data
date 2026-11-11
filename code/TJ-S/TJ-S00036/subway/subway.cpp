#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;
long long  _, __, n, m, q, l[500005], dis[1000005];
vector <pair <long long, long long> > adj[1000005];
long long dij(long long s, long long t)
{
    priority_queue <pair <long long, long long> > pq;
    memset(dis, 0x3f3f3f3f3f3f3f3f, sizeof(dis));
    pq.push({0, s});
    while (!pq.empty())
    {
        auto [_d, u] = pq.top();
        pq.pop();
        if (dis[u] != 0x3f3f3f3f3f3f3f3f)
        {
            continue;
        }
        dis[u] = -_d;
        if (u == t)
        {
            return dis[u];
        }
        for (auto [v, w] : adj[u])
        {
            pq.push({_d-w, v});
        }
    }
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> _ >> n >> m >> __ >>  q;
    for (long long i = 1; i <= m; i++)
    {
        cin >> l[i];
    }
    long long ___ = m;
    for (long long i = 1, k; i <= n; i++)
    {
        cin >> k;
        for (long long j = 1, a, t; j <= k; j++)
        {
            cin >> a >> t;
            ___++;
            adj[___].push_back({a, t}), adj[a].push_back({___, t});
            if (j != 1)
            {
                adj[___].push_back({___-1, 0}), adj[___-1].push_back({___, 0});
            }
        }
    }
    m = ___;
    while(q--)
    {
        long long u, v;
        cin >> u >> v;
        cout << l[u]+dij(u, v)+l[v] << "\n";
    }
    return 0;
}
