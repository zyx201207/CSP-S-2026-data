#include <bits/stdc++.h>
#define int long long

const int kMaxN = 2e6 + 25, kL = 23;

int tid, T, n, m, siz[kMaxN], dep[kMaxN], r[kMaxN], f[kMaxN][kL], ans = 1e18, rt, mns = 1e18, up[kMaxN], down[kMaxN][2];
std::vector<int> e[kMaxN];
bool b[kMaxN], vis[kMaxN];

void Tran(int x, int p) {
  siz[x] = 1, dep[x] = dep[p] + 1, f[x][0] = p;
  for (int i = 1; i < kL; i++) {
    f[x][i] = f[f[x][i - 1]][i - 1];
  }
  for (auto i : e[x]) {
    if (i != p) {
      Tran(i, x);
      siz[x] += siz[i];
    }
  }
}

inline int Common(int x, int y) {
  if (dep[x] < dep[y]) {
    std::swap(x, y);
  }
  for (int i = kL - 1; i >= 0; i--) {
    if (dep[f[x][i]] >= dep[y]) {
      x = f[x][i];
    }
  }
  if (x == y) {
    return x;
  }
  for (int i = kL - 1; i >= 0; i--) {
    if (f[x][i] != f[y][i]) {
      x = f[x][i], y = f[y][i];
    }
  }
  return f[x][0];
}

int Root(int i) {
  return r[i] == i ? i : r[i] = Root(r[i]);
}

void Connect(int x, int p) {
  if (b[x] && b[p]) {
    int u = Root(x), v = Root(p);
    if (u != v) {
      r[u] = v;
    }
  }
  for (auto i : e[x]) {
    if (i != p) {
      Connect(i, x);
    }
  }
}

void Search(int x, int csum) {
  if (csum > m) {
    return;
  }
  if (x > n) {
    if (csum != m) {
      return;
    }
    std::iota(r + 1, r + 1 + n, 1);
    Connect(1, 0);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (b[i] && i == Root(i)) {
        cnt++;
      }
    }
    if (cnt > 2) {
      return;
    }
    int ret = 0;
    for (int i = 1; i <= n; i++) {
      if (!b[i]) {
        int mn = 1e18;
        for (int j = 1; j <= n; j++) {
          if (b[j]) {
            mn = std::min(mn, dep[i] + dep[j] - 2 * dep[Common(i, j)]);
          }
        }
        ret = std::max(ret, mn);
      }
    }
    ans = std::min(ans, ret);
    return;
  }
  b[x] = 1;
  Search(x + 1, csum + 1);
  b[x] = 0;
  Search(x + 1, csum);
}

void GetDep(int x, int p) {
  for (auto i : e[x]) {
    if (i != p && !vis[i]) {
      GetDep(i, x);
      if (down[i][0] + 1 > down[x][0]) {
        down[x][1] = down[x][0], down[x][0] = down[i][0] + 1;
      } else if (down[i][0] + 1 > down[x][1]) {
        down[x][1] = down[i][0] + 1;
      }
    }
  }
}

void TranUp(int x, int p) {
  up[x] = up[p] + 1;
  for (auto i : e[x]) {
    if (i != p && !vis[i]) {
      TranUp(i, x);
    }
  }
}

void Get(int x, int p) {
  for (auto i : e[x]) {
    if (i != p && !vis[i]) {
      if (std::max(up[i], down[i][0]) < mns) {
        mns = std::max(up[i], down[i][0]), rt = i;
      }
      Get(i, x);
    }
  }
}

inline void GetRoot(int x, int p) {
  for (int i = 1; i <= n; i++) {
    up[i] = 0, down[i][0] = down[i][1] = 0;
  }
  GetDep(x, p);
  for (auto i : e[x]) {
    if (i != p && !vis[i] && down[i][0] + 1 == down[x][0]) {
      up[x] = down[x][1];
      TranUp(i, x);
    } else if (i != p && !vis[i]) {
      up[x] = down[x][0];
      TranUp(i, x);
    }
  }
  up[x] = 0;
  mns = 1e18, rt = 0;
  Get(x, p);
}

inline void Solve() {
  GetRoot(1, 0);
  vis[rt] = 1;
  int ans = 0;
  if (m == 1) {
    for (int i = 1; i <= n; i++) {
      if (!vis[i]) {
        ans = std::max(ans, dep[i] + dep[rt] - 2 * dep[Common(i, rt)]);
      }
    }
    std::cout << ans << '\n';
    return;
  }
  GetRoot(rt, 0);
  vis[rt] = 1;
  std::vector<int> ve;
  for (int i = 1; i <= n; i++) {
    if (vis[i]) {
      ve.emplace_back(i);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      int ret = 1e18;
      for (auto j : ve) {
        ret = std::min(ret, dep[i] + dep[j] - 2 * dep[Common(i, j)]);
      }
      ans = std::max(ans, ret);
    }
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(0)->sync_with_stdio(false);
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
  for (std::cin >> tid >> T; T--;) {
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      e[i].clear(), siz[i] = 0, dep[i] = 0, vis[i] = 0, up[i] = 0;
    }
    for (int i = 1, x, y; i < n; i++) {
      std::cin >> x >> y, e[x].emplace_back(y), e[y].emplace_back(x);
    }
    Tran(1, 0);
    if (n <= 10) {
      ans = 1e18;
      Search(1, 0);
      std::cout << ans << '\n';
      continue;
    }
    if (m <= 2) {
      Solve();
      continue;
    }
  }
  return 0;
}
