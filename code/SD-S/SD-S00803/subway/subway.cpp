#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
const int N = 500 + 7, M = 5e5 + 7;
int id, n, m, d, q;
int w[M];
vector<pair<int, int>> g[M];
int f[N][N];
signed main() {
//  system("fc subway.out subway.ans");
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> id >> n >> m >> d >> q;
  for (int i = 1; i <= m; ++ i) {
    cin >> w[i];
  } 
  for (int i = 1, k, u, t; i <= n; ++ i) {
    cin >> k;
    while (k --) {
      cin >> u >> t;
      g[u].emplace_back(i, t);
    }
  }
  for (int i = 1; i <= n; ++ i) {
    for (int j = 1; j <= n; ++ j) {
      if (i == j) {
        continue;
      }
      f[i][j] = 1e18;
    }
  }
  for (int i = 1; i <= m; ++ i) {
    for (pair<int, int> x : g[i]) {
      int u = x.first, t1 = x.second;
      for (pair<int, int> y : g[i]) {
        int v = y.first, t2 = y.second;
        f[u][v] = min(f[u][v], t1 + t2);
      }
    }
  }
  for (int k = 1; k <= n; ++ k) {
    for (int u = 1; u <= n; ++ u) {
      for (int v = 1; v <= n; ++ v) {
        f[u][v] = min(f[u][v], f[k][u] + f[k][v]);
      }
    }
  }
  while (q --) {
    int i, j;
    cin >> i >> j;
    int res = 1e18;
    for (pair<int, int> x : g[i]) {
      int u = x.first, t1 = x.second;
      for (pair<int, int> y : g[j]) {
        int v = y.first, t2 = y.second;
        res = min(res, w[i] + t1 + f[u][v] + t2 + w[j]);
      }
    }
    cout << res << '\n';
  }
  return 0;
}

