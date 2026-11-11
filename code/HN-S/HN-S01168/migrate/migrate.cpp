#include<bits/stdc++.h>

using namespace std;

const int N = 5e3 + 5;

int vis[N], c, t, cnt, n, d;
long long x[N];

void bfs(int b, int e){
  fill(vis + 1, vis + n + 1, -1);
  queue<pair<int, int>> que;
  que.push({b, 0});
  while(que.size()){
    auto u = que.front();
    que.pop();
    if(vis[u.first] != -1){
      if(u.first == e && vis[u.first] == u.second) cnt++;
      continue;
    }
    vis[u.first] = u.second;
    if(u.first == e){
      cnt++;
      continue;
    }
    for(int i = 1; i <= n; i++){
      if(abs(x[i] - x[u.first]) <= d){
        que.push({i, vis[u.first] + 1});
      }
    }
  }
}

bool check(int b, int e){
  cnt = 0;
  bfs(b, e);
  return cnt == 2;
}

void Solve(){
  cin >> n >> d;
  for(int i = 1; i <= n; i++){
    cin >> x[i];
  }
  int ans = 0;
  for(int i = 1; i <= n; i++){
    for(int j = i + 1; j <= n; j++){
      ans += check(i, j);
    }
  }
  cout << ans << '\n';
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  cin >> c >> t;
  while(t--){
    Solve();
  }
  return 0;
}
