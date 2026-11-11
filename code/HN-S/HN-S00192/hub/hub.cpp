#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;

int type, n, k;
vector<int> G[MAXN];

namespace sub1{

bool vis[11];
int dis[11];

void DFS1(int u, int s){
  if(vis[u]) return;
  vis[u] = 1;
  for(int v : G[u]){
    if(s >> (v - 1) & 1) DFS1(v, s);
  }
}

void DFS2(int u, int fa, int dep){
  dis[u] = min(dis[u], dep);
  for(int v : G[u]){
    if(v != fa) DFS2(v, u, dep + 1);
  }
}

void Solve(){
  int ans = INT_MAX;
  for(int i = 0; i < 1 << n; i++){
    if(__builtin_popcount(i) != k) continue;
    for(int j = 1; j <= n; j++) vis[j] = 0, dis[j] = INT_MAX;
    int c = 0;
    for(int j = 1; j <= n; j++){
      if((i >> (j - 1) & 1) && !vis[j]) DFS1(j, i), c++;
    }
    if(c > 2) continue;
    for(int j = 1; j <= n; j++){
      if(i >> (j - 1) & 1) DFS2(j, 0, 0);
    }
    ans = min(ans, *max_element(dis + 1, dis + 1 + n));
  }
  cout << ans << '\n';
}

}

void Solve(){
  cin >> n >> k;
  for(int i = 1; i <= n; i++) G[i].clear();
  for(int i = 1, u, v; i < n; i++){
    cin >> u >> v;
    G[u].push_back(v), G[v].push_back(u);
  }
  if(type <= 3){
    sub1::Solve();
  }else{
    if(k == n) return cout << 0 << '\n', void();
    n >>= 1;
    if(k >= n) return cout << 1 << '\n', void();
    n = n - k + 1;
    cout << (n + 3) / 4 + (k & 1) + 1 << '\n';
  }
}

int main(){
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int T; for(cin >> type >> T; T; Solve(), T--);  
  return 0;
}