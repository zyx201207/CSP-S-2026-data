#include <bits/stdc++.h>
#define int long long
using namespace std;

// N:500
// M, sigma(k):5e5
// d:20
// q:1e5

// O(n^3)

int c, n, m, d, Q;
vector<int> w(500005, 0);
vector<int> k(505, 0);
vector<int> a[505];
vector<int> t[505];
vector<int> s[505];

namespace A {
  vector<vector<int>> dis(1005, vector<int>(1005, 1e15));
  void solve() {
    for (int i = 1; i <= m; i++) {
      dis[i][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
      if (k[i] == 2) {
        dis[a[i][1]][a[i][2]] = min(dis[a[i][1]][a[i][2]], t[i][1] + t[i][2]);
        dis[a[i][2]][a[i][1]] = min(dis[a[i][2]][a[i][1]], t[i][1] + t[i][2]);
      }
    }
    for(int k = 1; k <= m; k++) {
      for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
          dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        }
      }
    }
    for (int i = 1; i <= Q; i++) {
      int x, y; cin >> x >> y;
      if (x == y) cout << "0\n";
      else cout << w[x] + w[y] + dis[x][y] << '\n';
    }
  }
}

namespace B {
  void solve() {
    for (int i = 1; i <= Q; i++) {
      int x, y; cin >> x >> y;
    }

  }
}

namespace brute_force {
  void solve() {
    for (int i = 1; i <= Q; i++) {
      int x, y; cin >> x >> y;
    }

  }
}

signed main() {
// #ifndef MY_JUDGE
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
// #endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> c >> n >> m >> d >> Q;
  for (int i = 1; i <= m; i++) cin >> w[i];
  for (int i = 1; i <= n; i++) {
    cin >> k[i];
    a[i].resize(k[i] + 1);
    t[i].resize(k[i] + 1);
    for (int j = 1; j <= k[i]; j++) cin >> a[i][j], cin >> t[i][j], s[a[i][j]].push_back(i);
  }
  if (c >= 7 && c <= 11) {A::solve();return 0;}
  if (c >= 12 && c <= 19) B::solve();
  else brute_force::solve();
  return 0;
}
