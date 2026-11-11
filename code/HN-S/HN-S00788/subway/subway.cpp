#include <bits/stdc++.h>
#define int long long

const int kMaxN = 5e2 + 25, kMaxM = 5e5 + 25;

int tid, n, m, d, q, w[kMaxM], len[kMaxN], dis[kMaxN][kMaxN];
std::vector<std::pair<int, int>> v[kMaxM];

signed main() {
  std::cin.tie(0)->sync_with_stdio(false);
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  std::cin >> tid >> n >> m >> d >> q;
  for (int i = 1; i <= m; i++) {
    std::cin >> w[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> len[i];
    for (int j = 1, x, y; j <= len[i]; j++) {
      std::cin >> x >> y, v[x].emplace_back(i, y);
    }
  }
  for (int i = 1; i <= n; i++)  {
    for (int j = 1; j <= n; j++) {
      dis[i][j] = 1e18;
    }
    dis[i][i] = 0;
  }
  for (int i = 1; i <= m; i++) {
    for (auto x : v[i]) {
      for (auto y : v[i]) {
        if (x.first != y.first) {
          dis[x.first][y.first] = std::min(dis[x.first][y.first], x.second + y.second);
          dis[y.first][x.first] = std::min(dis[y.first][x.first], x.second + y.second);
        }
      }
    }
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
  for (int x, y; q--;) {
    std::cin >> x >> y;
    int ans = 1e18;
    for (auto i : v[x]) {
      for (auto j : v[y]) {
        ans = std::min(ans, dis[i.first][j.first] + i.second + j.second);
      }
    }
    std::cout << ans + w[x] + w[y] << '\n';
  }
  return 0;
}
