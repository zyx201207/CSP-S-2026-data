#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool aa;
const ll kM = 1e6 + 5, kN = 505;
ll c, n, m, d, q, w[kM], f[kN][kN];
vector<ll> id[kM], tt[kM];
bool bb;
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  cin >> c >> n >> m >> d >> q;
  for(int i = 1; i <= m; i++){
    cin >> w[i];
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      f[i][j] = 1e18;
    }
    f[i][i] = 0;
  }
  for(int i = 1, k, a, t; i <= n; i++){
    cin >> k;
    for(int j = 1; j <= k; j++){
      cin >> a >> t;
      for(int p = 0; p < id[a].size(); p++){
        ll u = id[a][p];
        f[u][i] = min(f[u][i], t + tt[a][p]);
        f[i][u] = min(f[i][u], t + tt[a][p]);
      }
      id[a].push_back(i);
      tt[a].push_back(t);
    }
  }
  for(int k = 1; k <= n; k++){
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n;j++){
        f[i][j] = min(f[i][k] + f[k][j], f[i][j]);
      }
    }
  }
  while(q--){
    ll x, y;
    cin >> x >> y;
    ll mi = 1e18;
    for(int p = 0; p < id[x].size(); p++){
      ll u = id[x][p];
      for(int q = 0; q < id[y].size(); q++){
        ll v = id[y][q];
        mi = min(mi, f[u][v] + tt[x][p] + tt[y][q]);
      }
    }
    cout << w[x] + w[y] + mi << "\n";
  }
  return 0;
}