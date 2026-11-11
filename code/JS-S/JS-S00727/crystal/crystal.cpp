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

// freopen();
// freopen();

#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using real = long double;

void solve() {
  int n;
  i64 m;
  std::cin >> n >> m;
  std::vector<i64> a(n + 1, 0);
  for (int i = 1; i <= n; ++i) std::cin >> a[i];
  std::sort(a.begin() + 1, a.end());
  std::vector<i64> d(n + 1, 0);
  for (int i = 1; i <= n; ++i) d[i] = a[i] - a[i - 1];
  i64 now_use = 0;
  i64 ans = 0;
  int l = 1, r = 1;
  i64 len = 1;
  while (r < n) {
    while (r < n and len * d[r + 1] + now_use <= m) {
      now_use += len * d[r + 1];
      ++r;
      ++len;
    }
    ans = std::max(ans, len);
    ++l;
    now_use -= a[r] - a[l];
    --len;
  }

  std::cout << ans << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  assert(std::freopen("crystal.in", "r", stdin));
  assert(std::freopen("crystal.out", "w", stdout));

  int t = 1;
  while (t--) {
    solve();
  }

  return 0;
}

// wo chang chang zhui yi guo qu