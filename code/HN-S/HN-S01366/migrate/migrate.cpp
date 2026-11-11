#include <bits/stdc++.h>
using namespace std;

#define int long long

int x[2000000];

signed main() {
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  cin.tie(nullptr)->sync_with_stdio(false);
  int c, t;
  cin >> c >> t;
  while (t --) {
    int n, d;
    cin >> n >> d;
    for (int i = 0; i != n; ++ i) {
      cin >> x[i];
    }
    if (n / d < 2) {
      cout << 0 << '\n';
      continue;
    }
    int ans = 0;
    for (int i = 0; i <= n - d * 2; ++ i) {
      int j;
      for (j = i + 1; j != i + d *2; ++ j) {
        if (x[j] - x[j - 1] != 1) break;
      }
      if (j == i + d * 2) {
        ++ ans;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
