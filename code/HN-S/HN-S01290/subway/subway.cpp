#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 5e5 + 10, M = 1510;
const ll inf = 1e18;

int c, n, m, d, q;
int w[N], fa[N], a[N], vis[N];

ll t[N], dis[M][M], dist[N];

struct edge{
  int v;
  ll t;
};

vector<edge> g[N];

struct P{
  int u;
  ll w;
  bool operator < (const P &i) const {
    return w > i.w;
  }
};//Ð¡¸ù¶Ñ

void dij(int x){
  for(int i = 1; i <= m + n; i++) vis[i] = 0, dis[x][i] = inf;
  dis[x][x] = 0;
  priority_queue<P> q;
  q.push({x ,0});
  while(q.size()){
    P nw = q.top();
    q.pop();
    int u  = nw.u, w = nw.w;
    if(vis[u]) continue;
    vis[u] = 1;
    for(edge e : g[u]){
      if(w + e.t < dis[x][e.v]){
        dis[x][e.v] = w + e.t;
        q.push({e.v, dis[x][e.v]});
      }
    }
  }
}

void bfs(int x){
  for(int i = 1; i <= m + n; i++) vis[i] = 0, dist[i] = inf;
  dist[x] = 0;
  queue<int> q;
  q.push(x);
  while(q.size()){
    int u = q.front();
    q.pop();
    if(vis[u]) continue;
    vis[u] = 1;
    for(edge e : g[u]){
      if(dist[e.v] > dist[u] + 1)
        dist[e.v] = dist[u] + 1, q.push(e.v);
    }
  }
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  cin >> c >> n >> m >> d >> q;
  for(int i = 1; i <= m; i++){
    cin >> w[i];
  }
  for(int i = 1; i <= m; i++){
    fa[i] = i + m;
  }
  for(int i = 1, k; i <= n; i++){
    cin >> k;
    for(int j = 1; j <= k; j++){
      cin >> a[j] >> t[j];
      fa[a[j]] = m + i;
    }
    int F = m + i;
    for(int j = 1; j <= k; j++){
      g[a[j]].push_back({F, t[j]});
      g[F].push_back({a[j], t[j]});
    }
  }
  if(c <= 11){
    for(int i = 1; i <= m; i++){
      dij(i);
    }
    while(q--){
      int l, r;
      cin >> l >> r;
//      cout << dis[6][2] << " ";
      cout << dis[l][r] + w[l] + w[r] << "\n";
    }
  }
  else{
    while(q--){
      int l, r;
      cin >> l >> r;
      bfs(l);
      cout << dist[r] * t[1] + w[l] + w[r] << "\n";
    }
  }
  return 0;
}
