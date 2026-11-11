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
  std::ignore = std::freopen("subway.in", "r", stdin);
  std::ignore = std::freopen("subway.out", "w", stdout);
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int c, n, m, d, q;
  std::cin >> c >> n >> m >> d >> q;
  std::vector<int> w(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> w[i];
  }
  std::vector<std::vector<std::pair<int, long long>>> e(n + m);
  for (int i = 0; i < n; ++i) {
    int k;
    std::cin >> k;
    e[m + i].resize(k);
    for (int j = 0; j < k; ++j) {
      int station;
      long long cost;
      std::cin >> station >> cost;
      --station;
      e[m + i][j] = std::make_pair(station, cost);
      e[station].emplace_back(m + i, cost);
    }
  }
  // for (int i = 0; i < n + m; ++i) {
  //   std::cerr << "e[" << i << "]:\n";
  //   for (auto edge : e[i]) {
  //     std::cerr << edge.first << ' ' << edge.second << '\n';
  //   }
  // }
  std::vector<std::vector<long long>> dis(n + m, std::vector<long long>(n + m, std::numeric_limits<long long>::max()));
  for (int i = 0; i < n; ++i) {
    std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> q;
    dis[i][i] = 0;
    q.emplace(0, i);
    while (!q.empty()) {
      auto cur = q.top();
      q.pop();
      int u = cur.second;
      long long dist = cur.first;
      // std::cerr << "pop heap: " << u << ',' << dist << ',' << dis[i][u] << '\n';
      if (dis[i][u] != dist) {
        continue;
      }
      // std::cerr << "now at " << u << ", dist = " << dist << '\n';
      for (auto edge : e[u]) {
        int v = edge.first;
	long long cost = edge.second;
        if (dis[i][v] > dist + cost) {
          dis[i][v] = dist + cost;
          q.emplace(dis[i][v], v);
        }
      }
    }
  }
  // for (int i = 0; i < n; ++i) {
  //   for (int j = 0; j < n + m; ++j) {
  //     std::cerr << dis[i][j] << ' ';
  //   }
  //   std::cerr.put(10);
  // }
  for (int test_case = 0; test_case < q; ++test_case) {
    // std::cerr << "case #" << test_case << '\n';
    int x, y;
    std::cin >> x >> y;
    if (x > y) {
      std::swap(x, y);
    }
    --x, --y;
    std::cout << dis[x][y] + w[x] + w[y] << '\n';
  }
  return 0;
}
