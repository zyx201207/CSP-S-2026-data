// Darkworldmystery 2023 ~ 2027
#include<bits/stdc++.h>

using namespace std;
using LL = long long;

const LL kMaxN = 9005;

struct Point
{
    LL k, a[kMaxN], t[kMaxN];
} sta[kMaxN];

LL c, n, m, d, q, cost[kMaxN], dis[kMaxN];
vector<pair<LL, LL> > nbr[kMaxN];

void dijkstra(LL s)
{
    fill(dis + 1, dis + 1 + m * n + m, 1e9);
    dis[s] = 0ll;
    priority_queue<pair<LL, LL>, vector<pair<LL, LL> >, greater<pair<LL, LL> > > q;
    q.push({0ll, s});
    while(!q.empty())
    {
        pair<LL, LL> TT = q.top(); q.pop();
        LL d = TT.first, x = TT.second;
        if(d > dis[x])
            continue;
        for(auto p : nbr[x])
        {
            LL y = p.first, w = p.second;
            if(dis[y] > dis[x] + w)
            {
                dis[y] = dis[x] + w;
                q.push({dis[y], y});
            }
        }
    }
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    cin >> c >> n >> m >> d >> q;
    for(LL i = 1; i <= m; i++)
        cin >> cost[i];
    for(LL i = 1; i <= n; i++)
    {
        cin >> sta[i].k;
        for(LL j = 1; j <= sta[i].k; j++)
        {
            cin >> sta[i].a[j] >> sta[i].t[j];
            nbr[sta[i].a[j]].push_back({i * m + sta[i].a[j], sta[i].t[j]});
            nbr[i * m + sta[i].a[j]].push_back({sta[i].a[j], sta[i].t[j]});
        }
    }
    for(LL i = 1; i <= n; i++)
        for(LL j = 1; j < sta[i].k; j++)
        {
            nbr[sta[i].a[j] + i * m].push_back({sta[i].a[j + 1] + i * m, 0});
            nbr[sta[i].a[j + 1] + i * m].push_back({sta[i].a[j] + i * m, 0});
        }
    for(LL i = 1, x, y; i <= q; i++)
    {
        cin >> x >> y;
        dijkstra(x);
        cout << dis[y] + cost[x] + cost[y] << "\n";
    }
    return 0;
}