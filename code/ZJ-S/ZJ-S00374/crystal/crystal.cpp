#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

int main() {
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  i64 m;
  std::cin >> n >> m;

  std::vector<i64> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  std::sort(a.begin(), a.end());

  std::vector<i64> s(n + 1);
  for (int i = 0; i < n; i++) {
    s[i + 1] = s[i] + a[i];
  }

  auto check = [&](int mid) {
    for (int i = 0; i + mid <= n; i++) {
      if (a[i + mid - 1] * mid - (s[i + mid] - s[i]) <= m) {
        return true;
      }
    }
    return false;
  };

  int lo = 1, hi = n;
  while (lo < hi) {
    int mid = (lo + hi + 1) / 2;
    if (check(mid)) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }
  std::cout << hi << "\n";

  return 0;
}