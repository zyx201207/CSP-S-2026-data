#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

constexpr i64 inf = 1E18;

int main() {
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int c, n, m, d, q;
  std::cin >> c >> n >> m >> d >> q;

  std::vector<int> w(m);
  for (int i = 0; i < m; i++) {
    std::cin >> w[i];
  }

  std::vector<std::vector<std::array<int, 2>>> adj(m);
  for (int i = 0; i < n; i++) {
    int k;
    std::cin >> k;
    for (int j = 0; j < k; j++) {
      int a, t;
      std::cin >> a >> t;
      a--;
      adj[a].push_back({i, t});
    }
  }

  std::vector<std::vector<i64>> g(n, std::vector<i64>(n, inf));
  for (int i = 0; i < n; i++) {
    g[i][i] = 0;
  }

  for (int i = 0; i < m; i++) {
    int t = adj[i].size();
    for (int x = 0; x < t; x++) {
      for (int y = x + 1; y < t; y++) {
        int u = adj[i][x][0], v = adj[i][y][0];
        if (u != v) {
          int w = adj[i][x][1] + adj[i][y][1];
          g[u][v] = std::min<i64>(g[u][v], w);
          g[v][u] = std::min<i64>(g[v][u], w);
        }
      }
    }
  }

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        g[i][j] = std::min(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }

  while (q--) {
    int s, t;
    std::cin >> s >> t;
    s--;
    t--;
    i64 ans = inf;
    for (auto i : adj[s]) {
      for (auto j : adj[t]) {
        ans = std::min(ans, g[i[0]][j[0]] + i[1] + j[1]);
      }
    }
    std::cout << ans + w[s] + w[t] << "\n";
  }

  return 0;
}