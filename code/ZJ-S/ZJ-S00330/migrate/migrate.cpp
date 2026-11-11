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
  std::ignore = std::freopen("migrate.in", "r", stdin);
  std::ignore = std::freopen("migrate.out", "w", stdout);
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int c, t;
  std::cin >> c >> t;
  while (t--) {
    int n;
    long long d;
    std::cin >> n >> d;
    std::vector<long long> a(n);
    for (auto &x : a) {
      std::cin >> x;
    }
    long long ans = 0;
    std::vector<int> block(1, {0});
    for (int i = 0; i < n; ++i) {
      if (i + 3 < n && a[i + 2] - a[i] <= d && a[i + 3] - a[i + 1] <= d && a[i + 3] - a[i] > d) {
        ++block.back();
        block.emplace_back(0);
      } else {
        ++block.back();
      }
    }
    for (int i = 1; i < static_cast<int>(block.size() + 1); ++i) {
      ans += block[i - 1] * block[i];
    }
    std::cout << ans << '\n';
  }
  return 0;
}
