#include <bits/stdc++.h>
using namespace std;

const int N = 5e2 + 5, M = 5e5 + 5, K = 5e5 + 5, D = 22;
const long long inf = 1e15;
using ll = long long;

ll c, n, m, d, q, r[M], p[M];
ll w[N][N];

struct node1{
  ll u, w;
};

vector <node1> a[N + M];

struct node2{
  ll id, w;
}t[M][D];

int main(){
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> c >> n >> m >> d >> q;
  for(int i = 1; i <= m; i++){
    cin >> r[i];
  }
  for(int i = 0; i <= n; i++){
    for(int j = 0; j <= n; j++){
      if(i != j){
        w[i][j] = inf;
      }else{
        w[i][j] = 0;
      }
    }
  }
  for(int i = 1; i <= n; i++){
    ll k;
    cin >> k;
    for(int j = 1; j <= k; j++){
      ll u, x;
      cin >> u >> x;
      p[u]++;
      t[u][p[u]] = {i, x};
      for(auto it : a[u]){
        w[i][it.u - M] = w[it.u - M][i] = min(w[i][it.u - M], it.w + x);
      }
      a[i + M].push_back({u, x});
      a[u].push_back({i + M, x});
    }
  }
  /*
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      cout << i << ' ' << j << ' ' << w[i][j] << '\n';
    }
  }
  */
  for(int k = 1; k <= n; k++){
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
      }
    }
  }
  while(q--){
    ll u, v;
    cin >> u >> v;
    ll ans = 0, cnt = inf;
    ans += r[u] + r[v];
    for(int i = 1; i <= p[u]; i++){
      for(int j = 1; j <= p[v]; j++){
        cnt = min(cnt, t[u][i].w + t[v][j].w + w[t[u][i].id][t[v][j].id]);
      }
    }
    ans += cnt;
    cout << ans << '\n';
  }
  return 0;
}
