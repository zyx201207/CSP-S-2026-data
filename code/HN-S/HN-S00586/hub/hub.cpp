#include <bits/stdc++.h>
// #define MEMORY
using namespace std;
using LL = long long;
bool Mbe;

const int N = 4005;
int tid, t, n, k, d[N][N];
bool fl[N], vis[N];
vector<int> e[N];

void Dfs(int u, int fa, int st) {
  for (int v : e[u]) {
    v != fa && (d[st][v] = d[st][u] + 1, Dfs(v, u, st), 1);
  }
}

void Dfs(int u) {
  vis[u] = 1;
  for (int v : e[u]) !vis[v] && fl[v] && (Dfs(v), 1);
}

int Calc(int s, int x) {
  int res = 1e9;
  for (int i = 1; i <= n; i++) {
    ((s >> i - 1) & 1) && (res = min(res, d[x][i]));
  }
  return res;
}

int Solve(int s) {
  if (__builtin_popcount(s) != k) return 1e9;
  for (int i = 1; i <= n; i++) {
    fl[i] = ((s >> i - 1) & 1), vis[i] = 0;
  }
  for (int i = 1, cnt = 0; i <= n; i++) {
    !vis[i] && fl[i] && (Dfs(i), cnt++);
    if (cnt > 2) return 1e9;
  }
  int res = 0;
  for (int i = 1; i <= n; i++) res = max(res, Calc(s, i));
  return res;
}

bool Med;
int main() {
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
#ifdef MEMORY
  cerr << abs(&Mbe - &Med) / 1048576.0 << "\n";
#endif
  cin.tie(0)->sync_with_stdio(0);
  for (cin >> tid >> t; t; t--) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) e[i].clear();
    for (int i = 1, u, v; i < n; i++) {
      cin >> u >> v;
      e[u].push_back(v), e[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) d[i][i] = 0, Dfs(i, 0, i);
    int ans = 1e9;
    for (int s = 0; s < (1 << n); s++) ans = min(ans, Solve(s));
    cout << ans << "\n";
  }
  return 0;
}