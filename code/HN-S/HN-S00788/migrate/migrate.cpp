#include <bits/stdc++.h>

using Pii = std::pair<int, int>;
using LL = long long;

const int kMaxN = 2e6 + 25, kMaxM = 5e3 + 25;

int tid, T, n, dis[kMaxM][kMaxM], f[kMaxM][kMaxM], lt[kMaxN], rt[kMaxN], sum[kMaxN];
bool vis[kMaxN];
std::vector<int> e[kMaxM];
LL d, x[kMaxN], g[kMaxN][3];

inline void BFS(int s) {
  std::queue<Pii> q;
  std::fill(dis[s] + 1, dis[s] + 1 + n, 1e18);
  std::fill(f[s] + 1, f[s] + 1 + n, 0);
  std::fill(vis + 1, vis + 1 + n, 0);
  for (q.push({s, 0}), dis[s][s] = 0, f[s][s] = 1, vis[s] = 1; !q.empty(); q.pop()) {
    int x = q.front().first, w = q.front().second;
    for (auto i : e[x]) {
      if (!vis[i] && dis[s][i] > w + 1) {
        vis[i] = 1, q.push({i, w + 1});
        dis[s][i] = w + 1, f[s][i] = f[s][x];
      } else if (dis[s][i] == w + 1) {
        f[s][i] = std::min(3, f[s][i] + f[s][x]);
      }
    }
  }
}

inline void Solve() {
  if (n <= 5001) {
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      e[i].clear();
    }
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (x[j] - x[i] <= d) {
          e[i].emplace_back(j), e[j].emplace_back(i);
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      BFS(i);
      for (int j = i; j <= n; j++) {
        ans += (f[i][j] == 2);
      }
    }
    std::cout << ans << '\n';
    return;
  }
  LL ans = 0;
  sum[n + 1] = 0;
  for (int i = 1; i <= n; i++) {
    sum[i] = 0;
    int l = 0, r = i;
    for (int mid; l + 1 < r;) {
      mid = (l + r) >> 1;
      if (x[i] - x[mid] <= d) {
        r = mid;
      } else {
        l = mid;
      }
    }
    lt[i] = r;
    l = i, r = n + 1;
    for (int mid; l + 1 < r;) {
      mid = (l + r) >> 1;
      if (x[mid] - x[i] <= d) {
        l = mid;
      } else {
        r = mid;
      }
    }
    rt[i] = l;
  }
  for (int i = 1; i <= n; i++) {
    ans += sum[lt[i] + 1];
    sum[rt[i]]++;
  }
  std::cout << ans << '\n';
}

int main() {
  std::cin.tie(0)->sync_with_stdio(false);
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  for (std::cin >> tid >> T; T--;) {
    std::cin >> n >> d;
    for (int i = 1; i <= n; i++) {
      std::cin >> x[i];
    }
    Solve();
  }
  return 0;
}
