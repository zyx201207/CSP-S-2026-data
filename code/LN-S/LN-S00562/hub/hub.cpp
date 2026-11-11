#include <bits/stdc++.h>
int mainf(int c)
{
  int n, k;
  std::cin >> n >> k;
  std::vector<std::vector<int>> adj(n);
  std::vector<std::pair<int, int>> es(n - 1);
  for (int i = 1; i < n; ++i)
  {
    int u, v;
    std::cin >> u >> v;
    --u; --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    es[i - 1] = {u, v};
  }
  // O(nk*C(n,k)) = O(n^2*2^n)
  int minmaxdis = 0x3f3f3f3f;
  for (int b = 0; b < (1 << n); ++b)
    if (__builtin_popcount(b) == k)
  {
    // V - E = 2
    auto inS = [b](int x){ return (b >> x) & 1; };
    int os = k;
    for (auto e : es)
      if (inS(e.first) && inS(e.second))
        --os;
    if (os > 2) continue;
    std::vector<int> dis(n, 0x3f3f3f3f);
    auto dfs = [&](auto&& self, int u, int p) -> void
    {
      for (auto v : adj[u])
        if (v != p)
          dis[v] = std::min(dis[v], dis[u] + 1),
          self(self, v, u);
    };
    for (int i = 0; i < n; ++i)
      if (inS(i))
        dis[i] = 0,
        dfs(dfs, i, i);
    int maxdis = 0;
    for (int i = 0; i < n; ++i)
      maxdis = std::max(maxdis, dis[i]);
    minmaxdis = std::min(minmaxdis, maxdis);
  }
  std::cout << minmaxdis << '\n';
  return 0;
}
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::freopen("hub.in", "r", stdin);
  std::freopen("hub.out", "w", stdout);
  int c, t;
  std::cin >> c >> t;
  while (t--)
    mainf(c);
  return 0;
}