#include <bits/stdc++.h>
using namespace std;
template <typename T> void ckmn(T& x, T y) { (y < x) && (x = y); }
template <typename T> void ckmx(T& x, T y) { (y > x) && (x = y); }
using ll = long long;
const int N = 4000, inf = 0x3f3f3f3f;
int n, k;
vector<int> G[N + 5];
int lm;
int f[N + 5];
int fa[N + 5], dep[N + 5], sz[N + 5], mxd[N + 5];
void dfs(int u, int ft) {
  fa[u] = ft, dep[u] = dep[ft] + 1, sz[u] = 1, mxd[u] = dep[u];
  for (auto& v : G[u]) {
    if (v == ft) continue ;
    dfs(v, u);
    sz[u] += sz[v];
    mxd[u] = max(mxd[u], mxd[v]);
  }
}
void dfs_f(int u) {
  if (mxd[u] - dep[u] + 1 <= lm) {
    f[u] = 0;
    return ;
  }
  f[u] = 1;
  for (auto& v : G[u]) if (v != fa[u]) {
    dfs_f(v);
    f[u] += f[v];
  }
}
int now = 0, nd;
void dfs2(int u, int d) {
  if (d > lm + lm) return ;
  ckmn(nd, f[u] + now);
  if (nd <= k) {
    // cerr << "??? : " << u << '\n';
    return ;
  }
  int a = 0, b = 0;
  for (auto& v : G[u]) {
    if (mxd[v] - dep[v] + 2 >= a) b = a, a = mxd[v] - dep[v] + 2;
    else ckmx(b, mxd[v] - dep[v] + 2);
  }
  for (auto& v : G[u]) if (v != fa[u]) {
    if (mxd[v] - dep[v] + 2 == a && b - 1 + d <= lm + lm) dfs2(v, max(d + 1, b));
    else if (a - 1 + d <= lm + lm) dfs2(v, max(d + 1, a));
  }
}
bool check(int Limit) {
  lm = Limit;
  for (int root = 1; root <= n; root++) {
    dfs(root, 0);
    for (int i = 1; i <= n; i++) f[i] = 0;
    dfs_f(root);
    if (f[root] <= k) return 1;
    for (auto& v : G[root]) {
      now = f[v];
      int a = 0, b = 0;
      for (auto& w : G[root]) if (w != v) {
        if (mxd[w] - dep[w] + 2 >= a) b = a, a = mxd[w] - dep[w] + 2;
        else ckmx(b, mxd[w] - dep[w] + 2);
      }
      for (auto& w : G[root]) if (w != v) {
        nd = inf;
        if (mxd[w] - dep[w] + 2 == a && b <= lm + lm) dfs2(w, max(2, a));
        else if (a <= lm + lm) dfs2(w, max(2, b));
        if (nd <= k) {
          // cerr << "??? " << root << ' ' << v << '\n';
          return 1;
        }
      }
    }
  }
  return 0;
}
void solve() {
  cin >> n >> k;
  for (int i = 1, u, v; i < n; i++) {
    cin >> u >> v;
    G[u].push_back(v), G[v].push_back(u);
  }
  int L = 0, R = n - 1, mi = 0, ans = 0;
  while (L <= R) {
    mi = (L + R) >> 1;
    if (check(mi)) ans = mi, R = mi - 1;
    else L = mi + 1;
  }
  cout << ans << '\n';
  for (int i = 1; i <= n; i++) {
    G[i].clear();
  }
}
int main() {
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int c, t; cin >> c >> t; while (t--) solve();
  return 0;
} // g++ hub.cpp -o hub -std=c++14 -O2 -static -Wall -Wextra