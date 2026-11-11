#include <bits/stdc++.h>
using namespace std;

void File(){
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
}

using ll = long long;
const int kN = 2e6 + 7;
int cid, T, n;
ll d, a[kN];
namespace SubA{
  void main(){
    ll p = a[2] - a[1];
    if(p > d){
      cout << 0 << '\n';
      return ;
    }
    ll k = d / p;
    if((k + 1) * p <= d) ++k;
    if(k == 1){
      cout << 0 << '\n';
    }
    else cout << max(0ll, 1ll * n - (2ll * k - 1)) << '\n';
    return ;
  }
}
namespace Subbf{
  int cnt[kN], dis[kN], ans, que[kN], ft, tl, vis[kN];
  void bfs(int s){
    for(int i = 1; i <= s; i++) dis[i] = n + 1, cnt[i] = vis[i] = 0;
    dis[s] = 0, cnt[s] = 1;
    ft = 1, tl = 0; que[++tl] = s; vis[s] = 1;
    while(ft <= tl){
      int u = que[ft]; ++ft; vis[u] = 0; 
      for(int j = u - 1; j >= 1; j--){
        if(a[u] - a[j] > d) break;
        if(dis[j] >= dis[u] + 1){
          dis[j] = dis[u] + 1;
          cnt[j] += cnt[u];
          if(!vis[j]) vis[j] = 1, que[++tl] = j;
        }
      }
    }
    for(int i = 1; i < s; i++) ans += (cnt[i] == 2);
    return ;
  }
  void main(){
    ans = 0;
    for(int i = 1; i <= n; i++){
      if(i > 1){
        bfs(i);
      }
    }
    cout << ans << '\n';
    return; 
  }
}
void solve(){
  cin >> n >> d;
  for(int i = 1; i <= n; i++) cin >> a[i];
  if(n == 1){
    cout << 0 << '\n';
    return ;
  }
  if(cid <= 10){
    Subbf::main();
    return ;
  }
  if(cid >= 11 && cid <= 12){
    SubA::main();
    return ;
  }
  cout << 0 << '\n';  
  return ;
}
signed main(){
  File();
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> cid >> T;
  while(T--) solve();
  return 0;
}