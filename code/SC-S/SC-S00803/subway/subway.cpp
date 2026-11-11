#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 504, M = 5e5+4;
const ll inf = 1e18;
int c, n, m, d, q;
ll a[M], dis[N][N];
struct node{int to, w;};
vector<node> g[M];
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i=1;i<=m;++i) cin >> a[i];
    for (int i=1;i<=n;++i) for (int j=1;j<=n;++j) dis[i][j] = i==j?0:inf;
    for (int i=1, k, to, tim;i<=n;++i){
        cin >> k;
        while (k--){
            cin >> to >> tim;
            g[to].push_back({i, tim});
        }
    }
    for (int i=1;i<=m;++i){
        int l = g[i].size();
        for (int j=0;j<l;++j){
            int u = g[i][j].to;
            for (int k=j+1;k<l;++k){
                int v = g[i][k].to;
                dis[u][v] = min(dis[u][v], (ll)g[i][j].w+g[i][k].w);
                dis[v][u] = dis[u][v];
            }
        }
    }
    for (int k=1;k<=n;++k)
        for (int i=1;i<=n;++i)
            for (int j=1;j<=n;++j)
                dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
    while (q--){
        int u, v; cin >> u >> v;
        ll ans = inf;
        for (auto x:g[u]){
            for (auto y:g[v]){
                ans = min(ans, dis[x.to][y.to]+x.w+y.w);
            }
        }
        cout << ans+a[u]+a[v] << '\n';
    }
    return 0;
}