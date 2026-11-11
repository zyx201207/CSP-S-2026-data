#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair < ll, ll >;

const ll Maxn = 505;
const ll Maxm = 5e5 + 5;
const ll Maxq = 1e5 + 5;
const ll INF = LLONG_MAX / 2;

ll c, n, m, d, q;
ll w[Maxm], Map[Maxn][Maxn];
ll dist[Maxn][Maxn], color[Maxn][Maxn];
ll ans[Maxq];
vector < PII > sub[Maxm];
vector < PII > g[Maxn];

inline void read(ll &x)
{
    x = 0; ll f = 1;
    char ch = getchar();
    while(!isdigit(ch)) f = ch == '-' ? -1 : f, ch = getchar();
    while( isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    x *= f;
}

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    read(c), read(n), read(m), read(d), read(q);
    for (ll i = 1; i <= m; ++i)
        read(w[i]);
    for (ll i = 1; i <= n; ++i)
    {
        ll k;
        read(k);
        for (ll j = 1; j <= k; ++j)
        {
            ll a, t;
            read(a), read(t);
            sub[a].push_back(make_pair(i, t));
        }
    }
    for (ll i = 1; i <= n; ++i)
        for (ll j = 1; j <= n; ++j)
            Map[i][j] = dist[i][j] = INF;
    for (ll i = 1; i <= m; ++i)
    {
        for (auto s: sub[i])
        {
            for (auto t: sub[i])
            {
                ll u = s.first, v = t.first;
                ll w1 = s.second, w2 = t.second;
                if(u == v) continue;
                Map[u][v] = min(Map[u][v], w1 + w2);
                Map[v][u] = min(Map[v][u], w1 + w2);
            }
        }
    }
    for (ll i = 1; i <= n; ++i)
        for (ll j = 1; j <= n; ++j)
            if(Map[i][j] != INF) g[i].push_back(make_pair(j, Map[i][j]));
    for (ll s = 1; s <= n; ++s)
    {
        priority_queue < PII, vector < PII >, greater < PII > > q;
        dist[s][s] = 0;
        q.push(make_pair(0, s));
        while(!q.empty())
        {
            ll u = q.top().second; q.pop();
            if(color[s][u]) continue;
            color[s][u] = true;
            for (auto t: g[u])
            {
                ll v = t.first;
                ll w = t.second;
                if(dist[s][u] + w < dist[s][v])
                {
                    dist[s][v] = dist[s][u] + w;
                    q.push(make_pair(dist[s][v], v));
                }
            }
        }
    }
    for (ll i = 1; i <= q; ++i)
    {
        ll x, y;
        read(x), read(y);
        ll Min = INF;
        for (auto u: sub[x])
            for (auto v: sub[y])
                Min = min(Min, dist[u.first][v.first] + u.second + v.second + w[x] + w[y]);
        ans[i] = Min;
    }
    for (ll i = 1; i <= q; ++i)
        printf("%lld\n", ans[i]);
    return 0;
}
