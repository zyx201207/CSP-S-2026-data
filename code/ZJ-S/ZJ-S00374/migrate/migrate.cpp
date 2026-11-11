#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
  int n;
  i64 d;
  std::cin >> n >> d;

  std::vector<i64> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  std::vector<int> nxt(n);
  for (int i = n - 1, j = n - 1; i >= 0; i--) {
    while (a[j] - a[i] > d) {
      j--;
    }
    nxt[i] = j;
  }
  std::vector<std::vector<int>> adj(n);
  for (int i = 0; i < n; i++) {
    if (nxt[i] != i) {
      adj[nxt[i]].push_back(i);
    }
  }

  std::vector<std::array<int, 2>> to(n);
  auto work = [&](int l, int r) {
    i64 ans = 0;
    auto dfs = [&](auto self, int x) -> void {
      for (auto y : adj[x]) {
        self(self, y);
        int s = 0;
        bool ok = true;
        if (nxt[x - 1] == nxt[x]) {
          s++;
          if (y > l && a[x - 1] - a[y - 1] <= d) {
            ok = false;
          }
          if (nxt[x - 2] == nxt[x]) {
            s++;
          }
        }
        if (!ok) {
          if (s < 2) {
            to[x][s]++;
          }
        } else {
          for (int i = 0; i < 2; i++) {
            if (i + s < 2) {
              to[x][i + s] += to[y][i];
            }
          }
        }
        if (x != r) {
          int L, R = nxt[x] + 1;
          {
            int lo = x, hi = nxt[x];
            while (lo < hi) {
              int m = (lo + hi + 1) / 2;
              if (a[m] - a[x - 1] <= d) {
                lo = m;
              } else {
                hi = m - 1;
              }
            }
            L = lo;
          }
          if (x > l + 1) {
            int lo = x + 1, hi = nxt[x] + 1;
            while (lo < hi) {
              int m = (lo + hi) / 2;
              if (a[m] - a[x - 2] > d) {
                hi = m;
              } else {
                lo = m + 1;
              }
            }
            R = hi;
          }
          ans += 1LL * (nxt[x] - L) * to[y][1];
          if (y == l || a[x - 1] - a[y - 1] > d) {
            ans += 1LL * std::max(0, L - R + 1) * to[y][0];
          } else {
            ans += std::max(0, L - R + 1);
          }
        }
      }
      to[x][0]++;
    };
    dfs(dfs, r);

    return ans;
  };

  int lst = 0;
  i64 ans = 0;
  for (int i = 0; i < n; i++) {
    if (nxt[i] == i) {
      ans += work(lst, i);
      lst = i + 1;
    }
  }
  std::cout << ans << "\n";
}

int main() {
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int c, t;
  std::cin >> c >> t;

  while (t--) {
    solve();
  }

  return 0;
}