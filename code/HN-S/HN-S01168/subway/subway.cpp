#include<bits/stdc++.h>

using namespace std;

const int N = 5e2 + 5;
const int M = 5e5 + 5;
const long long INF = 1e18;

int c, n, m, d, q;
long long dp[N][N], w[M], len[N];
vector<pair<int, int>> g[M];
vector<long long> a[N], t[N];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  cin >> c >> n >> m >> d >> q;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      dp[i][j] = (i == j ? 0 : INF);
    }
  }
  for(int i = 1; i <= m; i++){
    cin >> w[i];
  }
  for(int i = 1; i <= n; i++){
    cin >> len[i];
    a[i].push_back(0);
    t[i].push_back(0);
    for(int j = 1, u, v; j <= len[i]; j++){
      cin >> u >> v;
      a[i].push_back(u);
      t[i].push_back(v);
      g[u].push_back({i, j});
    }
  }
  for(int i = 1; i <= m; i++){
    for(int j = 0; j < g[i].size(); j++){
      for(int k = 0; k < g[i].size(); k++){
        dp[g[i][j].first][g[i][k].first] = min(dp[g[i][j].first][g[i][k].first], t[g[i][j].first][g[i][j].second] + t[g[i][k].first][g[i][k].second]);
      }
    }
  }
  /*for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      cout << dp[i][j] << '\n';
    }
  }*/
  for(int k = 1; k <= n; k++){
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }
  while(q--){
    int x, y;
    cin >> x >> y;
    long long ans = INF;
    for(int i = 0; i < g[x].size(); i++){
      for(int j = 0; j < g[y].size(); j++){
        ans = min(ans, dp[g[x][i].first][g[y][j].first] + w[x] + w[y] + t[g[x][i].first][g[x][i].second] + t[g[y][j].first][g[y][j].second]);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
