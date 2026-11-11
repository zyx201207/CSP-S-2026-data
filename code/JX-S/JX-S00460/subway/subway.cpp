#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N = 5e5 + 9, M = 509, inf = 0x3f3f3f3f3f3f3f3f;
int c, n, m, d, q, dst[M][M], w[N];
vector<pair<int, int>> es[N];
void upd(int &x, int y) {
  if (x > y) x = y;
}
signed main() {
#ifndef LOCAL
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
#endif
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> c >> n >> m >> d >> q;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
      if (i == j) dst[i][j] = 0;
      else dst[i][j] = inf;
    }
  for (int i = 1; i <= m; ++i) cin >> w[i];
  for (int i = 1; i <= n; ++i) {
    int k;
    cin >> k;
    for (int j = 1; j <= k; ++j) {
      int x, y;
      cin >> x >> y;
      es[x].emplace_back(i, y);
    }
  }
  for (int i = 1; i <= m; ++i) {
    for (int j = 0; j < es[i].size(); ++j) {
      for (int k = j + 1; k < es[i].size(); ++k) {
        upd(dst[es[i][j].first][es[i][k].first], es[i][j].second + es[i][k].second);
        upd(dst[es[i][k].first][es[i][j].first], es[i][j].second + es[i][k].second);
      }
    }
  }
  for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        upd(dst[i][j], dst[i][k] + dst[k][j]);
  while (q--) {
    int x, y, ans = inf;
    cin >> x >> y;
    for (auto [xu, xv] : es[x])
      for (auto [yu, yv] : es[y]) upd(ans, xv + yv + dst[xu][yu]);
    cout << ans + w[x] + w[y] << '\n';
  }
}