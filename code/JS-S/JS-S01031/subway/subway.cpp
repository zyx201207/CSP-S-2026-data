#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll,ll> pll;
#define INF 0x3f3f3f3f3f3f3f3f
const ll N = 5e2 + 5;
const ll M = 1e6 + 5;
ll c;
ll n;
ll m;
ll d;
ll q;
ll a[M];
ll dis[N][N];
vector <pll> g[M];
inline void openfile(string s)
{
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
inline void Floyd()
{
    for(ll i = 1;i <= n;++i)
        dis[i][i] = 0;
    for(ll k = 1;k <= n;++k)
        for(ll i = 1;i <= n;++i)
            for(ll j = 1;j <= n;++j)
                if(i != j && j != k && k != i && dis[i][j] > dis[i][k] + dis[k][j])
                    dis[i][j] = dis[i][k] + dis[k][j];
}
int main()
{
    openfile("subway");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for(ll i = 0;i < N;++i)
        fill(dis[i],dis[i] + N,INF);
    cin >> c >> n >> m >> d >> q;
    for(ll i = 1;i <= m;++i)
        cin >> a[i];
    for(ll i = 1;i <= n;++i)
    {
        ll k = 0;
        cin >> k;
        for(ll j = 1;j <= k;++j)
        {
            ll u = 0;
            ll w = 0;
            cin >> u >> w;
            g[u].push_back({i,w});
        }
    }
    for(ll i = 1;i <= m;++i)
    {
        ll len = g[i].size();
        for(ll j = 0;j < len - 1;++j)
        {
            ll u = g[i][j].first;
            ll w = g[i][j].second;
            for(ll k = j + 1;k < len;++k)
            {
                ll v = g[i][k].first;
                ll d = g[i][k].second;
                dis[u][v] = min(dis[u][v],d + w);
                dis[v][u] = min(dis[v][u],d + w);
            }
        }
    }
    Floyd();
    while(q--)
    {
        ll s = 0;
        ll t = 0;
        cin >> s >> t;
        ll ans = INF;
        for(auto x : g[s])
        {
            for(auto y : g[t])
            {
                ll u = x.first;
                ll v = y.first;
                ll d = x.second;
                ll w = y.second;
                ans = min(ans,dis[u][v] + a[s] + a[t] + d + w);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
