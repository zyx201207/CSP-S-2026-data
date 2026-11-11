#include <bits/stdc++.h>
// #define MEMORY
using namespace std;
using LL = long long;
using Pii = pair<LL, LL>;
bool Mbe;

const int N = 505, M = 5e5 + 5;
LL tid, n, m, k, q, tot, a[M], d[N][N];
vector<pair<LL, LL>> h[M];

bool Med;
int main() {
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
#ifdef MEMORY
  cerr << abs(&Mbe - &Med) / 1048576.0 << "\n";
#endif
  cin.tie(0)->sync_with_stdio(0);
  cin >> tid >> n >> m >> k >> q;
  for (int i = 1; i <= m; i++) cin >> a[i];
  for (int i = 1, k; i <= n; i++) {
    cin >> k;
    for (int x, t; k; k--) {
      cin >> x >> t, h[x].push_back({i, t});
    }
    fill(d[i] + 1, d[i] + n + 1, 1e18), d[i][i] = 0;
  }
  for (int i = 1; i <= m; i++) {
    for (auto [x, t1] : h[i]) {
      for (auto [y, t2] : h[i]) {
        d[x][y] = min(d[x][y], t1 + t2);
      }
    }
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

  for (int x, y; q; q--) {
    cin >> x >> y;
    LL ans = 1e18;
    for (auto [i, t1] : h[x]) {
      for (auto [j, t2] : h[y]) {
        ans = min(ans, d[min(i, j)][max(i, j)] + t1 + t2);
      }
    }
    cout << ans + a[x] + a[y] << "\n";
  }
  return 0;
}
// xyz love zrr