#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long;
constexpr ll inf = 4e18;
constexpr int N = 5e5 + 5;
constexpr int M = 500 + 5;

int sub_id, n, m, max_deg, q, w[N];
vector<pair<int, int>> d[N];
ll dis[M][M];

void solve_main() {
  cin >> sub_id >> n >> m >> max_deg >> q;
  for (int i = 1; i <= m; ++i) {
    cin >> w[i];
    d[i].reserve(20);
  }
  for (int i = 1; i <= n; ++i) {
    int k;
    cin >> k;
    for (int j = 1; j <= k; ++j) {
      int x, v;
      cin >> x >> v;
      d[x].emplace_back(i, v);
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i == j) {
        dis[i][j] = 0;
      } else {
        dis[i][j] = inf;
      }
    }
  }

  for (int i = 1; i <= m; ++i) {
    for (auto tmpx : d[i]) {
      for (auto tmpy : d[i]) {
        dis[tmpx.first][tmpy.first] = min(dis[tmpx.first][tmpy.first], 1ll * tmpx.second + 1ll * tmpy.second);
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int k = 1; k <= n; ++k) {
        dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
      }
    }
  }

  while (q--) {
    int x, y;
    cin >> x >> y;
    ll ans = inf;

    for (auto tmpx : d[x]) {
      for (auto tmpy : d[y]) {
        ans = min(ans, dis[tmpx.first][tmpy.first] + tmpx.second + tmpy.second);
      }
    }

    ans += w[x];
    ans += w[y];
    cout << ans << '\n';
  }
}

int main() {
  assert(freopen("subway.in", "r", stdin));
  assert(freopen("subway.out", "w", stdout));
  cin.tie(nullptr)->sync_with_stdio(false);
  solve_main();
  return 0;
}