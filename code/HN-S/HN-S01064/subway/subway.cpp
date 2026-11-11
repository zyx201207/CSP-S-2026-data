#include<bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;

const ll INF = ll(1e15);
const int MAXN = 505, MAXM = 5e5 + 5;

int timesta[MAXM];
vector<pair<int, int>> g[MAXM];
int Tid, nsub, nsta, ooo, T;
ll dis[MAXN][MAXN];

int main() {
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> Tid >> nsub >> nsta >> ooo >> T;
  for (int i = 1; i <= nsta; i++) cin >> timesta[i];
  for (int i = 1, k, u, t; i <= nsub; i++) {
    cin >> k;
    while (k--) {
      cin >> u >> t;
      g[u].push_back({i, t});
    }
  }
  for (int i = 1; i <= nsub; i++) for (int j = 1; j <= nsub; j++) {
    dis[i][j] = INF * (i != j);
  }
  for (int i = 1; i <= nsta; i++) {
    for (auto &[u, t1] : g[i]) for (auto &[v, t2] : g[i]) {
      dis[u][v] = min(dis[u][v], 0ll + t1 + t2);
    }
  }
  for (int k = 1; k <= nsub; k++) {
    for (int i = 1; i <= nsub; i++) for (int j = 1; j <= nsub; j++) {
      dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    }
  }
  for (int u, v; T--; ) {
    cin >> u >> v;
    ll ans = INF;
    for (auto &[x, t1] : g[u]) for (auto &[y, t2] : g[v]) {
      ans = min(ans, dis[x][y] + t1 + t2);
    }
    cout << ans + timesta[u] + timesta[v] << '\n';
  }
  return 0;
}