#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int MAXN = 5e5 + 5, MAXM = 5e2 + 5;
const ll INF = 1e18;

int type, n, m, d, q, w[MAXN];
vector<pii> s[MAXN];
ll dis[MAXM][MAXM];

int main(){
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> type >> m >> n >> d >> q;
  for(int i = 1; i <= n; i++) cin >> w[i];
  for(int i = 1, k, x, t; i <= m; i++){
    cin >> k;
    for(; k; k--){
      cin >> x >> t;
      s[x].push_back({i, t});
    }
  }
  for(int i = 1; i <= m; i++){
    for(int j = 1; j <= m; j++) dis[i][j] = i == j ? 0 : INF;
  }
  for(int i = 1; i <= n; i++){
    int sz = s[i].size();
    for(int j = 0; j < sz; j++){
      for(int k = 0; k < j; k++){
        int u = s[i][j].first, v = s[i][k].first;
        dis[u][v] = dis[v][u] = min(dis[u][v], 0ll + s[i][j].second + s[i][k].second);
      }
    }
  }
  for(int k = 1; k <= m; k++){
    for(int i = 1; i <= m; i++){
      for(int j = 1; j <= m; j++) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    }
  }
  for(int x, y; q; q--){
    cin >> x >> y;
    ll res = INF;
    int szx = s[x].size(), szy = s[y].size();
    for(int i = 0; i < szx; i++){
      for(int j = 0; j < szy; j++){
        int u = s[x][i].first, v = s[y][j].first;
        res = min(res, dis[u][v] + s[x][i].second + s[y][j].second);
      }
    }
    cout << res + w[x] + w[y] << '\n';
  }
  return 0;
}
