#include<bits/stdc++.h>

using namespace std;
using LL = long long;

const LL kMaxN = 5005;

LL c, t, n, d, a[kMaxN], dis[kMaxN], cnt[kMaxN];
vector<LL> nbr[kMaxN];

void dijkstra(LL s)
{
    fill(dis + 1, dis + 1 + n, 2e18);
    fill(cnt + 1, cnt + 1 + n, 0ll);
    dis[s] = 0ll;
    priority_queue<pair<LL, LL>, vector<pair<LL, LL> >, greater<pair<LL, LL> > > q;
    q.push({0ll, s});
    while(!q.empty())
    {
        auto TT = q.top(); q.pop();
        LL d = TT.first, x = TT.second;
        if(d > dis[x])
            continue;
        for(auto y : nbr[x])
        {
            if(dis[y] == dis[x] + 1)
                cnt[y]++;
            if(dis[y] > dis[x] + 1)
            {
                cnt[y] = 1;
                dis[y] = dis[x] + 1;
                q.push({dis[y], y});
            }
        }
    }
}

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    cin >> c >> t;
    while(t--)
    {
        cin >> n >> d;
        for(LL i = 1; i <= n; i++)
            cin >> a[i], nbr[i].clear();
        for(LL i = 1; i <= n; i++)
            for(LL j = i + 1; j <= n; j++)
                if(abs(a[j] - a[i]) <= d)
                    nbr[i].push_back(j), nbr[j].push_back(i);
        LL ret = 0;
        for(LL i = 1; i <= n; i++)
        {
            dijkstra(i);
            for(LL j = i + 1; j <= n; j++)
                if(cnt[j] == 2)
                    ret++;
        }
        cout << ret << "\n";
    }
    return 0;
}