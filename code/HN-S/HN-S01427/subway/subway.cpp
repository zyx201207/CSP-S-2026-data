#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAXN1 = 2.5e3 + 1, MAXN2 = 4e4 + 5e2 + 1, MAXN = 1e6 + 5e2 + 1;

struct edge{
  int v, w;
};

struct Node{
  int u;
  ll dis;
  inline bool operator<(const Node &i) const{
    return dis > i.dis;
  }
};

int c, n, m, d, q, x, y, tt, w[MAXN];
ll dis[MAXN1][MAXN1], dis2[MAXN2];

vector<edge> g[MAXN];
priority_queue<Node> pq;
queue<int> que;

inline void add(int u, int v, int w){
  g[u].push_back({v, w});
}

inline void dijkstra(int s){
  for(int i = 1; i <= m * 2 + n; i++){
    dis[s][i] = LLONG_MAX;
  }
  dis[s][s] = 0;
  pq.push({s, 0});
  while(!pq.empty()){
    int u = pq.top().u;
    pq.pop();
    for(const auto &[v, w] : g[u]){
      if(dis[s][v] > dis[s][u] + w){
        dis[s][v] = dis[s][u] + w;
        pq.push({v, dis[s][v]});
      }
    }
  }
}

inline void bfs(int s){
  fill(dis2 + 1, dis2 + 1 + n + m, -1);
  dis2[s] = 0;
  que.push(s);
  while(!que.empty()){
    int u = que.front();
    que.pop();
    if(dis2[y] != -1){
      break;
    }
    for(const auto &[v, w] : g[u]){
      if(dis2[v] == -1){
        dis2[v] = dis2[u] + w;
        que.push(v);
      }
    }
  }
  while(!que.empty()){
    que.pop();
  }
}

inline void Solve1(){
  for(int i = 1; i <= m; i++){
    dijkstra(i);
  }
  while(q--){
    cin >> x >> y;
    cout << w[x] + w[y] + dis[x][y] << '\n';
  }
}

inline void Solve2(){
  while(q--){
    cin >> x >> y;
    bfs(x);
    cout << w[x] + w[y] + dis2[y] << '\n';
  }
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  cin >> c >> n >> m >> d >> q;
  for(int i = 1; i <= m; i++){
    cin >> w[i];
  }
  for(int i = 1, k; i <= n; i++){
    cin >> k;
    for(int j = 1, a, t; j <= k; j++){
      cin >> a >> t;
      tt = t;
      add(a, i + m, t), add(i + m, a, t);
    }
  }
  if(c <= 11){
    Solve1();
    return 0;
  }
  if(c >= 12 && c <= 19 || c >= 20 && c <= 21){
    Solve2();
    return 0;
  }
  Solve1();
  return 0;
}
