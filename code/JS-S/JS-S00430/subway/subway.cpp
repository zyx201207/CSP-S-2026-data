#include <bits/stdc++.h>
#define ll long long int
#define fi first
#define se second
#define rep(i, f, t) for(int i = f ; i <= t ; ++i)
#define per(i, f, t) for(int i = f ; i >= t ; --i)
#define all(x) x.begin() x.end()
#define re return
#define endl '\n'
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tupii pair<int, pii>
#define t1 fi
#define t2 se.fi
#define t3 se.se

using namespace std;
const ll inf = 0x3f3f3f3f3f3f3f3fLL;
ll c,n,m,d,q,w[500007],k, a, t, x, y;
vector<pll> edge[500507];
ll dist[507][507];
int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    rep(i, 1, m)cin >> w[i];
    rep(i, 1, n){
        cin >> k;
        rep(j, 1, k){
            cin >> a >> t;
            edge[a].push_back(pll(i + 500000, t));
            edge[i + 500000].push_back(pll(a, t));
        }
    }
    rep(i, 1, n)rep(j, 1, n)dist[i][j] = 1e17;
    rep(i, 1 ,n)dist[i][i] = 0;

    rep(i, 1, m){
        int s = edge[i].size();
        rep(j, 0, s - 1)rep(k, 0, s - 1){
            if(j == k)continue;
            ll u = edge[i][j].fi - 500000, v = edge[i][k].fi - 500000, ds = edge[i][j].se + edge[i][k].se;
            dist[u][v] = min(dist[u][v], ds);
        }
    }

    rep(k, 1, n)rep(i, 1, n)rep(j,1,n){
        dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
    }
    while(q--){
        cin >> x >> y;
        ll res = inf;
        for(auto e:edge[x])for(auto f:edge[y]){
            res = min(res, e.se + f.se + dist[e.fi - 500000][f.fi - 500000]);
        }
        cout << w[x] + w[y] + res << endl;
    }
    re 0;
}

