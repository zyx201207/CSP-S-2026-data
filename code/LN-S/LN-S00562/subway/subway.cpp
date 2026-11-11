#include <bits/stdc++.h>
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::freopen("subway.in", "r", stdin);
  std::freopen("subway.out", "w", stdout);
  int c, n, m, d, q;
  std::cin >> c >> n >> m >> d >> q;
  constexpr long long inf = 0x3f3f3f3f'3f3f3f3f;
  std::vector<long long> w(m);
  for (int i = 0; i < m; ++i)
    std::cin >> w[i];
  std::vector<std::vector<std::pair<int, long long>>> pass(m);
  for (int i = 0; i < n; ++i)
  {
    int k;
    std::cin >> k;
    for (int j = 0; j < k; ++j)
    {
      int a; long long t;
      std::cin >> a >> t;
      --a;
      pass[a].emplace_back(i, t);
    }
  }
  std::vector<std::vector<long long>> dis
    (n, std::vector<long long>(n, inf));
  for (int i = 0; i < n; ++i)
    dis[i][i] = 0;
  for (int i = 0; i < m; ++i)
  {
    for (auto p1 : pass[i])
      for (auto p2 : pass[i])
        dis[p1.first][p2.first] = 
          std::min(dis[p1.first][p2.first], p1.second + p2.second);
  }
  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
  while (q--)
  {
    int x, y;
    std::cin >> x >> y;
    --x; --y;
    long long res = inf;
    for (auto p1 : pass[x])
      for (auto p2 : pass[y])
        res = std::min(res, p1.second + p2.second + dis[p1.first][p2.first]);
    std::cout << res + w[x] + w[y] << '\n';
  }
  return 0;
}