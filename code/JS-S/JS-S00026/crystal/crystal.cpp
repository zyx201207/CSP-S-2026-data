#include <bits/stdc++.h>

using i64 = long long;

int main() {
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "r", stdout);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  i64 n, m;
  std::cin >> n >> m;
  std::vector<i64> a(n + 1);
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  std::sort(a.begin(), a.end());
  std::vector<i64> pre(n + 1);
  for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
  int lo = 1, hi = n;
  auto check = [&](int x) -> bool {
    for (int i = 1; i <= n - x; i++) {
      if (x * a[i + x - 1] - (pre[i + x - 1] - pre[i - 1]) <= m)
        return true;
    }
    return false;
  };
  while (lo <= hi) {
    int mid = (hi - lo) / 2 + lo;
    if (check(mid))
      lo = mid + 1;
    else
      hi = mid - 1;
  }
  std::cout << hi << std::endl;
  return 0;
}