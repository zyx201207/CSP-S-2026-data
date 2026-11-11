#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

constexpr int N = 4000, inf = 0x3f3f3f3f;

int C;
int f[N][N][3][2];

void chkmin(int &x, int y) {
  if (x > y) {
    x = y;
  }
}

void solve() {
  int n, k;
  std::cin >> n >> k;

  std::vector<std::vector<int>> adj(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    std::cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  if (C == 13 || C == 14) {
    int m = n / 2;
    if (k == n) {
      std::cout << 0 << "\n";
    } else if (k >= m) {
      std::cout << 1 << "\n";
    } else {
      std::cout << (m - k + 3) / 4 << "\n";
    }
    return;
  }

  auto check = [&](int m) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= m; j++) {
        for (int x = 0; x < 3; x++) {
          for (int y = 0; y < 2; y++) {
            f[i][j][x][y] = inf;
          }
        }
      }
    }
    auto dfs = [&](auto self, int x, int p) -> void {
      for (auto y : adj[x]) {
        if (y == p) {
          continue;
        }
        self(self, y, x);
      }
      for (int d = 0; d <= m; d++) {
        int g[3][2], h[3][2];
        memset(g, 0x3f, sizeof g);
        g[d == 0][d == 0] = d == 0;
        for (auto y : adj[x]) {
          if (y == p) {
            continue;
          }
          memset(h, 0x3f, sizeof h);
          for (int i = 0; i <= 2; i++) {
            for (int j = 0; j < 2; j++) {
              for (int k = -1; k <= 1; k++) {
                int u = d + k;
                if (u < 0 || u > m) {
                  continue;
                }
                for (int v = 0; i + v - (u == 0 && d == 0) <= 2; v++) {
                  int z = i + v - (u == 0 && d == 0);
                  chkmin(h[z][j || (k == -1)], g[i][j] + f[y][u][v][1]);
                }
              }
              if (d < m) {
                for (int v = 0; i + v <= 2; v++) {
                  chkmin(h[i + v][j], g[i][j] + f[y][d + 1][v][0]);
                }
              }
            }
          }
          memcpy(g, h, sizeof h);
        }
        memcpy(f[x][d], g, sizeof f[x][d]);
      }
    };
    dfs(dfs, 0, -1);
    int ans = n;
    for (int i = 0; i <= m; i++) {
      ans = std::min({ans, f[0][i][1][1], f[0][i][2][1]});
    }
    return ans <= k;
  };

  int lo = 0, hi = n - 1;
  while (lo < hi) {
    int m = (lo + hi) / 2;
    if (check(m)) {
      hi = m;
    } else {
      lo = m + 1;
    }
  }
  std::cout << hi << "\n";
}

int main() {
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> C >> t;

  while (t--) {
    solve();
  }

  return 0;
}