#include <bits/stdc++.h>
#define int long long
using namespace std;

int c, T, n, k;
vector<int> g[1000005];
int dep[5005];
int fa[5005][22];
int ans = 1e15;

void dfs(int u, int f) {
  dep[u]=dep[f]+1, fa[u][0]=f;
  for (auto v : g[u]) {
    if (v == f) continue;
    dfs(v, u);
  }
}

int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for (int i = 18; i >= 0; i--)
    if (dep[fa[u][i]] >= dep[v])
      u = fa[u][i];
  if (u == v) return u;
  for (int i = 18; i >= 0; i--)
    if (fa[u][i] != fa[v][i])
      u = fa[u][i], v = fa[v][i];
  return fa[u][0];
}

namespace brute_force {
  vector<bool> flag(5005);
  vector<int> vec;
  int ans;
  void check() {
    int maxn = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (flag[i] && !flag[fa[i][0]]) {
        cnt++;
      }
    }
    if (cnt > 2) return;
    for (int i = 1; i <= n; i++) {
      int cur = 1e16;
      for (auto v : vec) {
        cur = min(cur, dep[i] + dep[v] - 2 * dep[lca(i, v)]);
      }
      maxn = max(maxn, cur);
    }
    ans = min(ans, maxn);
  }
  void dfs(int u) {
    if (u > n) {
      if (vec.size() == k) {
        check();
      }
    } else if (vec.size() > k) {
      return;
    } else {
      vec.push_back(u); flag[u] = true;
      dfs(u + 1);
      vec.pop_back(); flag[u] = false;
      dfs(u + 1);
    }
  }
  void solve() {
    ans = 1e16;
    for (int i = 1; i <= n; i++) flag[i] = false;
    while(!vec.empty()) vec.pop_back();
    dfs(1);
    cout << ans << '\n';
  }
}

signed main() {
// #ifndef MY_JUDGE
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
// #endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> c >> T;
  while(T--) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) g[i].resize(0);
    for (int i = 1; i < n; i++) {
      int u, v; cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= 18; i++)
      for (int u = 1; u <= n; u++)
        fa[u][i] = fa[fa[u][i-1]][i-1];
    // if (c <= 3)
      brute_force::solve();
  }
  return 0;
}