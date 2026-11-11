#include <cstring>
#include <iostream>
#include <vector>

using i64 = long long;

template <class T>
inline void ck_mx(T &x, T y) { x < y && (x = y, 1); }
template <class T>
inline void ck_mn(T &x, T y) { x > y && (x = y, 1); }

#define file(s) \
   std::freopen(#s ".in", "r", stdin), std::freopen(#s ".out", "w", stdout)

constexpr int N = 500 + 5;
constexpr int M = 5e5 + 5;
constexpr i64 INF = 1e18;

int n, m, q, a[M], _;
std::vector<std::pair<int, int>> b[M];

i64 dis[N][N];

int main() {
   std::cin.tie(nullptr)->sync_with_stdio(false);
   file(subway);
#ifdef DEBUG
   file(cur);
#endif

   std::cin >> _ >> n >> m >> _ >> q;
   for (int i = 1; i <= m; ++i) std::cin >> a[i];
   for (int i = 1, k, x, y; i <= n; ++i) {
      std::cin >> k;
      while (k--) std::cin >> x >> y, b[x].push_back({i, y});
   }

   std::memset(dis, 0x3f, sizeof(dis));
   for (int i = 1; i <= n; ++i) dis[i][i] = 0;

   for (int i = 1; i <= m; ++i)
      for (auto [x, tX] : b[i]) for (auto [y, tY] : b[i]) if (x ^ y)
         ck_mn(dis[x][y], 1ll * tX + tY), ck_mn(dis[y][x], 1ll * tX + tY);

   for (int k = 1; k <= n; ++k) for (int i = 1; i <= n; ++i) if (k ^ i)
      for (int j = 1; j <= n; ++j) if (k ^ j && i ^ j)
         ck_mn(dis[i][j], dis[i][k] + dis[k][j]);

   while (q--) {
      int x, y;
      std::cin >> x >> y;

      i64 res = INF;
      for (auto [i, tI] : b[x]) for (auto [j, tJ] : b[y])
         ck_mn(res, tI + tJ + dis[i][j]);

      std::cout << res + a[x] + a[y] << '\n';
   }

   return 0;
}
