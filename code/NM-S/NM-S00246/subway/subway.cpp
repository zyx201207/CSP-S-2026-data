#include <bits/stdc++.h>
using namespace std;

const int SIZE = 5e4 + 510;
int w[510];
int c, n, m, d, q;

struct Node {
  int id, cost;
};
vector<Node> adj[SIZE];

bool stations[SIZE], lines[510];

int ans = INT_MAX;
int dfs(int u, int cost, int target) {
  if (cost >= ans) return ans;
  if (u == target) { ans = min(ans, cost); return cost; }
  int res = INT_MAX;
  for (auto p : adj[u]) {
    int v = p.id, w = p.cost;
    if ((v <= m && stations[v]) || (v > m && lines[v - m])) continue;

    if (v <= m) stations[v] = true;
    else lines[v - m] = true;

    res = min(res, dfs(v, cost + w, target));

    if (v <= m) stations[v] = false;
    else lines[v - m] = false;
  }

  return res;
}

signed main() {
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);

  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> c >> n >> m >> d >> q;
  for (int i = 1; i <= m; i++) cin >> w[i];

  for (int i = 1; i <= n; i++) {
    int k; cin >> k;
    int u = i + m;
    for (int j = 1; j <= k; j++) {
      int v, t; cin >> v >> t;
      adj[u].push_back({v, t}), adj[v].push_back({u, t});
    }
  }

  while (q--) {
    int x, y; cin >> x >> y;
    // memset(stations, 0, sizeof stations);
    // memset(lines, 0, sizeof lines);
    ans = INT_MAX;
    cout << dfs(x, 0, y) + w[x] + w[y] << '\n';
  }

  return 0;
}
