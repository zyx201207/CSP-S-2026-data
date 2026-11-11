#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e6 + 9;
int cid, n, k, dep[N], fa[N], chn[N], cs, mxd[N], f[4009][4009], g[N][2];
vector<int> es[N];
int dfs(int x, int ff) {
  fa[x] = ff, dep[x] = dep[ff] + 1;
  int mx = dep[x];
  for (int y : es[x])
    if (y ^ ff) mx = max(dfs(y, x), mx);
  return mx;
}
void dfs1(int x, int ff) {
  f[x][0] = 0x3f3f3f3f;
  for (int y : es[x]) {
    if (y ^ ff) {

    }
  }
}
bool chk(int x) {
  int cnt = 0, lft = 0, rht = cs + 1;
  for (int i = 1; i <= cs; ++i)
    if (mxd[i] > x) return false;
  for (int i = 1, mx = -0x3f3f3f3f; i <= cs; ++i) {
    mx = max(mx + 1, mxd[i]);
    if (mx > x) {
      lft = i - 1;
      break;
    }
  }
  if (lft == 0) return false;
  for (int i = cs, mx = -0x3f3f3f3f; i >= 1; --i) {
    mx = max(mx + 1, mxd[i]);
    if (mx > x) {
      rht = i + 1;
      break;
    }
  }
  if (rht > cs) return false;
  for (int i = lft; i <= rht; ++i) {
    if (min(i - lft, rht - i) + mxd[i] > x) return false;
  }
  return true;
}
signed main() {
#ifndef LOCAL
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
#endif
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> cid >> tt;
  while (tt--) {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) es[i].clear();
    for (int i = 1, x, y; i < n; ++i) {
      cin >> x >> y;
      es[x].push_back(y), es[y].push_back(x);
    }
    dfs(1, 0);
    int p1 = max_element(dep + 1, dep + n + 1) - dep;
    dfs(p1, 0);
    int p2 = max_element(dep + 1, dep + n + 1) - dep;
    int u = p2;
    cs = 0;
    while (u != p1) {
      chn[++cs] = u, u = fa[u];
    }
    chn[++cs] = p1;
    int mid = chn[cs / 2];
    if (k == 1) {
      dfs(mid, 0);
      cout << *max_element(dep + 1, dep + n + 1) << '\n';
    }
    else if (k == 2) {
      for (int i = 1; i <= cs; ++i) {
        dep[chn[i]] = mxd[i] = 0;
        for (int y : es[chn[i]])
          if (y != chn[i - 1] && y != chn[i + 1]) mxd[i] = dfs(y, chn[i]);
      }
      // cout << chk(1) << '\n';
      // return 0;
      int l = 0, r = n;
      while (l < r) {
        int m = (l + r) >> 1;
        if (chk(m)) r = m;
        else l = m + 1;
      }
      cout << l << '\n';
    }
    else {

    }
  }
}