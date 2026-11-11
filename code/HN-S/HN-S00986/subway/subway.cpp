#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i++)
#define per(i, x, y) for(int i = x; i >= y; i--)
// #define int long long
#define chkmax(x, y) (x = max(x, y))
#define chkmin(x, y) (x = min(x, y))
#define pb push_back
using namespace std;
using ll = long long;

const int MAXM = 5e5 + 5, MAXN = 505;
const ll inf = 1e18;

int c, n, m, d, q, w[MAXM];
int k[MAXN];
vector<pair<int, int>> a[MAXN];

ll e[MAXN][MAXN], dis[MAXN][MAXN];
int CurT[MAXM];

struct node {
  int u;
  ll w;
  bool operator<(const node &x) const {
    return x.w < w;
  }
};
bool vis[MAXN];
void Dij(int s) {
  priority_queue<node> pq;
  rep(i, 1, n) vis[i] = 0, dis[s][i] = inf;
  pq.push({s, 0}), dis[s][s] = 0;
  for (; pq.size(); ) {
    node now = pq.top(); pq.pop();
    int u = now.u;
    if (vis[u]) continue; vis[u] = 1;
    rep(v, 1, n) if (e[u][v] != -1) {
      if (dis[s][v] > dis[s][u] + e[u][v]) {
        dis[s][v] = dis[s][u] + e[u][v];
        if (!vis[v]) pq.push({v, dis[s][v]});
      }
    }
  }
}
// void Floyd() {
//   rep(i, 1, n) rep(j, 1, n) dis[i][j] = e[i][j];
//   rep(k, 1, n) rep(i, 1, n) rep(j, 1, n) chkmin(dis[i][j], dis[i][k] + dis[k][j]);
// }
vector<pair<int, int>> id[MAXM];
signed main() {
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
int T1 = clock();
  cin >> c >> n >> m >> d >> q;
  rep(i, 1, m) cin >> w[i];
  rep(i, 1, n) {
    cin >> k[i];
    rep(j, 1, k[i]) {
      int v, t; cin >> v >> t;
      a[i].pb({v, t}), id[v].pb({i, t});
    }
  }


  rep(i, 1, m) CurT[i] = -1;
  rep(i, 1, n) rep(j, 1, n) e[i][j] = (i == j ? 0 : inf);
  rep(i, 1, n) {
    for (int idx = 0; idx < a[i].size(); idx++) {
      int v = a[i][idx].first, t = a[i][idx].second;
      for (int idx2 = 0; idx2 < id[v].size(); idx2++) {
        int v2 = id[v][idx2].first, t2 = id[v][idx2].second;
        if (i != v2) chkmin(e[i][v2], 1ll * t + t2), chkmin(e[v2][i], 1ll * t + t2);
      }
    }
  }
int T2 = clock();
  // cerr << e[1][2];
  rep(i, 1, n) Dij(i); 
  // Floyd();


  rep(_, 1, q) { // fast
    int u, v;
    cin >> u >> v; 
    ll ans = inf;
    for (int I = 0; I < id[u].size(); I++) {
      for (int J = 0; J < id[v].size(); J++) {
        int i = id[u][I].first, ti = id[u][I].second;
        int j = id[v][J].first, tj = id[v][J].second;
        chkmin(ans, ti + tj + dis[i][j]);
      }
    }
    cout << ans + w[u] + w[v] << '\n';
  }
int T3 = clock();
// cerr << 1. * (T3 - T1) / CLOCKS_PER_SEC;
  return 0;
}
// g++ subway.cpp -o subway -std=c++14 && ./subway