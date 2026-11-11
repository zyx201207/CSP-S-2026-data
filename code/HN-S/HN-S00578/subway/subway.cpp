#include <bits/stdc++.h>
using namespace std;

void File(){
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
}

using ll = long long;
using pii = pair<int, int>;
const ll INF = 1e18;
const int kN = 503;
const int kM = 5e5 + 7;
int w[kM], cid, n, m, d, Q;
ll dis[kN][kN];
vector<pii> b[kM];
signed main(){
  File();
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> cid >> n >> m >> d >> Q;  
  for(int i = 1; i <= m; i++) cin >> w[i];
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++) dis[i][j] = INF;
    dis[i][i] = 0;
  }
  for(int i = 1; i <= n; i++){
    int k; cin >> k; 
    for(int j = 1; j <= k; j++){
      int x, y; cin >> x >> y;
      b[x].push_back({i, y});
    }
  }
  for(int i = 1; i <= m; i++){
    for(int j = 0; j < (int)b[i].size(); j++){
      for(int k = j + 1; k < (int)b[i].size(); k++){
        int u = b[i][j].first, v = b[i][k].first;
        int w1 = b[i][j].second, w2 = b[i][k].second;
        dis[u][v] = dis[v][u] = min(dis[u][v], 1ll * (w1 + w2));
      }
    }
  }
  for(int k = 1; k <= n; k++){
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        dis[i][j] = dis[j][i] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
  while(Q--){
    int s, t; cin >> s >> t;
    ll ans = INF;
    for(int j = 0; j < (int)b[s].size(); j++){
      for(int k = 0; k < (int)b[t].size(); k++){
        int u = b[s][j].first, v = b[t][k].first;
        int w1 = b[s][j].second, w2 = b[t][k].second;
        ans = min(ans, dis[u][v] + w1 + w2);
      }
    }
    cout << ans + w[s] + w[t] << '\n';
  }
  return 0;
}