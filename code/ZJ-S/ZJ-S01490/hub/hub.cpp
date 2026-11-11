#include <bits/stdc++.h>
#define endl '\n'
using i32 = int;
using i64 = long long;
using p32 = std::pair<i32, i32>;
using p64 = std::pair<i64, i64>;
const i32 inf32 = 1e9;
const i64 inf64 = 2e18;
void solve(i32 _);
signed main() {
	std::cin.tie(0)->sync_with_stdio(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, T = 1;
	std::cin >> c >> T;
	while (T--) solve(c);
}
void solve(i32 _) {
	i32 n, k;
  std::cin >> n >> k;
  std::vector<i32> a(n + 2, 0);
  std::vector<std::vector<i32>> g(n + 2);
  std::vector<char> vis(n + 2, 0), avail(n + 2, 0);
  for (i32 i = 1; i < n; i++) {
    i32 u, v;
    std::cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (i32 i = 1; i <= n; i++) a[i] = i;
  auto dfs = [&](auto&& self, i32 u) -> void {
    vis[u] = 1;
    for (i32 v : g[u]) {
      if (vis[v] or not avail[v]) continue;
      self(self, v);
    }
  };
  auto bfs = [&](i32 st) -> i32 {
    std::queue<p32> q;
    q.push({st, 0});
    while (not q.empty()) {
      auto [u, w] = q.front();
      q.pop();
      vis[u] = 1;
      if (avail[u]) return w;
      for (auto v : g[u]) {
        if (vis[v]) continue;
        q.push({v, w + 1});
      }
    }
    return 0;
  };
  i32 ans = 0;
  do {
    std::fill(vis.begin(), vis.end(), 0);
    std::fill(avail.begin(), avail.end(), 0);
    for (i32 i = 1; i <= k; i++) avail[a[i]] = 1;
    i32 cnt = 0;
    for (i32 i = 1; i <= k; i++) {
      if (not vis[a[i]]) {
        cnt++, dfs(dfs, a[i]);
      }
    }
    std::fill(vis.begin(), vis.end(), 0);
    for (i32 i = k + 1; i <= n; i++) ans = std::max(ans, bfs(a[i]));
    i32 flag = 0;
    for (i32 i = 1; i <= n; i++) 
      if (a[i] != n - i + 1) flag = 1;
    if (not flag) break;
  } while (std::next_permutation(a.begin() + 1, a.begin() + n + 1));
  std::cout << ans << endl;
}

// what im i doing man
// im coding a piece of []