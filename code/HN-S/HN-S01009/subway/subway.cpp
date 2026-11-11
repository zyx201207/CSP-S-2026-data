#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using Pii = pair<int, int>;

const int kMaxN = 505, kMaxM = 5e5 + 5;
const LL kInf = 1e18;

int c, n, m, d, q;
LL dis[kMaxN][kMaxN];
int w[kMaxM];
vector<Pii> v[kMaxM];

int main() {
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> c >> n >> m >> d >> q;
  for (int i = 1; i <= m; i++) cin >> w[i];
  for (int i = 1, k; i <= n; i++) {
    cin >> k;
    for (int a, c; k--;) {
      cin >> a >> c;
      v[a].push_back({i, c});
    }
  }
  memset(dis, 0x3f, sizeof dis);
  for (int i = 1; i <= n; i++) dis[i][i] = 0;
  for (int i = 1; i <= m; i++) {
    for (int x = 0; x < v[i].size(); x++) {
      int p = v[i][x].first, wp = v[i][x].second;
      for (int y = x + 1; y < v[i].size(); y++) {
        int q = v[i][y].first, wq = v[i][y].second;
        dis[p][q] = dis[q][p] = min(dis[p][q], (LL)(wp + wq));
      }
    }
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= i; j++) {
        dis[i][j] = dis[j][i] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
  for (int x, y; q--;) {
    cin >> x >> y;
    LL ans = kInf;
    for (auto p : v[x]) {
      for (auto q : v[y]) {
        ans = min(ans, p.second + q.second + dis[p.first][q.first]);
      }
    }
    cout << ans + w[x] + w[y] << '\n';
  }
  return 0;
}
/*
g++ subway.cpp -o subway -std=c++14 -O2 -Wall -Wextra -fsanitize=address,undefined && ./subway
*/