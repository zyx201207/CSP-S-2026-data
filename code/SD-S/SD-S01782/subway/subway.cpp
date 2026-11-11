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

static constexpr int N = 505, M = 5e5 + 5, D = 22;
static constexpr i64 Inf = 1e18;

int _no, n, m, d, q;
int w[M];
i64 dis[N][N];
vec<pair<int, int>> st[M]; // [id, val]

void solve() {
  std::cin >> _no >> n >> m >> d >> q;
  for (int i = 1; i <= m; ++i) {
    std::cin >> w[i];
    st[i].reserve(d);
  }
  for (int i = 1, k, sta, val; i <= n; ++i) {
     std::cin >> k;
     for (int _ = 1; _ <= k; ++_) {
       std::cin >> sta >> val;
       st[sta].emplace_back(i, val);
     }
     for (int j = 1; j <= n; ++j) dis[i][j] = (i == j ? 0 : Inf);
  }
  for (int i = 1; i <= m; ++i) {
    auto &cur = st[i];
    for (auto it = cur.begin(); it != cur.end(); ++it) {
      for (auto jt = it; jt != cur.end(); ++jt) {
        chmin(dis[it->first][jt->first], (i64) it->second + (i64) jt->second);
        chmin(dis[jt->first][it->first], (i64) it->second + (i64) jt->second);
      }
    }
  }
  
//  for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j)
//    std::cerr << "DIS " << i << ' ' << j << ' ' << dis[i][j] << '\n';
  
  for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) for (int k = 1; k <= n; ++k)
    chmin(dis[i][j], dis[i][k] + dis[k][j]);
  
//  for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j)
//    std::cerr << "DIS " << i << ' ' << j << ' ' << dis[i][j] << '\n';
  
  for (int _ = 1, l, r; _ <= q; ++_) {
    std::cin >> l >> r;
    i64 ans = Inf + Inf;
    for (auto i : st[l]) {
      for (auto j : st[r]) {
        i64 nxtAns = (i64) i.second + (i64) j.second + (i64) dis[i.first][j.first];
        chmin(ans, nxtAns);
//        std::cerr << "DBG " << i.first << ' ' << j.first << ' ' << nxtAns << '\n';
      }
    }
    ans += (i64) w[l] + (i64) w[r];
    std::cout << ans << '\n';
  }
}
}

int main() {
#ifndef LOCAL_DBG
  std::freopen("subway.in", "r", stdin);
  std::freopen("subway.out", "w", stdout); 
#endif
  std::cin.tie(nullptr)->sync_with_stdio(false);
  silvecor::solve();
  return 0;
}
