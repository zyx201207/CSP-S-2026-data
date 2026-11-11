#include <bits/stdc++.h>

using namespace std;

const int MAXN = 20, MAXX = (1 << 10);

int c, t, n, k, fa[MAXN][20], dep[MAXN], dis[MAXN];
vector<int> g[MAXN]; 
bool v[MAXN], vv[MAXN];

void dfs(int x, int f){
  if(!v[x]) return ;
  vv[x] = 1;
  for(int xx: g[x]){
    if(xx == f) continue;
    dfs(xx, x);
  }
}

void dfs1(int x, int f){
  fa[x][0] = f, dep[x] = dep[f] + 1;
  for(int i = 1; i < 10; i++){
    fa[x][i] = fa[fa[x][i - 1]][i - 1];
  }
  for(int xx: g[x]){
    if(xx == f) continue;
    dfs1(xx, x);
  }
}

int Lca(int a, int b){
  if(dep[a] > dep[b]) swap(a, b);
  int d = dep[b] - dep[a];
  for(int i = 9; i >= 0; i--){
    if(d >> i & 1) b = fa[b][i];
  }
  if(a == b) return a;
  for(int i = 9; i >= 0; i--){
    if(fa[a][i] != fa[b][i]) a = fa[a][i], b = fa[b][i];
  }
  return fa[a][0];
}

void Solve(){
  cin >> n >> k;
  for(int i = 1, u, v; i < n; i++){
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs1(1, 0);
  int ans = 1e9;
  for(int i = 1; i < (1 << n); i++){
    if(__builtin_popcount(i) != k) continue;
    for(int j = 1; j <= n; j++) v[j] = vv[j] = 0;
    for(int j = 1; j <= n; j++){
      if(i >> (j - 1) & 1) v[j] = 1;
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
      if(v[i] && !vv[i]){
        dfs(i, 0), cnt++;
      }
    }
    if(cnt > 2) continue;
    for(int j = 1; j <= n; j++) dis[j] = (v[j] ? 0 : 1e9);
    for(int j = 1; j <= n; j++){
      if(!v[j]) continue;
      for(int k = 1; k <= n; k++){
        int lca = Lca(j, k);
        dis[k] = min(dis[k], dep[k] + dep[j] - 2 * dep[lca]);
      }
    }
    int anss = 0;
    for(int j = 1; j <= n; j++) anss = max(anss, dis[j]);
    ans = min(ans, anss); 
  }
  cout << ans << '\n';

  for(int i = 1; i <= n; i++){
    g[i].clear();
    for(int j = 0; j < 10; j++) fa[i][j] = 0;
    dep[i] = 0;
  }
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
  cin >> c >> t;
  while(t--){
    Solve();
  }
  return 0;
}