#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
const int inf = 1e18;
using info = pair<int, int>;

signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("subway.in", "r", stdin), freopen("subway.out", "w", stdout);
  int c, n, m, d, q; cin >> c >> n >> m >> d >> q;
  vector<int> w(m + 1);
  for (int i = 1; i <= m; i++) cin >> w[i];
  vector<vector<int>> dis(n + 1, vector<int>(n + 1, inf));
  for (int i = 1; i <= n; i++) dis[i][i] = 0;
  vector<vector<info>> vec(m + 1);
  for (int i = 1; i <= n; i++) {
    int k; cin >> k;
    while (k--) {
      int a, t; cin >> a >> t;
      vec[a].push_back({i, t});
    }
  }
  for (int i = 1; i <= m; i++) {
    int k = vec[i].size();
    for (auto [u, x] : vec[i]) for (auto [v, y] : vec[i])
      dis[u][v] = min(dis[u][v], x + y);
  }

  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
  
  while (q--) {
    int x, y, ans = inf; cin >> x >> y;
    for (auto [u, i] : vec[x])
      for (auto [v, j] : vec[y]) ans = min(ans, dis[u][v] + i + j);
    cout << ans + w[x] + w[y] << endl;
  }
  return 0;
}