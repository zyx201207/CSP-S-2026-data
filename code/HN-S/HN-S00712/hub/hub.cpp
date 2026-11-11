#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e6 + 10;

int n, k, ans, dep[MAXN], sz[MAXN], dfn[MAXN], son[MAXN], top[MAXN], ts, f[MAXN];
bool chs[MAXN], vis[MAXN];
vector<int> g[MAXN], node;

void pre(int u, int fa) {
  dep[u] = dep[fa] + 1, f[u] = fa, sz[u] = 1, son[u] = 0;
  for (int v : g[u]) {
    if (v == fa) continue;
    pre(v, u);
    sz[u] += sz[v];
    if (sz[v] > sz[son[u]]) son[u] = v;
  }
}

void dfs(int u, int fa, int ftop) {
  top[u] = ftop, dfn[u] = ++ts;
  if (son[u]) dfs(son[u], u, ftop);
  for (int v : g[u]) {
    if (v == fa || v == son[u]) continue;
    dfs(v, u, v);
  }
}

int lca(int u, int v) {
  for (; top[u] != top[v]; u = f[top[u]]) {
    if (dep[top[u]] < dep[top[v]]) swap(u, v);
  }
  return dep[u] < dep[v] ? u : v;
}

int dis(int u, int v) {
  return dep[u] + dep[v] - (dep[lca(u, v)] << 1);
}

void check(int u) {
  if (!chs[u] || vis[u]) return;
  vis[u] = 1;
  for (int v : g[u]) check(v);
}

void dfs(int x, int cnt) {
  if (cnt > k) return;
  if (x == n + 1) {
    if (cnt != k) return;
    int c = 0;
    fill(vis + 1, vis + n + 1, 0);
    for (int u : node) if (!vis[u]) check(u), c++;
    if (c > 2) return;
    int res = 0;
    for (int i = 1; i <= n; i++) {
      int mi = n;
      for (int u : node) mi = min(mi, dis(i, u));
      res = max(res, mi);
    }
    ans = min(ans, res);
    return;
  }
  dfs(x + 1, cnt);
  chs[x] = 1, node.push_back(x);
  dfs(x + 1, cnt + 1);
  chs[x] = 0, node.pop_back();
}

void Solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; g[i++].clear());
  for (int i = 1, u, v; i < n; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  ans = n, ts = 0;
  pre(1, 0), dfs(1, 0, 1), dfs(1, 0);
  cout << ans << '\n';
}

int main() {
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int c, T;
  for (cin >> c >> T; T--; Solve());
  return 0;
}
/*
luogu uid: 768951
OI 2022.8 ~ 2026.10
but Anastasia is forever!
What do you want more than a Happy ending?
*/
