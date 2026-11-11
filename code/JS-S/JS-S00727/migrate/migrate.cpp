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
  i64 d;
  std::cin >> n >> d;
  std::vector<i64> x(n + 1, 0);
  for (int i = 1; i <= n; ++i) std::cin >> x[i];
  std::vector<int> R(n + 1, 0);
  {
    int l = 1, r = 1;
    while (l <= n) {
      while (r <= n and x[r] - x[l] <= d) ++r;
      R[l] = r - 1;
      ++l;
    }
  }
  // for (int i = 1; i <= n; ++i) std::cerr << R[i] << " \n"[i == n];
  std::vector<std::vector<int> > g(n + 1, std::vector<int>(n + 1, 0));
  i64 ans = 0;
  for (int l = 1; l <= n; ++l) {
    for (int r = l + 1; r <= n; ++r) {
      int cnt = 0;
      int nl = l;
      while (nl < r) {
        if (nl == R[nl]) {
          cnt = -1;
          break;
        }
        nl = R[nl], ++cnt;
      }
      g[r][l] = g[l][r] = cnt;
    }
  }

  // for (int l = 1; l <= n; ++l)
  //   for (int r = 1; r <= n; ++r) std::cerr << g[l][r] << " \n"[r == n];

  for (int l = 1; l <= n; ++l) {
    for (int r = 1; r <= n; ++r) {
      int nl = l;
      int can = 1;
      bool flag = false;
      bool flag2 = false;
      while (R[nl] < r) {
        if (nl == R[nl]) {
          can = 0;
          flag2 = true;
          break;
        }
        if (R[nl] - nl > 1) {
          if (g[R[nl]][r] == g[R[nl] - 1][r]) {
            if (flag) {
              can = 0;
              break;
            } else
              flag = true;
          }
        }
        if (R[nl] - nl > 2) {
          if (g[R[nl] - 2][r] == g[R[nl]][r]) {
            can = 0;
            break;
          }
        }

        nl = R[nl];
      }

      if (flag2) break;
      if (flag) {
        ans += can;
        // if (can)
        //   std::cerr << l << ' ' << r << '\n';
      }
    }
  }

  std::cout << ans << '\n';
  // std::cerr << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  assert(std::freopen("migrate.in", "r", stdin));
  assert(std::freopen("migrate.out", "w", stdout));

  int c;
  int t = 1;
  std::cin >> c >> t;
  while (t--) {
    solve();
  }

  return 0;
}

// wo chang chang zhui yi guo qu