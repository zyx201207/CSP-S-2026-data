#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;

int n, k, f[MAXN], sz[MAXN], dis[MAXN];
vector<int> e[MAXN];

int getfa(int u) { return (f[u] == u ? u : f[u] = getfa(f[u])); }
void Merge(int u, int v) {
  u = getfa(u), v = getfa(v);
  if(u == v) return;
  f[u] = v, sz[v] += sz[u];
}

void Solve() {
  cin >> n >> k;
  for(int i = 1; i <= n; ++i) e[i].clear();
  for(int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  int ans = 1e9;
  for(int s = 0; s < (1 << n); ++s) {
    if(__builtin_popcount(s) != k) continue;
    fill(sz + 1, sz + n + 1, 1);
    fill(dis + 1, dis + n + 1, 0);
    iota(f + 1, f + n + 1, 1);
    for(int i = 1; i <= n; ++i) {
      if(!((s >> (i - 1)) & 1)) continue;
      bool op = 0;
      for(int v : e[i]) {
        if((s >> (v - 1)) & 1) Merge(i, v);
      }
    }
    int cnt = 0;
    for(int i = 1; i <= n; ++i) {
      cnt += (((s >> (i - 1)) & 1) && f[i] == i);
    }
    if(cnt > 2) continue;
    queue<int> que;
    for(int i = 1; i <= n; ++i) {
      if((s >> (i - 1)) & 1) que.push(i), dis[i] = 1;
    }
    for(; !que.empty(); ) {
      int u = que.front();
      que.pop();
      for(int v : e[u]) {
        if(!dis[v]) {
          dis[v] = dis[u] + 1, que.push(v);
        }
      }
    }
    int res = 0;
    for(int i = 1; i <= n; ++i) res = max(res, dis[i] - 1);
    ans = min(ans, res);
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
  int _C, _T;
  for(cin >> _C >> _T; _T--; Solve());
  return 0;
}
