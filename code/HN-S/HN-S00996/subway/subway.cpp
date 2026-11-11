#include<bits/stdc++.h>
#define rep(i,l,r) for (int i = l; i <= r; i ++)
#define rrp(i,l,r) for (int i = l; i >= r; i --)
using namespace std;
#ifdef LOCAL
#define debug(x) (cerr << #x << " = " << x << '\n')
#else
#define debug(x) void(0)
#endif
typedef pair<int, int> pii;
typedef long long LL;
typedef unsigned long long uLL;
const int N = 505, M = 5e5 + 5;

int n, m, D, q, w[M];
vector<pair<int, int>> g[M];
LL dis[N][N];

void fakemain() {
  cin >> n >> m >> D >> q;
  rep (i, 1, m) cin >> w[i], g[i].reserve(D);
  rep (i, 1, n) {
    int k, x, t; cin >> k;
    while (k --) cin >> x >> t, g[x].emplace_back(i, t);
  }
  memset(dis, 0x3f, sizeof dis);
  rep (i, 1, n) dis[i][i] = 0;
  rep (i, 1, m) {
    for (auto [x, t1] : g[i]) for (auto [y, t2] : g[i])
      dis[x][y] = min<LL>(dis[x][y], t1 + t2);
  }
  rep (k, 1, n) rep (i, 1, n) rep (j, 1, n) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
  for (int x, y; q --; ) {
    cin >> x >> y;
    LL ans = 1e18;
    for (auto [i, t1] : g[x]) for (auto [j, t2] : g[y])
      ans = min(ans, dis[i][j] + t1 + t2 + w[x] + w[y]);
    cout << ans << '\n';
  }
}

signed main() {
  auto fre = [&](string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  };
  fre("subway");
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int T = 1, c;
  cin >> c;
  // cin >> T;
  while (T --) fakemain();
  cerr << "time used: " << 1. * clock() / CLOCKS_PER_SEC << "s\n";
  return 0;
}