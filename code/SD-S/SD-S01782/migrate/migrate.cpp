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

static constexpr int N = 2e6 + 6;

int n;
i64 d, a[N];
using NSet = std::unordered_set<int>;
std::unordered_map<i64, NSet> f[N][2]; // f[i][0/1] 0: 1path 1: 2path

void clearPrv() {
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 2; ++j) {
      f[i][j].clear(); 
    }
  }
}
void conj(NSet &x, const NSet &y) {
  for (int i : y) x.insert(i); 
}
void subtr(NSet &x, const NSet &y) {
  for (int i : y) {
    auto it = x.find(i);
    if (it != x.end()) {
      std::cerr << "DBG " << i << ' ' << *it << '\n';
      x.erase(it); 
    }
  }
}

void innerSolve() {
  std::cin >> n >> d;
  clearPrv();
  for (int i = 1; i <= n; ++i) std::cin >> a[i];

//  f[1][0][0] = 1;
  for (int i = 2; i <= n; ++i) {
    int bottom = std::lower_bound(a + 1, a + i, (i64) a[i] - (i64) d) - a;
    if (bottom == i) {
//      f[i][0][0] = 1;
      continue; 
    }
    for (int j = bottom; j < i; ++j) {
//      ++f[i][0][a[i] - a[j]];
      f[i][0][a[i] - a[j]].insert(j);
      for (const auto &item : f[j][0]) {
        if (item.first + a[j + 1] - a[j] > d) {
//          f[i][0][a[i] - a[j]] += item.second; 
          conj(f[i][0][a[i] - a[j]], item.second);
        } else {
          if (j == i - 1 or item.first + a[i] - a[j] <= d) {
//            f[i][0][item.first + a[i] - a[j]] += item.second;
            conj(f[i][0][item.first + a[i] - a[j]], item.second);
          } else {
            if (item.first + a[j + 2] - a[j] > d) {
//              f[i][1][a[i] - a[j + 1]] += item.second; 
              conj(f[i][1][a[i] - a[j + 1]], item.second);
            }
          }
        }
      }
      for (const auto &item : f[j][1]) {
        if (item.first + a[j + 1] - a[j] > d) {
//          f[i][1][a[i] - a[j]] += item.second;
          conj(f[i][1][a[i] - a[j]], item.second);
        }
      }
    }
  }

  i64 ans = 0;
  for (int i = 2; i <= n; ++i) {
    NSet curr;
    for (const auto &item : f[i][1]) {
//      std::cerr << "DBG " << i << ' ' << item.first;
//      for (auto it : item.second) std::cerr << ' ' << it;
//      std::cerr << '\n';
      if (item.first != 0) conj(curr, item.second);
    }
//    for (const auto &item : f[i][0]) {
//      subtr(curr, item.second); 
//    }
    ans += (i64) curr.size();
  }
  std::cout << ans << '\n';
}

void solve() {
  int _no, t;
  std::cin >> _no >> t;
  while (t--) innerSolve();
}
}

int main() {
#ifndef LOCAL_DBG
  std::freopen("migrate.in", "r", stdin);
  std::freopen("migrate.out", "w", stdout); 
#endif
  std::cin.tie(nullptr)->sync_with_stdio(false);
  silvecor::solve();
  return 0;
}
