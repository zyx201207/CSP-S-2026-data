#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const LL kMaxN = 5e5 + 5, kMaxM = 505;

ifstream fin("subway.in");
ofstream fout("subway.out");

LL c, n, m, d, q, w[kMaxN], e[kMaxM][kMaxM];
vector<pair<LL, LL>> g[kMaxN];

int main() {
  fin >> c >> m >> n >> d >> q;
  for (LL i = 1; i <= n; i++) {
    fin >> w[i];
  }
  for (LL i = 1, k; i <= m; i++) {
    fin >> k;
    for (LL a, t; k; k--) {
      fin >> a >> t;
      g[a].push_back({i, t});
    }
  }
  memset(e, 0x3f, sizeof e);
  for (LL i = 1; i <= m; i++) {
    e[i][i] = 0;
  }
  for (LL i = 1; i <= n; i++) {
    for (LL j = 0; j < g[i].size(); j++) {
      for (LL l = j + 1; l < g[i].size(); l++) {
        LL l1 = g[i][j].first, l2 = g[i][l].first;
        e[l1][l2] = e[l2][l1] = min(e[l1][l2], g[i][j].second + g[i][l].second);
      }
    }
  }
  for (LL k = 1; k <= m; k++) {
    for (LL i = 1; i <= m; i++) {
      for (LL j = 1; j <= m; j++) {
        e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
      }
    }
  }
  for (LL x, y; q; q--) {
    fin >> x >> y;
    LL ans = 1e18;
    for (LL i = 0; i < g[x].size(); i++) {
      for (LL j = 0; j < g[y].size(); j++) {
        ans = min(ans, e[g[x][i].first][g[y][j].first] + g[x][i].second + g[y][j].second);
      }
    }
    fout << ans + w[x] + w[y] << '\n';
  }
  return 0;
}
/*
x x xxx
o o ooo
*/