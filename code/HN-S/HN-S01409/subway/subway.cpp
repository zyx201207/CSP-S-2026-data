// subway
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

using ll = long long;

const int N = 5e2 + 3, M = 5e5 + 3;

const ll INF = 1e18 + 3;

struct Edge{
  int u;
  ll v;
};

vector<Edge> a[M];

ll w[M];

ll dp[N][N];

int c, n, m, d, q;

int main () {
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  cin >> c >> n >> m >> d >> q;
  for (int i = 1; i <= m; i++) {
    cin >> w[i];
  }
  for (int i = 1, k, u; i <= n; i++) {
    Edge p;
    cin >> k, p.u = i;
    for (int j = 1; j <= k; j++) {
      cin >> u >> p.v;
      a[u].push_back(p);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i != j) dp[i][j] = INF;
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < a[i].size(); j++) {
      for (int k = 0; k < j; k++) {
        dp[a[i][j].u][a[i][k].u] = dp[a[i][k].u][a[i][j].u] = min(dp[a[i][j].u][a[i][k].u], a[i][j].v + a[i][k].v); // ´ýÓÅ»¯ 2e8
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }
  while (q--) {
    int x, y;
    ll ans = INF;
    cin >> x >> y;
    for (int i = 0; i < a[x].size(); i++) {
      for (int j = 0; j < a[y].size(); j++) {
        ans = min(ans, a[x][i].v + a[y][j].v + dp[a[x][i].u][a[y][j].u]);
      }
    }
    cout << ans + w[x] + w[y] << '\n';
  }
  return 0;
}
