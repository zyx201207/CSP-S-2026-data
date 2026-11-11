#include <cstring>
#include <iostream>

using i64 = long long;

#define file(s) \
   std::freopen(#s ".in", "r", stdin), std::freopen(#s ".out", "w", stdout)

constexpr int N = 2e6 + 5;

int n;
i64 m, a[N], cnt[N];

void work() {
   std::cin >> n >> m;
   for (int i = 1; i <= n; ++i) std::cin >> a[i];

   std::memset(cnt + 1, 0, n * sizeof(i64));
   i64 lst, bas, len;

   for (int i = 1, j; i <= n; ++i) {
      i64 lim = a[i] - m;
      if (i == 1 || a[i - 1] < lim) {
         j = i, lst = bas = len = 1;
         continue;
      }

      if (a[j] >= lim) {
         lst += bas, ++len;
         continue;
      }
      while (a[j] < lim) ++j;

      if (j == i - 1) lst += bas, len = 1;
      else {
         if (j == i - 2) cnt[i] = lst - bas;
         lst = bas = i - j + 1;
      }
//      std::cerr << i << ' ' << bas << '\n';
   }

   i64 res = 0;
   for (int i = n, j; i; res += lst * cnt[i--]) {
      i64 lim = a[i] + m;
      if (i == n || a[i + 1] > lim) {
         j = i, lst = bas = 1;
         continue;
      }

      if (a[j] <= lim) {
         lst += bas;
         continue;
      }
      while (a[j] > lim) --j;

      if (j == i + 1) lst += bas;
      else lst = bas = j - i + 1;
   }

   std::cout << res << '\n';
}

int main() {
   std::cin.tie(nullptr)->sync_with_stdio(false);
   file(migrate);
#ifdef DEBUG
   file(cur);
#endif

   int _ID, _T;
   for (std::cin >> _ID >> _T; _T--; ) work();

   return 0;
}
