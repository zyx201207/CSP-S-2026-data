#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 5e3 + 5;

struct S{
  int x, t;
};

int dis[N], p;
ll a[N], n, d;
vector<int> g[N];

void bfs(int s){
  fill(dis, dis + n + 1, INT_MAX);
  queue<S> q;
  q.push({s, 0});
  while(!q.empty()){
    S x = q.front();
    q.pop();
    if(dis[x.x] != INT_MAX) continue;
    dis[x.x] = x.t;
    for(int v : g[x.x]){
      if(x.t + 1 < dis[v]){
        q.push({v, x.t + 1});
      }
    }
  }
}

void dfs(int x, int y, int t){
  if(t > dis[y] || dis[y] == INT_MAX || p > 2) return;
  if(x == y){
    ++p;
    return;
  }
  for(int v : g[x]){
    dfs(v, y, t + 1);
  }
}

void Solve(){
  int ans = 0;
  cin >> n >> d;
  for(int i = 1; i <= n; i++){
    g[i].clear();
  }
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  for(int i = 1; i <= n; i++){
    for(int j = i + 1; j <= n; j++){
      if(abs(a[i] - a[j]) <= d){
        g[i].push_back(j);
        g[j].push_back(i);
      }
    }
  }
  for(int i = 1; i <= n; i++){
    bfs(i);
    for(int j = 1; j <= n; j++){
      if(i == j) continue;
      p = 0;
      dfs(i, j, 0);
      ans += (p == 2);
    }
  }
  cout << ans / 2 << '\n';
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  int c, t;
  cin >> c >> t;
  while(t--){
    Solve();
  }
  return 0;
}
