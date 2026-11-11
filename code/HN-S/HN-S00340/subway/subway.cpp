#include<bits/stdc++.h>

using namespace std;

const int N = 510, M = 5e5 + 10;

struct node{
  int x;
  long long w;
};

int c, n, m, dd, q, w[M];
long long d[N][N];
vector<node> v[M], g[N];

signed main(){
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> c >> n >> m >> dd >> q;
  for(int i = 1; i <= m; i++) cin >> w[i];
  fill(&d[0][0], &d[n][n] + 1, 1e18);
  for(int i = 1; i <= n; i++) d[i][i] = 0;
  for(int i = 1, l; i <= n; i++){ cin >> l;
    for(int j = 1, x, t; j <= l; j++){
      cin >> x >> t, v[x].push_back({i, t});
      g[i].push_back({x, t});
    }
  }
  for(int i = 1; i <= n; i++){
    for(node j : g[i]){
      for(node l : v[j.x]){
        d[l.x][i] = min(d[l.x][i], j.w + l.w);
        d[i][l.x] = min(d[i][l.x], j.w + l.w);
      }
    }
  }
  for(int k = 1; k <= n; k++){
    for(int i = 1; i <= n; i++){
      if(d[i][k] == 1e18) continue;
      for(int j = 1; j <= n; j++){
        if(d[k][j] < 1e18)d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  for(int x, y; q--; ){
    cin >> x >> y; long long ans = 1e18;
    for(node i : v[x]){
      for(node j : v[y]){
        ans = min(ans, w[x] + w[y] + i.w + j.w + d[i.x][j.x]);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
