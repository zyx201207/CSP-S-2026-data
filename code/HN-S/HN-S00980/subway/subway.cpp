#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e2 + 10, MAXM = 5e5 + 10;
const long long INF = 1e17;

int c, n, m, d, q, w[MAXM];
long long dis[MAXN][MAXN];
// vector<int> a[MAXN], t[MAXN];

struct E{ // 第i个地铁站，有什么线路，出站什么时间
  int id;
  long long d; 
};
vector<E> bel[MAXM];

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
    for(int j = 1, x, y; j <= k; j++){
      cin >> x >> y;
      // a[i].push_back(x), t[i].push_back(y);
      bel[x].push_back({i, y});
    }
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      dis[i][j] = INF;
    }
    dis[i][i] = 0;
  }
  for(int i = 1; i <= m; i++){
    for(int j = 0; j < bel[i].size(); j++){
      for(int k = j + 1; k < bel[i].size(); k++){
        E x = bel[i][j], y = bel[i][k];
        dis[x.id][y.id] = dis[y.id][x.id] = min(dis[x.id][y.id], x.d + y.d);
      }
    }
  }
  // for(int i = 1; i <= n; i++){
  //   for(int j = 1; j <= n; j++){
  //     if(i != j && dis[i][j] != INF){
  //       g[i].push_back({j, dis[i][j]});
  //       g[j].push_back({i, dis[i][j]});
  //     }
  //   }
  //   dis[i][i] = 0;
  // }
  for(int k = 1; k <= n; k++){
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
  while(q--){
    int u, v;
    long long ans = INF;
    cin >> u >> v;
    for(E x: bel[u]){
      for(E y: bel[v]){
        // cout << x.id << ' ' << y.id << ' ' << dis[x.id][y.id] << ' ' << dis[x.id][y.id] + x.d + y.d << '\n';
        ans = min(ans, dis[x.id][y.id] + x.d + y.d);
      }
    }
    cout << ans + w[u] + w[v] << '\n';
  }
  return 0;
}