#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 1;

int c, t, n, k, ans, a[MAXN], d[MAXN];
bool vis[MAXN], flag[MAXN];

vector<int> g[MAXN];

inline void add(int u, int v){
  g[u].push_back(v);
}

inline void dfs1(int u){
  flag[u] = 1;
  for(const auto &v : g[u]){
    if(!flag[v] && vis[v]){
      dfs1(v);
    }
  }
}

inline void dfs2(int u, int fa){
  for(const auto &v : g[u]){
    if(v == fa){
      continue;
    }
    d[v] = d[u] + 1;
    dfs2(v, u);
  }
}

inline bool check(){
  int cnt = 0;
  fill(flag + 1, flag + 1 + n, 0);
  for(int i = 1; i <= n; i++){
    if(vis[i] && !flag[i]){
      dfs1(i);
      cnt++;
      if(cnt > 2){
        return 0;
      }
    }
  }
  return 1;
}

inline int calc(){
  int ans = 0;
  for(int i = 1; i <= n; i++){
    fill(d + 1, d + 1 + n, 0);
    dfs2(i, 0);
    int minn = n + 1;
    for(int j = 1; j <= n; j++){
      if(vis[j]){
        minn = min(minn, d[j]);
      }
    }
    ans = max(ans, minn);
  }
  return ans;
}

inline void dfs(int x, int t){
  if(x == n + 1 || t == k + 1){
    if(t != k + 1){
      return;
    }
    if(check()){
      ans = min(ans, calc());
    }
    return;
  }
  dfs(x + 1, t);
  a[t] = x, vis[x] = 1;
  dfs(x + 1, t + 1);
  vis[x] = 0;
}

inline void Solve1(){
  cin >> n >> k;
  for(int i = 1; i <= n; i++){
    g[i].clear(), vis[i] = a[i] = 0;
  }
  ans = n + 1;
  for(int i = 1, u, v; i < n; i++){
    cin >> u >> v;
    add(u, v), add(v, u);
  }
  dfs(1, 1);
  cout << ans << '\n';
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
  cin >> c >> t;
  while(t--){
    if(c <= 3){
      Solve1();
    }
  }
  return 0;
}
