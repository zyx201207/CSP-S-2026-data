#include <bits/stdc++.h>
#define int long long

using namespace std;

const int kMaxN = 2e6 + 5;

int c, t, n, d, x[kMaxN], p[kMaxN], v[kMaxN], w[kMaxN], ti[kMaxN], b[kMaxN];
vector<int> o;

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
    fill(b + 1, b + n + 1, 0), fill(ti + 1, ti + n + 1, 0);
    for (int i = 1; i <= n; i++) {
      v[i] = 1, w[i] = 0;
      o.clear();
      for (int x = i; p[x] != x; x = p[x]) {
        if (b[x + 2] != i && x + 2 <= i) {
          b[x + 2] = i;
          o.push_back(x + 2);
        }
        if (b[x + 1] != i && x + 1 <= i) {
          b[x + 1] = i;
          o.push_back(x + 1);
        }
        if (b[x] != i && x <= i) {
          b[x] = i;
          o.push_back(x);
        }
      }
      for (int x : o) {
        for (int k = p[x]; k <= min(x - 1, p[x] + 2); k++) {
          if (ti[k] != i) {
            w[k] = 1e9, v[k] = 0, ti[k] = i;
          }
          if (w[k] < w[x] + 1) break;
          ans -= v[k] == 2;
          if (w[k] == w[x] + 1) {
            v[k] += v[x];
          } else {
            w[k] = w[x] + 1, v[k] = v[x];
          }
          ans += v[k] == 2;
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
