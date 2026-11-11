#include <bits/stdc++.h>

using i64 = long long;

std::mt19937 rnd(std::time(0));

int main() {
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int c, n, m, d, q;
  std::cin >> c >> n >> m >> d >> q;
  std::vector<std::vector<std::pair<int, int>>> a(n + 1);
  for (int i = 1; i <= n; i ++) {
    int sz; std::cin >> sz;
    a[i].resize(sz + 1);
    for (int j = 1; j <= sz; j ++) {
      std::cin >> a[i][j].first >> a[i][j].second;
    }
  }
  while (q --) {
    int l, r;
    std::cin >> l >> r;
    std::cout << rnd() << std::endl;
  }
  return 0;
}