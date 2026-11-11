#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using i64 = long long;
const int N = 505;
const int M = 5e5 + 5;
const int Q = 1e5 + 5;
const i64 inf = 1e18;

int c, n, m, d, q; i64 ans[Q], w[M];
vector<pair<int, i64>> a[N], e[M];
vector<pair<int, int>> qu[M];
i64 f[N][N], g[M];

int main() {
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> c >> n >> m >> d >> q;
  F(i, 1, m) cin >> w[i], e[i].reserve(d);
  F(i, 1, n) {
    int k; cin >> k, a[i].resize(k);
    F(j, 0, k - 1) {
      int u; i64 t; cin >> u >> t;
      a[i][j] = {u, t}, e[u].push_back({i, t});
    }
  }
  F(i, 1, q) {
    int u, v; cin >> u >> v;
    qu[u].push_back({v, i}), ans[i] = inf;
  }

  F(i, 1, n) F(j, 1, n) f[i][j] = inf;
  F(i, 1, n) f[i][i] = 0;
  F(i, 1, n) for (auto [u, x] : a[i])
    for (auto [j, y] : e[u])
      f[i][j] = min(f[i][j], x + y);
  F(k, 1, n) F(i, 1, n) F(j, 1, n)
    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);

  F(i, 1, n) {
    F(u, 1, m) g[u] = inf;
    F(j, 1, n)
      for (auto [u, x] : a[j])
        g[u] = min(g[u], f[i][j] + x);
    for (auto [u, x] : a[i])
      for (auto [v, id] : qu[u])
        ans[id] = min(ans[id], w[u] + w[v] + x + g[v]);
  }

  F(i, 1, q) cout << ans[i] << "\n";
  return 0;
}