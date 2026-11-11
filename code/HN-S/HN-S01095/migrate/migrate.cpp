#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e6 + 5;

int c, t, n;
ll d, a[N], f[N], g[N], ans;

int main() {
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  cin.tie(0)->ios::sync_with_stdio(0);
  for (cin >> c >> t; t--; ans = 0) {
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      int p = upper_bound(a + 1, a + n + 1, a[i] + d) - a - 1;
      if (p != i) {
        f[p] += f[i] + 1;
        if (i > 1) {
          int q = upper_bound(a + 1, a + n + 1, a[i - 1] + d) - a - 1;
          if (q == p) {
            f[p] -= f[i];
          }
        }
      }
    }
    for (int i = n; i >= 1; i--) {
      int p = lower_bound(a + 1, a + n + 1, a[i] - d) - a;
      if (p != i) {
        g[p] += g[i] + 1;
        if (i < n) {
          int q = lower_bound(a + 1, a + n + 1, a[i + 1] - d) - a;
          if (q == p) {
            g[p] -= g[i];
          }
        }
      }
    }
    for (int i = 3; i < n; i++) {
      int p = upper_bound(a + 1, a + n + 1, a[i - 1] + d) - a - 1;
      int q = lower_bound(a + 1, a + n + 1, a[i] - d) - a;
      if (p > i && q < i - 1) {
        int x = upper_bound(a + 1, a + n + 1, a[i] + d) - a - 1;
        int y = lower_bound(a + 1, a + n + 1, a[i - 1] - d) - a;
        if (y != q && x != p) {
          ans += max(f[i] - f[q], 0ll) * max(g[i - 1] - g[p], 0ll);
        } else if (y != q) {
          ans += max(f[i] - f[q], 0ll) * g[i - 1];
        } else if (x != p) {
          ans += f[i] * max(g[i - 1] - g[p], 0ll);
        } else {
          ans += f[i] * g[i - 1];
        }
      }
    }
    cout << ans << '\n';
    fill(f, f + n + 1, 0);
    fill(g, g + n + 1, 0);
  }
  return 0;
}
// g++ migrate.cpp -o migrate -std=c++14 -O2 -Wall -Wextra -fsanitize=address,undefined