#include <bits/stdc++.h>
using namespace std;
template <typename T> void ckmn(T& x, T y) { (y < x) && (x = y); }
template <typename T> void ckmx(T& x, T y) { (y > x) && (x = y); }
using ll = long long;
const int N = 500, M = 500000;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
int c, n, m, d, q;
int w[M + 5];
struct edge { int v, w; };
vector<edge> G[M + 5];
ll dis[N + 5][N + 5];
int main() {
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> c >> n >> m >> d >> q;
  for (int i = 1; i <= m; i++) cin >> w[i];
  for (int i = 1, k; i <= n; i++) {
    cin >> k;
    for (int j = 1, a, t; j <= k; j++) {
      cin >> a >> t;
      G[a].push_back((edge){i, t});
    }
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      dis[i][j] = (i == j ? 0ll : INF);
  for (int i = 1; i <= m; i++) {
    for (int j = 0, x, y; j < (int)G[i].size(); j++) {
      for (int k = j + 1; k < (int)G[i].size(); k++) {
        x = G[i][j].v, y = G[i][k].v;
        ckmn(dis[x][y], (ll)G[i][j].w + G[i][k].w);
        ckmn(dis[y][x], (ll)G[i][j].w + G[i][k].w);
        // cerr << "? : " << x << " --> " << y<< ", w = " << (ll)G[i][j].w + G[i][k].w << '\n';
      }
    }
  }
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        ckmn(dis[i][j], dis[i][k] + dis[k][j]);
  ll ans = 0; int x, y; while (q--) {
    cin >> x >> y;
    ans = INF;
    for (auto& tx : G[x])
      for (auto& ty : G[y])
        ckmn(ans, dis[tx.v][ty.v] + tx.w + ty.w);
    cout << ans + w[x] + w[y] << '\n';
  }
  return 0;
} // g++ subway.cpp -o subway -std=c++14 -O2 -static -Wall -Wextra