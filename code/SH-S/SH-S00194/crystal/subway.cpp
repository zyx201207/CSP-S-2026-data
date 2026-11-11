#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const ll M = 5e5 + 10, N = 510, Q = 1e5 + 10;
struct vinfo
{
    ll v, l;
};
struct plll
{
    ll d, u, l;
    const bool operator>(const plll &rhs) const
    {
        return d > rhs.d;
    }
};
ll c, n, m, d, q, w[M];
ll t[N][M];
vector<vinfo> g[M];
vector<pll> query[M];
vector<ll> a[M];
ll dis[M];
ll ans[Q];
void dij(ll s)
{
    memset(dis, 0x3f, sizeof(dis));
    priority_queue<plll, vector<plll>, greater<plll>> pq;
    // dis[s] = 0;
    for (int l = 0; l < a[s].size(); l ++)
    {
        dis[s] = t[a[s][l]][s];
        pq.push((plll){dis[s], s, a[s][l]});
        while (!pq.empty())
        {
            plll cur = pq.top();
            pq.pop();
            ll u = cur.u, d = cur.d, line1 = cur.l;
            if (dis[u] < d)
            {
                continue;
            }
            for (int i = 0; i < g[u].size(); i ++)
            {
                ll v = g[u][i].v, line2 = g[u][i].l;
                ll w = 0;
                if (line1 != line2)
                {
                    // printf("wants from station #%lld->station #%lld|line #%lld -> line #%lld\n", u, v, f, line);
                    // printf("goes to zhangting at cur st&line%lld->newline zhantai%lld->newpoint zhantai %lld\n", t[u][f], t[u][line], t[v][line]);
                    w += (t[line1][u] + t[line2][u]);
                }
                if (dis[v] > dis[u] + w)
                {
                    dis[v] = dis[u] + w;
                    // printf("dis[%lld]<-%lld\n", v, dis[v]);
                    pq.push((plll){dis[v], v, line2});
                }
            }
        }
    }
    // puts("--------");
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%lld %lld %lld %lld %lld", &c, &n, &m, &d, &q);
    for (int i = 1; i <= m; i ++)
    {
        scanf("%lld", &w[i]);
    }
    for (int i = 1; i <= n; i ++)
    {
        ll k;
        scanf("%lld", &k);
        ll last;
        for (int j = 1; j <= k; j ++)
        {
            ll aij, tij;
            scanf("%lld %lld", &aij, &tij);
            a[aij].push_back(i);
            t[i][aij] = tij;
            if (j > 1)
            {
                g[last].push_back((vinfo){aij, i});
                g[aij].push_back((vinfo){last, i});
            }
            last = aij;
        }
    }
    vector<ll> starts;
    vector<bool> vis(M, 0);
    for (int i = 1; i <= q; i ++)
    {
        ll x, y;
        scanf("%lld %lld", &x, &y);
        query[x].push_back(make_pair(y, i));
        if (!vis[x])
        {
            starts.push_back(x);
            vis[x] = 1;
        }
    }
    for (int i = 0; i < starts.size(); i ++)
    {
        ll x = starts[i];
        dij(x);
        for (int j = 0; j < query[x].size(); j ++)
        {
            ll y = query[x][j].first, pos = query[x][j].second;
            ans[pos] = dis[y] + w[x] + w[y];
        }
    }
    for (int i = 1; i <= q; i ++)
    {
        printf("%lld\n", ans[i]);
    }
    return 0;
}