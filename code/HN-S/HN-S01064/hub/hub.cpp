#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 5;

bool vishert[MAXN];
vector<int> g[MAXN];
int Tid, T, n, k, ans, dep[MAXN], fa[MAXN][20];

// void getheart(int x, int fx) {
//   sz[x] = 1;
//   int mx = 0;
//   for (auto y : g[x]) {
//     if (y != fx && !visheart[y]) {
//       getheart(y, x), sz[x] += sz[y];
//       mx = max(mx, sz[y]);
//     }
//   }
//   if (max(mx, SZ - sz[x]) * 2 <= SZ) {
//     heart = x;
//   }
// }

// void dfs(int x, int fx) {
//   dep[x] = maxdep[x];
//   for (auto y : g[x]) {
//     if (y != fx && !visheart[y]) {
//       dfs(y, x), dep[x] = max(dep[x], dep[y] + 1);
//     }
//   }
// }

// void dfs(int x, int fx)

// bool Check(int u, int lim) {

// }

// void solve(int u) {
//   getheart(u, 0), u = heart;
//   visheart[u] = 1;
//   vector<int> son;
//   int fir = -1, sec = -1;
//   for (auto y : g[x]) {
//     if (y != fx && !visheart[y]) {
//       son.push_back(y), dfs(y, x);
//       if (dep[y] > fir) {
//         sec = fir, fir = dep[y];
//       } else sec = max(sec, deep[y]);
//     }
//   }

//   for (auto u : son) {
//     SZ = sz[u], maxdep[u] = max(maxdep[u], (fir == dep[u] ? sec : fir) + 2);
//     solve(u);
//   }
// }

bool vis[MAXN];
vector<int> path, ve;

void dfs(int x, int fx) {
  dep[x] = dep[fx] + 1, fa[x][0] = fx;
  for (int i = 1; i < 20; i++) {
    fa[x][i] = fa[fa[x][i - 1]][i - 1];
  }
  for (auto y : g[x]) {
    if (y != fx) dfs(y, x);
  }
}

int Lca(int u, int v) {
  if (dep[u] > dep[v]) swap(u, v);
  for (int k = dep[v] - dep[u], i = 0; i < 20; i++) {
    if ((k >> i) & 1) v = fa[v][i];
  }
  if (u == v) return u;
  for (int i = 19; i >= 0; i--) {
    if (fa[u][i] != fa[v][i]) {
      u = fa[u][i], v = fa[v][i];
    }
  }
  return fa[u][0];
}

int Dis(int u, int v) {
  return dep[u] + dep[v] - 2 * dep[Lca(u, v)];
}

void Dfs(int t, int c, int lian) {
  if (n - t + 1 < k - c || c > k) return ;
  if (t == n + 1) {
    if (lian > 2) return ;
    int s = 0;
    for (int i = 1; i <= n && s < ans; i++) {
      if (!vis[i]) {
        int mi = n;
        for (auto u : ve) {
          mi = min(mi, Dis(i, u));
        }
        s = max(s, mi);
      }
    }
    // cout << s << ' ';
    // for (auto u :ve) cout << u << ' ';
    // cout << '\n';
    ans = min(ans, s);
    return ;
  }
  ve.push_back(t), vis[t] = 1;
  for (auto u : g[t]) lian -= vis[u];
  Dfs(t + 1, c + 1, lian + 1);
  for (auto u : g[t]) lian += vis[u];
  ve.pop_back(), vis[t] = 0;
  Dfs(t + 1, c, lian);
}

void Solve() {
  cin >> n >> k, ans = n;
  for (int i = 1, u, v; i < n; i++) {
    cin >> u >> v;
    g[u].push_back(v), g[v].push_back(u);
  }
  dfs(1, 0), Dfs(1, 0, 0);
  cout << ans << '\n';
  // SZ = 1, ans = n, solve(1);
  
}

void Clear() {
  for (int i = 1; i <= n; i++) {
    g[i].clear();
  }
}

int main() {
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  for (cin >> Tid >> T; T--; ) {
    Solve(), Clear();
  }
  return 0;
}