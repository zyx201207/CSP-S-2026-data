#include <algorithm>
#include <iostream>

using i64 = long long;

template <class T>
inline void ck_mx(T &x, T y) { x < y && (x = y, 1); }
template <class T>
inline void ck_mn(T &x, T y) { x > y && (x = y, 1); }

#define file(s) \
   std::freopen(#s ".in", "r", stdin), std::freopen(#s ".out", "w", stdout)

constexpr int N = 5e5 + 5;

int n;
i64 m, a[N];

int main() {
   std::cin.tie(nullptr)->sync_with_stdio(false);
   file(crystal);
#ifdef DEBUG
   file(cur);
#endif

   std::cin >> n >> m;
   for (int i = 1; i <= n; ++i) std::cin >> a[i];
   std::sort(a + 1, a + n + 1);

   int res = 0;
   i64 cur = 0;
   for (int i = 1, j = 1; i <= n; ++i) {
      cur += (a[i] - a[i - 1]) * (i - j);
      while (cur > m) cur -= a[i] - a[j++];

      ck_mx(res, i - j + 1);
   }

   std::cout << res << '\n';

   return 0;
}
