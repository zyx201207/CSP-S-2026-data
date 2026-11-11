#include <bits/stdc++.h>
#define int long long

using namespace std;

const int kMaxN = 505, kM = 5e5 + 5, kInf = 1e18;

int c, n, m, d, q, w[kM], f[kMaxN][kMaxN];

struct S {
  int p, t;
};

vector<S> s[kM];

signed main() {
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  cin.tie(0) -> sync_with_stdio(0);
  cin >> c >> n >> m >> d >> q;
  for (int i = 1; i <= m; i++) {
    cin >> w[i];
  }
  for (int i = 1, k; i <= n; i++) {
    cin >> k;
    for (int a, t; k--;) {
      cin >> a >> t;
      s[a].push_back({i, t});
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      f[i][j] = kInf;
    }
    f[i][i] = 0;
  }
  for (int i = 1; i <= m; i++) {
    for (S x : s[i]) {
      for (S y : s[i]) {
        f[x.p][y.p] = min(f[x.p][y.p], x.t + y.t);
      }
    }
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
      }
    }
  }
  for (int x, y; q--;) {
    cin >> x >> y;
    int ans = kInf;
    for (S i : s[x]) {
      for (S j : s[y]) {
        ans = min(ans, i.t + j.t + f[i.p][j.p]);
      }
    }
    cout << ans + w[x] + w[y] << "\n";
  }
  return 0;
}