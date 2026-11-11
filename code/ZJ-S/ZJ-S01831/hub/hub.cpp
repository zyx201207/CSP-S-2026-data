#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long;
constexpr int inf = 1e9;
constexpr int N = 1e6 + 5;

int sub_id, T;

int n, m, d[N], f[N], g[N], real_fa[N], dep[N];
bool vis[N], bel[N];
vector<int> G[N];



int ans;

vector<int> vec;

void dfs_tmp(int u, int fa) {
  bel[u] = true;
  for (int v : G[u]) {
    if (v == fa) continue;
    dfs_tmp(v, u);
  }
}

void work(int del_u, int del_v) {
  for (int i = 1; i <= n; ++i) {
    bel[i] = false;
  }
  dfs_tmp(del_u, del_v);

  // int l = 1, r = n;
  // while (l <= r) {
  //   int mid = (l + r) >> 1;

  queue<pair<int, int>> q;
  for (int i = 1; i <= n; ++i) {
    vis[i] = false;
    d[i] = G[i].size();
    if (i == del_u || i == del_v) {
      --d[i];
    }
  }


  int node = n, cnt_true = 0, cnt_false = 0;
  for (int i = 1; i <= n; ++i) {
    cnt_true += bel[i];
    cnt_false += !bel[i];
  }

  for (int i = 1; i <= n; ++i) {
    if (d[i] <= 1) {
      q.emplace(i, 1);
      vis[i] = true;
      if (bel[i]) {
        --cnt_true;
      } else {
        --cnt_false;
      }
      --node;
    }
  }

  if (node + (!cnt_true) + (!cnt_false) <= m) ans = min(ans, 1);

  while (!q.empty()) {
    int u = q.front().first;
    int dis = q.front().second;
    q.pop();
    // if (dis == mid) continue;

    for (int v : G[u]) {
      if (vis[v] || (v == del_v && u == del_u) || (v == del_u && u == del_v)) continue;

      if (--d[v] <= 1) {
        vis[v] = true;
        q.emplace(v, dis + 1);
        if (bel[v]) {
          --cnt_true;
        } else {
          --cnt_false;
        }
        --node;
      }
    }

    if (node + (!cnt_true) + (!cnt_false) <= m) {
      ans = min(ans, dis + 1);
    }
  }

  //   node += !cnt_true;
  //   node += !cnt_false;

  //   if (node <= m) {
  //     r = mid - 1;
  //   } else {
  //     l = mid + 1;
  //   }
  // }

  // ans = min(ans, l);
}


int mx_dep = 0, real_mx_dep = 0;

void dfs0(int u, int fa) {
  if (f[u] > f[mx_dep]) mx_dep = u;
  for (int v : G[u]) {
    if (v == fa) continue;
    f[v] = f[u] + 1;
    dfs0(v, u);
  }
}

void dfs1(int u, int fa) {
  // if (f[u] < f[mx_dep]) mx_dep = u;
  if (f[u] > real_mx_dep) real_mx_dep = f[u];
  g[u] = 0;
  for (int v : G[u]) {
    if (v == fa) continue;
    real_fa[v] = u;
    f[v] = f[u] + 1;
    dfs1(v, u);
    g[u] = max(g[u], g[v] + 1); 
  }
}

// int st[20][N], L[N], R[N], cnt_dfn, dfn[N], rev[N];

// void dfs0(int u, int fa) {
//   rev[dfn[u] = ++cnt_dfn] = u;
//   st[0][cnt_dfn] = fa;
//   L[u] = cnt_dfn;

//   f[u] = 0, g[u] = 0;
//   for (int v : G[u]) {
//     if (v == fa) continue;
//     real_fa[v] = u;
//     dep[v] = dep[u] + 1;
//     dfs0(v, u);

//     f[u] = max(f[u], f[v]);
//     f[u] = max(f[u], g[v] + g[u] + 1);
//     g[u] = max(g[u], g[v] + 1);
//   }

//   R[u] = cnt_dfn;
// }

// inline int cmp(int u, int v) {
//   return dfn[u] < dfn[v] ? u : v;
// }

// inline int get_lca(int u, int v) {
//   if (u == v) return u;
//   int l = dfn[u], r = dfn[v];
//   if (l > r) swap(l, r);
//   ++l;
//   int k = __lg(r - l + 1);
//   return cmp(st[k][l], st[k][r - (1 << k) + 1]);
// }
// inline int get_dis(int u, int v) {
//   if (u == v) return 0;
//   // assert(u > 0 && v > 0);
//   cerr << u << ' ' << v << '\n';
//   int lca = get_dis(u, v);
//   // return dep[u] + dep[v];
//   return dep[u] + dep[v] - 2 * dep[lca];
// }

// struct Node {
//   int u, v, dis;
//   Node() {}
//   Node(int _u, int _v, int _dis) : u(_u), v(_v), dis(_dis) {}
// };

// inline Node merge(const Node& ls, const Node& rs) {
//   Node p;
//   if (ls.dis > rs.dis) {
//     p = ls;
//   } else {
//     p = rs;
//   }

//   int tmp = get_dis(ls.u, rs.u);
//   if (tmp > p.dis) {
//     p.dis = tmp, p.u = ls.u, p.v = rs.u;
//   }
//   tmp = get_dis(ls.u, rs.v);
//   if (tmp > p.dis) {
//     p.dis = tmp, p.u = ls.u, p.v = rs.v;
//   }
//   tmp = get_dis(ls.v, rs.u);
//   if (tmp > p.dis) {
//     p.dis = tmp, p.u = ls.v, p.v = rs.u;
//   }
//   tmp = get_dis(ls.v, rs.v);
//   if (tmp > p.dis) {
//     p.dis = tmp, p.u = ls.v, p.v = rs.v;
//   }
//   return p;
// }

// Node pre[N], suf[N];

void solve_main() {
  cin >> n >> m;
  ans = n;
  for (int i = 1; i <= n; ++i) {
    G[i].clear();
  }
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  if (n == m) {
    cout << 0 << '\n';
    return;
  }
  // cnt_dfn = 0;
  mx_dep = 1, real_mx_dep = 0;
  f[1] = 0;
  dfs0(1, 0);

  f[mx_dep] = 0;
  dfs1(mx_dep, 0);

  // for (int i = 1, _i = __lg(n); i <= _i; ++i) {
  //   int B = 1 << (i - 1);
  //   for (int j = 1; j <= n - (1 << i) + 1; ++j) {
  //     st[i][j] = cmp(st[i - 1][j], st[i - 1][j + B]);
  //   }
  // }
  // cout << get_lca(2, 3) << '\n';

  // pre[1] = Node(rev[1], rev[1], 0);
  // suf[1] = Node(rev[n], rev[n], 0);
  // for (int i = 2; i <= n; ++i) {
  //   pre[i] = merge(Node(rev[i], rev[i], 0), pre[i - 1]);
  // }

  // for (int i = n - 1; i >= 1; --i) {
  //   suf[i] = merge(Node(rev[i], rev[i], 0), suf[i + 1]);
  // }

  // int mn = inf, pos = 0;
  // for (int i = 1; i <= n; ++i) {
  //   if (i == 1) continue;
  //   int v = f[i];
  //   if (L[i] > 1 && R[i] < n) {
  //     v = max(v, merge(pre[L[i] - 1], suf[R[i] + 1]).dis);
  //   } else if (L[i] > 1) {
  //     v = max(v, pre[L[i] - 1].dis);
  //   } else {
  //     v = max(v, suf[R[i] + 1].dis);
  //   }
  //   if (v < mn) {
  //     mn = v, pos = i;
  //   }
  // }

  if (sub_id <= 10) {
    for (int pos = 1; pos <= n; ++pos) {
      if (pos == mx_dep) continue;
      work(pos, real_fa[pos]);
    }
  }
  if (sub_id > 10 && sub_id <= 14) {
    for (int pos = 1; pos <= n; ++pos) {
      if (pos == mx_dep) continue;
      if (f[pos] == real_mx_dep - real_mx_dep / 2 && g[pos] == real_mx_dep / 2) {
        work(pos, real_fa[pos]);
        break;
      }
    }
  }
  if (sub_id > 14) {
    for (int pos = 1; pos <= n; ++pos) {
      if (pos == mx_dep) continue;
      if (abs(f[pos] - real_mx_dep + real_mx_dep / 2) <= 10 && abs(g[pos] - real_mx_dep / 2) <= 10) {
        work(pos, real_fa[pos]);
      }

    }
  }

  cout << ans << '\n';
}

int main() {
  assert(freopen("hub.in", "r", stdin));
  assert(freopen("hub.out", "w", stdout));
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> sub_id >> T;
  while (T--) {
    solve_main();
  }
  return 0;
}