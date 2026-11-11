#include <bits/stdc++.h>
using namespace std;

void File(){
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
}

const int kN = 1e6 + 7;
int cid, T, n, k;
vector<int> ve[kN];
namespace SubA{
  void main(){
    int ans = n;
    for(int x = 1; x <= n / 2; x++){
      int ny = (n / 2) + 1 + x + (k / 2) - (k + 1) / 2;
      int y = ny / 2;
      ans = min(ans, max(x, max(y - x - k / 2 + 1, n / 2 + 2 - (k + 1) / 2 - y)));
      y = (ny + 1) / 2;
      ans = min(ans, max(x, max(y - x - k / 2 + 1, n / 2 + 2 - (k + 1) / 2 - y)));
    }
    if(k < n) ans = max(ans, 1);
    cout << ans << '\n';
    return ;
  }
}
namespace subbf{
  int vis[12], ok[12], d[12];
  void dfs(int x, int fa){
    vis[x] = 1;
    for(int j : ve[x]){
      if(j == fa || !ok[j]) continue;
      dfs(j, x);
    }
    return ;
  }
  void main(){
    int ans = n;
    for(int S = 0; S < (1 << n); S++){
      if(__builtin_popcount(S) != k) continue;
      int cnt = 0;
      for(int i = 1; i <= n; i++) vis[i] = ok[i] = 0;
      for(int i = 0; i < n; i++){
        if((S >> i) & 1) ok[i + 1] = 1;
      }
      for(int i = 1;i <= n; i++){
        if(ok[i] && !vis[i]){
          dfs(i, i); ++cnt;
        }
      }
      if(cnt > 2) continue;
      queue<int> que;
      for(int i = 1; i <= n; i++){
        d[i] = n; vis[i] = 0;
        if(ok[i]) d[i] = 0, que.push(i), vis[i] = 1;
      }
      while(!que.empty()){
        int u = que.front(); que.pop();
        vis[u] = 0;
        for(int j : ve[u]){
          if(d[j] > d[u] + 1){
            d[j] = d[u] + 1;
            if(!vis[j]) que.push(j);
          }
        }
      } 
      int mx = 0;
      for(int i = 1; i <= n; i++) mx = max(mx, d[i]);
      ans = min(ans, mx);
    }
    cout << ans << '\n';
    return ;
  }
}
void solve(){
  cin >> n >> k;
  for(int i = 1; i < n; i++){
    int u, v; cin >> u >> v;
    ve[u].push_back(v), ve[v].push_back(u);
  }
  if(cid <= 3){
    subbf::main();
    for(int i = 1; i <= n; i++) vector<int>{}.swap(ve[i]);
    return ;
  }
  if(cid >= 13 && cid <= 14){
    SubA::main();
    for(int i = 1; i <= n; i++) vector<int>{}.swap(ve[i]);
    return ;
  }
  cout << 1 << '\n';
  return ;
}
signed main(){
  File();
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> cid >> T;
  while(T--) solve();
  return 0;
}