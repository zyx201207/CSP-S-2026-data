#include <algorithm>
#include <vector>

using namespace std;

#ifdef LOCAL_IO
#include <iostream>
#else
#include <fstream>

const string kFILE = "subway";
ifstream cin(kFILE + ".in");
ofstream cout(kFILE + ".out");
#endif

int main() {
  cin.tie(0)->sync_with_stdio(0);
  using ll = long long;

  int tid, n, m, dm, q;
  cin >> tid >> n >> m >> dm >> q;
  vector<int> w(m);
  for (int &i : w) {
    cin >> i;
  }
  vector<vector<pair<int, int>>> e(m);
  for (int i = 0, k; i < n; ++i) {
    cin >> k;
    for (int j = 0, x, t; j < k; ++j) {
      cin >> x >> t;
      e[x - 1].emplace_back(i, t);
    }
  }
  vector<vector<ll>> d(n, vector<ll>(n, 1e18));
  for (int i = 0; i < n; ++i) {
    d[i][i] = 0;
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < e[i].size(); ++j) {
      for (int k = 0; k < j; ++k) {
        auto [x0, t0] = e[i][j];
        auto [x1, t1] = e[i][k];
        d[x0][x1] = d[x1][x0] = min(d[x0][x1], (ll)t0 + t1);
      }
    }
  }
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  for (int x, y; q--; ) {
    cin >> x >> y, --x, --y;
    ll ans = 1e18;
    for (auto [i, t0] : e[x]) {
      for (auto [j, t1] : e[y]) {
        ans = min(ans, t0 + d[i][j] + t1);
      }
    }
    cout << w[x] + w[y] + ans << '\n';
  }
  return 0;
}