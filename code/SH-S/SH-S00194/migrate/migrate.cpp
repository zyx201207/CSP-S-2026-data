#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const int N = 2e6 + 10;
ll c, t, n, d, x[N];
vector<pll> g[N];
inline ll myAbs(ll a)
{
    return a < 0 ? -a : a;
}
inline ll dist(ll a, ll b)
{
    return myAbs(x[a] - x[b]);
}
inline bool avail(ll a, ll b)
{
    return dist(a, b) <= d;
}
ll dis[N], cnt[N];
void dij(ll s)
{
    memset(dis, 0x3f, sizeof(dis));
    memset(cnt, 0, sizeof(cnt));
    dis[s] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push(make_pair(dis[s], s));
    while (!pq.empty())
    {
        pll cur = pq.top();
        pq.pop();
        ll u = cur.second, d = cur.first;
        if (dis[u] < d)
        {
            continue;
        }
        for (int i = 0; i < g[u].size(); i ++)
        {
            int v = g[u][i].first, w = 1;
            if (dis[v] > dis[u] + w)
            {
                if (v == 2 && u == 1)
                {
                    // printf("#%lld-> %lld zhaodaolegengduandelu\n", v, dis[v]);
                    // printf("yuanlai: %lld, gaichengle %lld\n", dis[v], dis[u] + w);
                }
                dis[v] = dis[u] + w;
                cnt[v] = 1;
                pq.push(make_pair(dis[v], v));
            }
            else if (dis[v] == dis[u] + w)
            {
                cnt[v] ++;
                // printf("dis[%lld] == dis[%lld] + %lld: ", v, u, w);
                // printf("%lld == %lld + %lld\n", dis[v], dis[u], w);
            }
        }
    }
}
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%lld %lld", &c, &t);
    while (t --)
    {
        scanf("%lld %lld", &n, &d);
        for (int i = 1; i <= n; i ++)
        {
            scanf("%lld", &x[i]);
            for (int j = 1; j < i; j ++)
            {
                if (avail(j, i))
                {
                    g[i].push_back(make_pair(j, dist(i, j)));
                    g[j].push_back(make_pair(i, dist(i, j)));
                }
            }
        }
        // for (int i = 1; i <= n; i ++)
        // {
        //     for (int j = 0; j < g[i].size(); j ++)
        //     {
        //         printf("pt: %lld w: %lld ", g[i][j].first, g[i][j].second);
        //     }
        //     puts("");
        // }
        ll ans = 0;
        for (int i = 1; i <= n; i ++)
        {
            dij(i);
            for (int j = i + 1; j <= n; j ++)
            {
                // cout << cnt[j] << ' ';
                if (cnt[j] == 2)
                {
                    ans ++;
                }
            }
            // cout << endl;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
