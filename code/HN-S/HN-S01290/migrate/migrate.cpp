#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 5e3 + 10;
const ll inf = 1e18;

vector<int> g[N];

int c, t, n;
ll d, a[N], dis[N][N], cnt[N][N], vis[N];

void dfs(int x, int u, int st){
  if(vis[u]) return ;
  vis[u] = 1;
  if(st < dis[x][u]) dis[x][u] = st, cnt[x][u] = 0;
  if(st == dis[x][u]) cnt[x][u] ++;
  for(int v : g[u]){
    dfs(x, v, st + 1);
  }
  vis[u] = 0;
}

void solve(){
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
    g[i].clear();
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      cnt[i][j] = 0;
    }
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(abs(a[j] - a[i]) <= d){

        g[i].push_back(j);
      }
    }
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      dis[i][j] = inf, vis[j] = 0;;
    }
    dis[i][i] = 0;
    dfs(i, i, 0);
  }
  int ans = 0;
  for(int i = 1; i <= n; i++){
    for(int j = i + 1; j <= n; j++){
      if(cnt[i][j] == 2){
        ans++;
      }
    }
  }
  cout << ans << "\n";
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
   cin >> c >> t;
  while(t--){
    solve();
  }
  return 0;
}
/*
0 1
5 2
1 2 3 4 5

*/
