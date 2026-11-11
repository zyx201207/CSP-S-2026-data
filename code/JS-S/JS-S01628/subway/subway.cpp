#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 505,M = 5e5 + 5,INF = 0x3f3f3f3f3f3f3f3f;
struct edge
{
    ll to,ti;
    edge(ll _v = 0,ll _w = 0): to(_v),ti(_w) {}
};
ll c,n,m,d,q,w[M],k[N],dis[N][N];
vector<ll> a[N],t[N];
vector<edge> gra[M];
int main() 
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    // clock_t st = clock();
    ll x,y,minn;
    cin >> c >> n >> m >> d >> q;
    for (ll i = 1; i <= m; i++) cin >> w[i];
    for (ll i = 1; i <= n; i++) 
    {
        cin >> k[i];
        for (ll j = 1; j <= k[i]; j++) 
        {
            cin >> x >> y;
            a[i].push_back(x);
            t[i].push_back(y);
            gra[x].push_back(edge(i,y));
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for (ll i = 1; i <= n; i++) dis[i][i] = 0;
    for (ll i = 1; i <= m; i++) 
        for (auto u : gra[i]) 
            for (auto v : gra[i]) 
                dis[u.to][v.to] = min(dis[u.to][v.to],u.ti + v.ti);
    for (ll k = 1; k <= n; k++) 
        for (ll i = 1; i <= n; i++) 
            if (k != i) 
                for (ll j = 1; j <= n; j++) 
                    dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
    for (ll i = 1; i <= q; i++) 
    {
        cin >> x >> y;
        minn = INF;
        for (auto u : gra[x]) 
            for (auto v: gra[y]) 
                minn = min(minn,u.ti + v.ti + dis[u.to][v.to]);
        cout << w[x] + w[y] + minn << '\n';
    }
    // clock_t ed = clock();
    // cout << double(ed - st) / CLOCKS_PER_SEC << endl;
    return 0;
}
