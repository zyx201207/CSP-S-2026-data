#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define int LL 
const int maxn = 5e5 + 10;
int c, T;
int n, k;
int dist[maxn][maxn]; 
vector<int>e[maxn];
inline void dfs(int s, int u, int pa) {
  for(int v : e[u]) {
    if(v != pa) {
      dist[s][v] = dist[s][u] + 1;
      dfs(s, v, u); 
    }
  }
}
int f[maxn];
inline int find(int x) {
  if(x == f[x]) return x;
  return f[x] = find(f[x]);
}
inline void init() {
  for(int i = 1; i <= n; ++ i) f[i] = i;
}
bitset<maxn>vs;
inline bool check() {
  init(); 
  for(int i = 1; i <= n; ++ i)
    for(int v : e[i]) 
      if(vs[i] && vs[v]) f[v] = i;
  int cnt = 0;
  for(int i = 1; i <= n; ++ i) cnt += (find(i) == i); 
  return cnt <= 2;
}
int ans = 1e9;
inline void dfs2(int u, int tot) {
  if(u == n + 1) {
    if(tot != k) return ;
    if(check()) {
      int cur = 0;
      for(int i = 1; i <= n; ++ i) {
        if(!vs[i]) {
          int cc = 1e9;
          for(int j = 1; j <= n; ++ j) if(vs[j]) cc = min(cc, dist[j][i]); 
          cur = max(cur, cc); 
        }
      }
      ans = min(ans, cur);
    }
  }
  vs[u] = 1, dfs2(u + 1, tot + 1), vs[u] = 0;
  dfs2(u + 1, tot); 
} 
inline void solve() {
  ans = 1e9; 
  for(int i = 1; i < n; ++ i) {
    int u, v;
    cin >> u >> v;
    e[u].emplace_back(v); 
  }
  for(int i = 1; i <= n; ++ i) dfs(i, i, -1); 
  dfs2(1, 0); 
  cout << ans << '\n'; 
}
signed main() {
  freopen("hub.in", "r", stdin); 
  freopen("hub.out", "w", stdout); 
  ios :: sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> c >> T;
  while(T -- ) solve(); 
  return 0; 
}