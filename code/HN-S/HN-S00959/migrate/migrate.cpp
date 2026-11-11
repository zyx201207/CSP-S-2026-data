#include <bits/stdc++.h>
#define int long long

using namespace std;

const int kMaxN = 2e6 + 5;

int c, t, n, d, x[kMaxN], p[kMaxN], v[kMaxN], w[kMaxN], o[kMaxN];

signed main() {
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  cin.tie(0) -> sync_with_stdio(0);
  for (cin >> c >> t; t--;) {
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
      cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
      p[i] = lower_bound(x + 1, x + n + 1, x[i] - d) - x;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      fill(v + 1, v + i + 1, 0);
      fill(w + 1, w + i + 1, 1e9);
      fill(o + 1, o + i + 2, 0);
      v[i] = 1, w[i] = 0;
      int l = 1e9, r = 1e9;
      for (int j = i; j >= 1; j--) {
        o[j] += o[j + 1];
        v[j] += o[j];
        if (w[j] != 1e9) {
          int _l = l;
          if (w[j] == w[j + 1] && j < i) {
            l = p[j], r = min(r, j - 1);
          } else {
            r = min(l - 1, j - 1), l = p[j];
          }
          for (int k = l; k <= min(_l - 1, r); k++) {
            w[k] = w[j] + 1;
          }
          o[r] += v[j], o[l - 1] -= v[j];
        }
        if (v[j] == 2) {
          ans++;
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}