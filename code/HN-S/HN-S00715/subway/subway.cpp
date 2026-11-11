#include <bits/stdc++.h>

using namespace std;

const int N = 6e5 + 5, M = 2e3 + 5;

struct S{
  int x, t;
  bool operator<(const S &i) const {return i.t < t;}
};

int w[N], dis[N], dis1[M][M], c, n, m, d, q;
priority_queue<S> pq;
vector<S> g[N];

void dij(int s){
  fill(dis, dis + m + n + 1, INT_MAX);
  pq.push({s, 0});
  while(!pq.empty()){
    S x = pq.top();
    pq.pop();
    if(dis[x.x] != INT_MAX) continue;
    dis[x.x] = x.t;
    for(S v : g[x.x]){
      if(x.t + v.t < dis[v.x]){
        pq.push({v.x, x.t + v.t});
      }
    }
  }
}

void dij1(int s){
  fill(dis1[s], dis1[s] + m + n + 1, INT_MAX);
  pq.push({s, 0});
  while(!pq.empty()){
    S x = pq.top();
    pq.pop();
    if(dis1[s][x.x] != INT_MAX) continue;
    dis1[s][x.x] = x.t;
    for(S v : g[x.x]){
      if(x.t + v.t < dis1[s][v.x]){
        pq.push({v.x, x.t + v.t});
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  cin >> c >> n >> m >> d >> q;
  for(int i = 1; i <= m; i++){
    cin >> w[i];
  }
  for(int i = 1, k; i <= n; i++){
    cin >> k;
    for(int j = 1, u, t; j <= k; j++){
      cin >> u >> t;
      g[i + m].push_back({u, t});
      g[u].push_back({i + m, t});
    }
  }
  if(n <= 200 && m <= 400){
    while(q--){
      int a, b;
      cin >> a >> b;
      dij(a);
      cout << dis[b] + w[a] + w[b] << '\n';
    }
  }
  else if(n <= 500){
    for(int i = 1; i <= n; i++){
      dij1(i);
    }
    while(q--){
      int a, b;
      cin >> a >> b;
      cout << w[a] + w[b] + dis1[a][b] << '\n';
    }
  }
  return 0;
}
