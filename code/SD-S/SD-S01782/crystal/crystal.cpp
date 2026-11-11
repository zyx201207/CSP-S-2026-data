#include <bits/stdc++.h>

namespace silvecor {
using i64 = int64_t;
using u64 = uint64_t;
using f64 = double;
template <typename T>
using vec = std::vector<T>;
using std::pair;
using str = std::string;
template <typename T>
bool chmin(T &x, T y) { return y < x ? (x = y, true) : false; }
template <typename T>
bool chmax(T &x, T y) { return y > x ? (x = y, true) : false; }

static constexpr int N = 5e5 + 2;

int n;
i64 m, d;
i64 a[N];

void solve() {
  std::cin >> n >> m;
  if (n == 1) {
    std::cout << "1\n";
    return; 
  }
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  } 
  std::sort(a, a+n);
  int ans = 0;
  int l = 0, r = 0;
  d = 0;
  while (l != n - 1 and r != n - 1) {
    while (m - d >= 0 and r != n - 1) {
      d += (i64) (r - l + 1) * (i64) (a[r + 1] - a[r]);
      ++r;
      if (m - d >= 0) {
        chmax(ans, r - l + 1);   
      } else break;
      
//      std::cerr << "DBG " << l << ' ' << r << ' ' << d << '\n';
    }
    while (m - d < 0 and l != r) {
      d -= a[r] - a[l];
      ++l;
      if (m - d >= 0) {
        chmax(ans, r - l + 1);
        break; 
      }
      
//      std::cerr << "DBG " << l << ' ' << r << ' ' << d << '\n';
    }
  }
  
  std::cout << ans << '\n';
}
}

int main() {
#ifndef LOCAL_DBG
  std::freopen("crystal.in", "r", stdin);
  std::freopen("crystal.out", "w", stdout); 
#endif
  std::cin.tie(nullptr)->sync_with_stdio(false);
  silvecor::solve();
  return 0;
}
