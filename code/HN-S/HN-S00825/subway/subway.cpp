#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 5e2 + 5, M = 5e5 + 5;
const ll INF = 1e18;

int c, n, m, d, q, w[M];
ll dis[N][N], ans;

struct edge{
    int v, t;
};
vector<edge> g[M];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1, k; i <= n; i++){
        cin >> k;
        for(int j = 1, v, t; j <= k; j++) cin >> v >> t, g[v].push_back((edge){i, t});
    }
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) dis[i][j] = (i == j ? 0ll : INF);
    for(int i = 1; i <= m; i++) for(edge u : g[i]) for(edge v : g[i]) dis[u.v][v.v] = min(0ll + u.t + v.t, dis[u.v][v.v]);
    for(int k = 1; k <= n; k++) for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    for(int i = 1, x, y; i <= q; i++){
        cin >> x >> y, ans = INF;
        for(edge u : g[x]) for(edge v : g[y]) ans = min(ans, dis[u.v][v.v] + u.t + v.t);
        cout << ans + w[x] + w[y] << '\n';
    }
    return 0;
}