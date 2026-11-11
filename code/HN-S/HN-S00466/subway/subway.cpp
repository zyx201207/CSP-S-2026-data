#include <bits/stdc++.h>

using namespace std;;

using ll = long long;
using ull = unsigned long long;

const int kMaxN = 550, kMaxM = 5e5 + 50;

ll c, n, m, d, q, w[kMaxM], dis[kMaxN][kMaxN], ans;
vector<pair<ll, ll>> line[kMaxM];

int main() {
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> c >> n >> m >> d >> q;
  for (int i = 1; i <= m; ++ i) {
    cin >> w[i];
  }
  for (ll i = 1, k; i <= n; ++ i) {
    for (int j = 1; j <= n; ++ j) {
      dis[i][j] = 1e18;
    }
    dis[i][i] = 0;
    cin >> k;
    for (ll j = 1, x, y; j <= k; ++ j) {
      cin >> x >> y;
      line[x].push_back({i, y});
    }
  }
  for (int k = 1; k <= m; ++ k) {
    for (auto i : line[k]) {
      for (auto j : line[k]) {
        if (i.first == j.first) {
          continue;
        }
        dis[i.first][j.first] = min(dis[i.first][j.first], i.second + j.second);
        dis[j.first][i.first] = min(dis[j.first][i.first], i.second + j.second);
      }
    }
  }
  for (int k = 1; k <= n; ++ k) {
    for (int i = 1; i <= n; ++ i) {
      for (int j = 1; j <= n; ++ j) {
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
  for (ll x, y; q; -- q) {
    cin >> x >> y, ans = 1e18;
    for (auto i : line[x]) {
      for (auto j : line[y]) {
        ans = min(ans, w[x] + w[y] + i.second + j.second + dis[i.first][j.first]);
      }
    }
    cout << ans << '\n';
  }
  return 0; 
}
