#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
const int N = 1e6 + 7;
int id;
int n, k, ans;
int a[N], fa[N];
int find(int x) {
  if (x == fa[x]) {
    return x;
  }
  return fa[x] = find(fa[x]);
}
vector<int> g[N];
int dfs1(int u, int F) {
  if (a[u]) {
    return 0;
  }
  int res = 1e18;
  for (int v : g[u]) {
    if (v != F) {
      res = min(res, dfs1(v, u) + 1);
    }
  }
  return res;
}
void dfs2(int u) {
  if (n - u + 1 < k) {
    return ;
  }
  if (u > n) {
    for (int i = 1; i <= n; ++ i) {
      fa[i] = i;
    }
    for (int i = 1; i <= n; ++ i) {
      if (!a[i]) {
        continue;
      }
      for (int j : g[i]) {
        if (a[j]) {
          fa[find(j)] = find(i);
        }
      }
    }
    int x = 0, y = 0;
    for (int i = 1; i <= n; ++ i) {
      if (a[i]) {
        if (!x) {
          x = find(i);
          continue;
        }
        if (x == find(i)) {
          continue;
        }
        if (!y) {
          y = find(i);
          continue;
        }
        if (y == find(i)) {
          continue;
        }
        return ;
      }
    }
    int res = 0;
    for (int i = 1; i <= n; ++ i) {
      res = max(res, dfs1(i, 0));
    }
    ans = min(ans, res);
    return ;
  }
  dfs2(u + 1);
  if (!k) {
    return ;
  }
  -- k;
  a[u] = 1;
  dfs2(u + 1);
  ++ k;
  a[u] = 0; 
}
signed Luogu_UID_947527() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++ i) {
    g[i].clear();
    a[i] = 0;
  }
  for (int i = 1, u, v; i < n; ++ i) {
    cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  if (n == k) {
    cout << 0 << '\n';
    return 0;
  }
  ans = 1e18;
  dfs2(1);
  cout << ans << '\n';
  return 0;
}
signed main() {
  //system("fc hub.out hub.ans");
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int T = 1;
  cin >> id >> T;
  while (T --) {
    Luogu_UID_947527();
  }
  return 0;
}

