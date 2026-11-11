#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using PQ = pair<ll, int>;

void FileIO (string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 5e5 + 10, M = 510;
const ll INF = 1e18;

int TestID, n, m, d, q, w[N], sz[N];
ll dis[M][M], ans;
pii g[N][25];

signed main () {
  ios::sync_with_stdio(0), cin.tie(0);
  FileIO("subway");
  cin >> TestID >> m >> n >> d >> q;
  for (int i = 1; i <= n; i++)
    cin >> w[i];
  for (int i = 1, k; i <= m; i++) {
    for (int j = 1; j <= m; j++) dis[i][j] = INF;
    cin >> k, dis[i][i] = 0;
    for (int j = 1, x, y; j <= k; j++)
      cin >> x >> y, g[x][++sz[x]] = {i, y};
  }
  for (int i = 1; i <= n; i++)
    for (int x = 1; x <= sz[i]; x++)
      for (int y = 1; y <= sz[i]; y++)
        dis[g[i][x].first][g[i][y].first] = min(dis[g[i][x].first][g[i][y].first], 0ll + g[i][x].second + g[i][y].second);
  for (int k = 1; k <= m; k++)
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= m; j++)
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
  for (int i = 1, u, v; i <= q; i++) {
    cin >> u >> v, ans = INF;
    for (int x = 1; x <= sz[u]; x++)
      for (int y = 1; y <= sz[v]; y++)
        ans = min(ans, dis[g[u][x].first][g[v][y].first] + g[u][x].second + g[v][y].second);
    cout << ans + w[u] + w[v] << '\n'; 
  }
  return 0;
}
