#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

const int kMaxN = 1e6 + 5, kLog = 21, kMaxM = 105;

int f[kMaxM][kMaxM], g[kMaxM], d[kMaxN], dfn[kMaxN], id[kMaxN], fa[kMaxN][kLog], len[kMaxN], siz[kMaxN], c, t, n, k, cnt;
tuple<int, int, int> pre[kMaxN], suf[kMaxN];
vector<int> e[kMaxN];

void getDepth(int x, int f) {
  d[x] = d[f] + 1;
  for (int i : e[x]) {
    if (i != f) {
      getDepth(i, x);
    }
  }
}

void k2(int x, int f) {
  fa[x][0] = f;
  len[x] = d[x] = d[f] + 1;
  for (int i = 1; i < kLog; i++) {
    fa[x][i] = fa[fa[x][i - 1]][i - 1];
  }
  dfn[x] = ++cnt;
  id[cnt] = x;
  siz[x] = 1;
  for (int i : e[x]) {
    if (i != f) {
      k2(i, x);
      len[x] = max(len[x], len[i]);
      siz[x] += siz[i];
    }
  }
}

void jump(int &x, int y) {
  for (int i = 0; i < kLog; i++) {
    if (y >> i & 1) {
      x = fa[x][i];
    }
  }
}

int lca(int x, int y) {
  if (d[x] < d[y]) {
    swap(x, y);
  }
  jump(x, d[x] - d[y]);
  if (x == y) {
    return x;
  }
  for (int i = kLog - 1; i >= 0; i--) {
    if (fa[x][i] != fa[y][i]) {
      x = fa[x][i];
      y = fa[y][i];
    }
  }
  return fa[x][0];
}

int dis(int x, int y) {
  if (!x || !y) {
    return 0;
  }
  return d[x] + d[y] - 2 * d[lca(x, y)];
}

tuple<int, int, int> get(int s, int t) {
  return make_tuple(dis(s, t), s, t);
}

tuple<int, int, int> add(const tuple<int, int, int> &a, const tuple<int, int, int> &b) {
  int s = get<1>(a), t = get<2>(a), p = get<1>(b), q = get<2>(b);
  return max(max(a, b), max(max(get(s, p), get(s, q)), max(get(t, p), get(t, q))));
}

void dfs(int x, int fa) {
  len[x] = d[x] = d[fa] + 1;
  for (int i : e[x]) {
    if (i == fa) {
      continue;
    }
    dfs(i, x);
    len[x] = max(len[x], len[i]);
  }
  siz[x] = 1;
  f[x][1] = 0;
  for (int i : e[x]) {
    if (i == fa) {
      continue;
    }
    fill(g + 1, g + siz[x] + siz[i] + 1, 1e9);
    for (int j = 1; j <= siz[x]; j++) {
      for (int k = 0; k <= siz[i]; k++) {
        int zrr = k ? f[i][k] : len[i] - d[x];
        g[j + k] = min(g[j + k], max(f[x][j], zrr));
      }
    }
    copy(g + 1, g + siz[x] + siz[i] + 1, f[x] + 1);
    siz[x] += siz[i];
  }
}

int main() {
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  for (cin >> c >> t; t; t--) {
    cin >> n >> k;
    for (int i = 1, u, v; i < n; i++) {
      cin >> u >> v;
      e[u].push_back(v);
      e[v].push_back(u);
    }
    if (k == 1) {
      getDepth(1, 0);
      getDepth(max_element(d + 1, d + n + 1) - d, 0);
      cout << (*max_element(d + 1, d + n + 1) + 1) / 2 << '\n';
      continue;
    }
    if (k == 2) {
      k2(1, 0);
      for (int i = 1; i <= n; i++) {
        pre[i] = add(pre[i - 1], make_tuple(0, id[i], id[i]));
      }
      for (int i = n; i >= 1; i--) {
        suf[i] = add(suf[i + 1], make_tuple(0, id[i], id[i]));
      }
      int ans = 1e9;
      for (int i = 1; i <= n; i++) {
        int d1 = len[i] - d[i];
        int d2 = get<0>(add(pre[dfn[i] - 1], suf[dfn[i] + siz[i]]));
        ans = min(ans, max(d1, (d2 + 1) / 2));
      }
      cout << ans << '\n';
      continue;
    }
    dfs(1, 0);
    k2(1, 0);
    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (dfn[i] <= dfn[j] && dfn[j] <= dfn[i] + siz[i] - 1 ||
            dfn[j] <= dfn[i] && dfn[i] <= dfn[j] + siz[j] - 1) {
          continue;
        }
        int d = 1e9;
        for (int k = 1; k <= n; k++) {
          if (dfn[i] <= dfn[k] && dfn[k] <= dfn[i] + siz[i] - 1 ||
              dfn[j] <= dfn[k] && dfn[k] <= dfn[j] + siz[j] - 1) {
            continue;
          }
          d = min(d, min(dis(k, i), dis(k, j)));
        }
        if (d == 1e9) {
          d = 0;
        }
        for (int p = 1; p < k; p++) {
          ans = min(ans, max(d, max(f[i][min(p, siz[i])], f[j][min(siz[j],k - p)])));
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}