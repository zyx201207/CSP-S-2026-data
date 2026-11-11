#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, ll>;

const int MAXN = 5e5 + 10, MAXV = 5e2 + 10;
const ll INF = 1e18;

int c, n, m, d, q, w[MAXN];
ll dis[MAXV][MAXV];
vector<pii> g[MAXN + MAXV];

int main() {
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> c >> n >> m >> d >> q;
  for (int i = 1; i <= m; cin >> w[i++]);
  for (int i = 1, k; i <= n; i++) {
    cin >> k;
    int u = m + i;
    for (int j = 1, v, t; j <= k; j++) {
      cin >> v >> t;
      g[u].push_back({v, t});
      g[v].push_back({u, t});
    }
    fill(dis[i] + 1, dis[i] + n + 1, INF);
    dis[i][i] = 0;
  }
  for (int k = 1; k <= m; k++) {
    for (auto &[i, w1] : g[k]) {
      for (auto &[j, w2] : g[k]) {
        if (i == j) continue;
        dis[i - m][j - m] = min(dis[i - m][j - m], w1 + w2);
        dis[j - m][i - m] = min(dis[j - m][i - m], w1 + w2);
      }
    }
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
  for (int i = 1, x, y; i <= q; i++) {
    cin >> x >> y;
    ll ans = INF;
    for (auto &[k1, w1] : g[x]) {
      for (auto &[k2, w2] : g[y]) {
        ans = min(ans, dis[k1 - m][k2 - m] + w[x] + w[y] + w1 + w2);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
