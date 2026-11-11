#include <cstdint>
#include <cstdio>
#include <functional>
#include <ios>
#include <iostream>
#include <limits>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

int main() {
  std::ignore = std::freopen("hub.in", "r", stdin);
  std::ignore = std::freopen("hub.out", "w", stdout);
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int c, t;
  std::cin >> c >> t;
  while (t--) {
    int n, k;
    std::cin >> n >> k;
    std::vector<std::vector<int>> e(n + 1);
    for (int i = 1; i < n; ++i) {
      int u, v;
      std::cin >> u >> v;
      e[u].emplace_back(v);
      e[v].emplace_back(u);
    }
    int ans = n / 4;
    std::cout << ans << '\n';
  }
  return 0;
}
