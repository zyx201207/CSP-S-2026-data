#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define int LL 
int c, n, m, d, q;
const int maxn = 510;
const int maxm = 5e5 + maxn + 10;
vector<PII>out[maxm];
int w[maxm];
LL dist[maxn][maxn];
bitset<maxn>vs;
vector<PII>e[maxn];
inline void add(int u, int v, int w) {
  e[u].emplace_back(v, w);
  e[v].emplace_back(u, w);
}
inline void dijkstra(int s) {
  int S = s;
  dist[s][S] = 0;
  priority_queue<PII, vector<PII>, greater<PII>> q;
  q.emplace(0, S);
  vs.reset(); 
  while(q.size()) {
    int u = q.top().second; q.pop();
    if(vs[u]) continue ;
    vs[u] = 1; 
    int m1 = e[u].size(); 
    for(int i = 0; i < m1; ++ i) {
      int v = e[u][i].first;
      int w = e[u][i].second;
      if(dist[s][v] > dist[s][u] + w) {
        dist[s][v] = dist[s][u] + w;
        q.emplace(dist[s][v], v); 
      }
    }
  }
}
signed main() {
  freopen("subway.in", "r", stdin); 
  freopen("subway.out", "w", stdout); 
  ios :: sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  memset(dist, 0x3f, sizeof dist); 
  cin >> c >> n >> m >> d >> q;
  for(int i = 1; i <= m; ++ i) cin >> w[i]; 
  for(int i = 1; i <= n; ++ i) {
    int k;
    cin >> k;
    for(int j = 1; j <= k; ++ j) {
      int x, t;
      cin >> x >> t;
      out[x].emplace_back(i, t);
    }
  }
  for(int i = 1; i <= m; ++ i) {
    int sz = out[i].size(); 
    for(int j = 0; j  < sz; ++ j) 
      for(int k = j + 1; k < sz; ++ k) {
        // auto [x1, t1] = out[i][j];
        // auto [x2, t2] = out[i][k]; 
        int x1 = out[i][j].first;
        int t1 = out[i][j].second;
        int x2 = out[i][k].first;
        int t2 = out[i][k].second;
        add(x1, x2, t1 + t2); 
      }
  }
  for(int i = 1; i <= n; ++ i) dijkstra(i);
  for(int i = 1; i <= q; ++ i) {
    int x, y;
    cin >> x >> y;
    LL ans = 1e18;
    // for(auto [x1, t1] : out[x])
    //   for(auto [x2, t2] : out[y]) ans = min(ans, t1 + dist[x1][x2] + t2);
    int m1 = out[x].size();
    int m2 = out[y].size(); 
    for(int j = 0; j < m1; ++ j)
      for(int k = 0; k < m2; ++ k) {
        int x1 = out[x][j].first;
        int t1 = out[x][j].second;
        int x2 = out[y][k].first;
        int t2 = out[y][k].second;
        ans = min(ans, t1 + dist[x1][x2] + t2);
      }
    cout << w[x] + ans + w[y] << '\n'; 
  }
  return 0; 
}