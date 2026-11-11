#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using Pii = pair<LL, LL>;

const int kMaxN = 505, kMaxM = 1e6 + 5;
const LL kInf = 1e16;

LL w[kMaxM], f[kMaxN][kMaxN], c, n, m, d, q;
LL a[kMaxM], t[kMaxM];
map<int, int> mp[kMaxN];
vector<Pii> pos[kMaxM];

int main() {
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> c >> n >> m >> d >> q;
  for (int i = 1; i <= m; i++) {
    cin >> w[i];
  }
  for( int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      f[i][j] = kInf;
    }
  }
  for (int i = 1; i <= n; i++) {
    f[i][i] = 0;
  }
  for (int i = 1, k; i <= n; i++) {
    cin >> k;
    for (int j = 1; j <= k; j++) {
      cin >> a[j] >> t[j];
      mp[i][a[j]] = t[j];
      pos[a[j]].push_back({t[j], i});
    }
  }
  for( int i = 1; i <= m; i++) {
    for (Pii x : pos[i]) {
      for (Pii y : pos[i]) {
        f[x.second][y.second] = min(f[x.second][y.second], x.first + y.first);
      }
    }
  }
  for (int k = 1; k <= n; k++) {
    for( int i = 1; i <= n; i++) {
      for( int j = 1; j <= n; j++) {
        f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
      }
    }
  }
  // cout << f[2][3] << "\n";
  // cout << f[1][2] << "\n";
  for (int x, y; q; q--) {
    cin >> x >> y;
    LL ans = kInf;
    for (Pii a : pos[x]) {
      for (Pii b : pos[y]) {
        ans = min(ans, f[a.second][b.second] + a.first + b.first);
      }
    }
    cout << ans + w[x] + w[y] << "\n";
  }
  return 0;
}
// g++ subway.cpp -o subway -std=c++14 -O2 -Wall && ./subway