// CatNyan Blesses Me!
// placeholder Blesses Me!
// Cubber Blesses Me!
// chenmohan201068 Blesses Me!
// clever_baka Blesses Me!
// DTL123 Blesses Me!
// Zheng_iii Blesses Me!
// Daylightning Blesses Me!
// xuanxuanni Blesses Me!
// _vector_ Blesses Me!
// cdx123456 Blesses Me!
// tourist Blesses Me!
// jiangly Blesses Me!
// CCF Blesses Me!

// 我怎么20min 胡出来了做法
// 又是和去年一样的情景，我能做出来吗？ CCF 求你让我过吧

// freopen();
// freopen();

#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using real = long double;

void solve() {
  constexpr static i64 inf = 0x3f3f3f3f3f3f3f3f;

  int n, m, d, q;
  std::cin >> n >> m >> d >> q;
  std::vector<i64> w(m + 1, 0);
  for (int i = 1; i <= m; ++i) std::cin >> w[i];
  std::vector<std::vector<i64>> adj(n + 1, std::vector<i64>(n + 1, inf));  // O(n^2)
  std::vector<std::vector<std::pair<int, i64>>> sta(m + 1);                // O(md)
  for (int i = 1; i <= n; ++i) {
    int k;
    std::cin >> k;
    for (int j = 1; j <= k; ++j) {
      int seetulip, t;
      std::cin >> seetulip >> t;
      sta[seetulip].emplace_back(i, t);
    }
  }

  for (int i = 1; i <= m; ++i) {
    int sz = (int)sta[i].size();
    for (int a = 0; a < sz; ++a)
      for (int b = a + 1; b < sz; ++b)
        adj[sta[i][b].first][sta[i][a].first] =
            adj[sta[i][a].first][sta[i][b].first] =
                std::min(adj[sta[i][a].first][sta[i][b].first], sta[i][a].second + sta[i][b].second);
  }

  std::vector<std::vector<i64>> dist = adj;
  for (int i = 1; i <= n; ++i) dist[i][i] = 0;
  for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);

  while (q--) {
    int x, y;
    std::cin >> x >> y;
    i64 ans = w[x] + w[y];
    int sz1 = (int)sta[x].size();
    int sz2 = (int)sta[y].size();
    i64 adding = inf;
    for (int a = 0; a < sz1; ++a)
      for (int b = 0; b < sz2; ++b)
        adding = std::min(adding, dist[sta[x][a].first][sta[y][b].first] + sta[x][a].second + sta[y][b].second);
    std::cout << ans + adding << '\n';
    // std::cerr << ans << '\n';
    // std::cerr << adding << '\n';
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  assert(std::freopen("subway.in", "r", stdin));
  assert(std::freopen("subway.out", "w", stdout));

  int xlx;
  std::cin >> xlx;
  int t = 1;
  while (t--) {
    solve();
  }

  return 0;
}

// wo chang chang zhui yi guo qu