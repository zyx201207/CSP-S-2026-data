#include <bits/stdc++.h>
// #define int long long
#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
using namespace std;
using LL = long long;
using Pii = pair<int, int>;

const int kMaxM = 5e5 + 5, kMaxN = 505;

int c, n, m, d, q;
LL a[kMaxM], dis[kMaxN][kMaxN];
vector<Pii> l[kMaxM];

// inline int min(int &x, int& y) {
//   return (x < y ? x : y);
// }

// inline int max(int &x, int& y) {
//   return (x > y ? x : y);
// }

signed main() {
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  // int beg = clock();
  cin >> c >> n >> m >> d >> q;
  for(int i = 1; i <= m; i++) {
    cin >> a[i];
  }
  auto Upd = [&](int x, int y, LL w) -> void {
    dis[x][y] = min(dis[x][y], w);
    dis[y][x] = min(dis[y][x], w);
  };
  memset(dis, 0x3f, sizeof(dis));
  for(int i = 1; i <= n; i++) {
    dis[i][i] = 0;
  }
  for(int i = 1, k; i <= n; i++) {
    cin >> k;
    for(int j = 1, v, t; k--; ) {
      cin >> v >> t;
      l[v].push_back({i, t});
    }
  }
  for(int i = 1; i <= m; i++) {
    for(Pii j : l[i]) {
      for(Pii k : l[i]) {
        Upd(j.fi, k.fi, j.se + k.se);
      }
    }
  }
  for(int k = 1; k <= n; k++) {
    for(int i = 1; i <= n; i++) {
      for(int j = i + 1; j <= n; j++) {
        dis[j][i] = dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
  for(int x, y; q--; ) {
    cin >> x >> y;
    LL ans = 1e18;
    for(Pii i : l[x]) {
      for(Pii j : l[y]) {
        ans = min(ans, dis[i.fi][j.fi] + i.se + j.se + a[x] + a[y]);
      }
    }
    cout << ans << "\n";
  }
  // cerr << clock() - beg << '\n';
  return 0;
}