// CatNyan Blesses Me!
// placeholder Blesses Me!
// Cubber Blesses Me!
// chenmohan201068 Blesses Me!
// clever_baka Blesses Me!
// DTL123 Blesses Me!
// Zheng_iii Blesses Me!
// Daylightning Blesses Me!
// xuanxuanni Blesses Me!
// _vector_ Blesses Me!
// cdx123456 Blesses Me!
// tourist Blesses Me!
// jiangly Blesses Me!
// CCF Blesses Me!

// freopen();
// freopen();

#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using real = long double;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<std::vector<int> > adj(n + 1, std::vector<int>(n + 1, 0));
  for (int i = 1; i < n; ++i) {
    int u, v;
    std::cin >> u >> v;
    adj[u][v] = adj[v][u] = 1;
  }
  std::vector<std::vector<int> > dist(n + 1, std::vector<int>(n + 1, 0x3f3f3f3f));
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      if (adj[i][j]) dist[i][j] = 1;
  for (int i = 1; i <= n; ++i) dist[i][i] = 0;
  for (int kk = 1; kk <= n; ++kk)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        dist[i][j] = std::min(dist[i][j], dist[i][kk] + dist[kk][j]);

  struct DSU {
    std::vector<int> fa;
    std::vector<int> sz;
    int uni = 0;
    DSU(int _n) {
      fa.resize(_n + 1);
      sz.resize(_n + 1, 1);
      for (int i = 1; i <= _n; ++i) fa[i] = i;
      uni = 0;
    }
    int find(int x) {
      return (fa[x] == x ? x : fa[x] = find(fa[x]));
    }
    void merge(int u, int v) {
      u = find(u);
      v = find(v);
      if (u == v) return;
      if (sz[u] < sz[v]) std::swap(u, v);
      fa[v] = u;
      sz[u] += sz[v];
      ++uni;
    }
  };
  int ans = 0x3f3f3f3f;
  for (int msk1 = 0; msk1 < (1 << n); ++msk1) {
    if (__builtin_popcount(msk1) != k) continue;
    DSU dsu(n + 1);
    std::vector<int> cho;
    for (int i = 0; i < n; ++i)
      if (msk1 & (1 << i)) cho.emplace_back(i + 1);
    int nn = (int)cho.size();
    for (int i = 0; i < nn; ++i)
      for (int j = 0; j < nn; ++j)
        if (adj[cho[i]][cho[j]]) dsu.merge(cho[i], cho[j]);
    if (dsu.uni >= k - 2) {
      int now = 0;
      for (int i = 0; i < n; ++i) {
        if ((msk1 & (1 << i)) == 0) {
          int noww = 0x3f3f3f3f;
          for (int x : cho) noww = std::min(noww, dist[i + 1][x]);
          now = std::max(noww, now);
        }
      }
      if (ans > now)
        ans = now;
    }
  }

  std::cout << ans << '\n';
}
void solve1() {
  int n, k;
  std::cin >> n >> k;
  std::vector<std::vector<int> > adj(n + 1);
  for (int i = 1; i < n; ++i) {
    int u, v;
    std::cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  int m = n / 2;
  if (k >= m and k < n)
    std::cout << 1 << '\n';
  else if (k == n)
    std::cout << 0 << '\n';
  else
    std::cout << (m + k) / k << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  assert(std::freopen("hub.in", "r", stdin));
  assert(std::freopen("hub.out", "w", stdout));

  int c;
  int t = 1;
  std::cin >> c >> t;
  while (t--) {
    if (c >= 13 and c <= 14)
      solve1();
    solve();
  }

  return 0;
}

// wo chang chang zhui yi guo qu