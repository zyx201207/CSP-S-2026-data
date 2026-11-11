/*
finish at 15:17
int + int + int + int => long long!
*/
#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int, int>;

const int MAXN = 505, MAXM = 500005;
const i64 INF = i64(1e18);

int _C, n, m, d, q, www[MAXM];
i64 w[MAXN][MAXN];
vector<pii> ve[MAXM];

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  cin >> _C >> n >> m >> d >> q;
  for(int i = 1; i <= m; ++i) {
    cin >> www[i];
  }
  for(int i = 1, k; i <= n; ++i) {
    cin >> k;
    for(int j = 1, a, t; j <= k; ++j) {
      cin >> a >> t;
      ve[a].emplace_back(i, t);
    }
  }
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j) {
      w[i][j] = (i == j ? 0ll : INF);
    }
  }
  for(int i = 1; i <= m; ++i) {
    for(int x = 0; x < ve[i].size(); ++x) {
      for(int y = x + 1; y < ve[i].size(); ++y) {
        int u = ve[i][x].first, v = ve[i][y].first;
        w[u][v] = w[v][u] = min(w[u][v], 0ll + ve[i][x].second + ve[i][y].second);
      }
    }
  }
  for(int i = 1; i <= n; ++i) {
    for(int u = 1; u <= n; ++u) {
      for(int v = 1; v <= n; ++v) {
        w[u][v] = min(w[u][v], w[u][i] + w[i][v]);
      }
    }
  }
  for(int u, v; q--; ) {
    cin >> u >> v;
    i64 ans = INF;
    for(int x = 0; x < ve[u].size(); ++x) {
      for(int y = 0; y < ve[v].size(); ++y) {
        ans = min(ans, 0ll + www[u] + www[v] + ve[u][x].second + ve[v][y].second + w[ve[u][x].first][ve[v][y].first]);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
