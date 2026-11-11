#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int M = 2e5 + 10, N = 5e5 + 10;
int id, n, m, d, q, sx, fx, w[M], len[N];
struct P{
  ll x, pre;
}dis[M];
vector<int> t[N], a[N], v[M], vis[M];
queue<int> que;
void check(int x, int time){
  if(dis[x].x <= time){
    return;
  }
  dis[x] = {time, x};
  que.push(x);
}
void bfs(){
  check(sx, 0);
  while(!que.empty()){
    int x = que.front();
    que.pop();
    for(auto pos : vis[x]){
      for(int i = 0;i < len[pos];i++){
        check(a[pos][i], dis[x].x + t[pos][i]);
      }
    }
  }
}
int main(){
  ios::sync_with_stdio(false), cin.tie(0);
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  cin >> id >> n >> m >> d >> q;
  for(int i = 1;i <= m;i++){
    cin >> w[i];
  }
  for(int i = 1;i <= n;i++){
    cin >> len[i];
    for(int j = 1;j <= len[i];j++){
      int x, time;
      cin >> x >> time;
      a[i].push_back(x);
      t[i].push_back(time);
      vis[x].push_back(i);
    }
  }
  while(q--){
    cin >> sx >> fx;
    sx--, fx--;
    for(int i = 1;i <= m;i++){
      dis[i] = {LLONG_MAX, 0};
    }
    bfs();
    cout << w[sx] + t[sx][sx] + dis[fx].x + t[dis[fx].pre][fx] + w[fx] << '\n';
  }
  return 0;
}
/**
qwq这就是提高组吗吓哭了
**/
