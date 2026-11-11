/*
CSP_S = max (CSP_S, 300);
bu yao chu (strings) a a a a a a a a a a.
bu yao chu (math) a a a a a a a a a a a.
bu dui a yun tang ji zi pao de bu shi hen kuai ma.
5e8 0.8s zhe me kuai hai you ren pen???
wo cao zen me T2 pao le 0.6s bu yao ka wo chang.
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 5e5 + 3, D = 24, M = 5e2 + 3;
const ll INF = 1e18;

struct Node {
  int x, c;
};

int n, m, d, q, a[M][D], t[M][D];
ll ans, w[N], f[M][M];

vector<Node> g[N];

inline void ckmn (ll &x, ll y) {
  x = (x < y ? x : y);
}

int main () {
  freopen ("subway.in", "r", stdin);
  freopen ("subway.out", "w", stdout);
  ios :: sync_with_stdio (0), cin.tie (0);
  cin >> n >> n >> m >> d >> q;
  memset (f, 0x3f, sizeof (f));
  for (int i = 1; i <= m; cin >> w[i++]) {
  }
  for (int i = 1, k; i <= n; ++i) {
    cin >> k, f[i][i] = 0;
    for (int j = 1, x, y; j <= k; ++j) {
      cin >> x >> y;
      g[x].push_back ({i, y});
    }
  }
  for (int i = 1; i <= m; ++i) {
    for (int p = 0; p < g[i].size (); ++p) {
      for (int q = 0; q < p; ++q) {
        int mn = min (f[g[i][p].x][g[i][q].x], 1ll * g[i][p].c + g[i][q].c);
        ckmn (f[g[i][p].x][g[i][q].x], mn);
        ckmn (f[g[i][q].x][g[i][p].x], mn);
      }
    }
  }
  for (int mid = 1; mid <= n; ++mid) {
    for (int s = 1; s <= n; ++s) {
      for (int t = 1; t <= n; ++t) {
        ckmn (f[s][t], f[s][mid] + f[mid][t]);
      }
    }
  }

  for (int x, y; q--; ) {
    cin >> x >> y, ans = INF;
    for (auto i : g[x]) {
      for (auto j : g[y]) {
        ckmn (ans, w[x] + w[y] + i.c + j.c + f[i.x][j.x]);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}

/*
by _Leehom_

uid : 994729
*/
