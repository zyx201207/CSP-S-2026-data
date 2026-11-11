// hub
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1e6 + 3;

vector<int> a[N];

bool f[N], q[N], g[N];

int dp[N];

int n, k, c, t;

void dfs_2(int x) {
  if (q[x] || !f[x]) return;
  q[x] = 1;
  for (int u : a[x]) {
    dfs_2(u);
  }
}

int dfs_3(int x) {
  int mi = n + 1;
  if (g[x]) return n + 1;
  if (f[x]) return 0;
  g[x] = 1;
  for (int u : a[x]) {
    mi = min(mi, dfs_3(u) + 1);
  }
  g[x] = 0;
  return mi;
}

int check() {
  int ma = 0, t = 0;
  for (int i = 1; i <= n; i++) {
    g[i] = q[i] = 0, dp[i] = n + 1;
  }
  for (int i = 1; i <= n; i++) {
    if (f[i] && !q[i]) {
      if (++t == 3) return n + 1;
      dfs_2(i);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!g[i] && !f[i]) ma = max(ma, dfs_3(i));
  }
  return ma;
}

int dfs(int x, int t) {
  int mi = n + 1;
  if (t == k) return check();
  for (int i = x + 1 ; i <= n; i++) {
    if (f[i]) continue;
    f[i] = 1;
    mi = min(mi, dfs(i, t + 1));
    f[i] = 0;
  }
  return mi;
}

void Solve_0() {
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    a[u].push_back(v), a[v].push_back(u);
  }
  cout << dfs(0, 0) << '\n';
}

int main () {
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
  cin >> c >> t;
  while (t--) {
    Solve_0();
  }
  return 0;
}
