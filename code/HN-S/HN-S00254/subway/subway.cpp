#include <bits/stdc++.h>
#define int ll
//#define DEBUG
using namespace std;
using ll = long long;

struct node {
  int x, v;
};

int _, n, m, d, q, w[500050], l, x, y;
ll dis[550][550], wt[550][550];
vector<node> tsf[500050];

signed main() {
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
#ifndef DEBUG
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif
  cin >> _ >> n >> m >> d >> q;
  for(int i = 1; i <= m; i++) cin >> w[i];
  for(int i = 1; i <= n; i++) {
    for(cin >> l; l--; ) {
      cin >> x >> y;
      tsf[x].push_back({i, y});
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) wt[i][j] = INT_MAX * 10000ll;
    wt[i][i] = 0;
  }
  for(int i = 1; i <= m; i++) {
    for(auto j : tsf[i]) {
      for(auto k : tsf[i]) wt[j.x][k.x] = min(wt[j.x][k.x], 0ll + j.v + k.v);
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) dis[i][j] = wt[i][j];
  }
  for(int k = 1; k <= n; k++) {
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    }
  }
  for(; q--; ) {
    cin >> x >> y;
    int ans = INT_MAX * 10000ll;
    for(auto i : tsf[x]) {
      for(auto j : tsf[y]) ans = min(ans, i.v + j.v + dis[i.x][j.x]);
    }
    cout << ans + w[x] + w[y] << '\n';
  }
  return 0;
}
/*
My Luogu ID:928986
20mins.
*/
