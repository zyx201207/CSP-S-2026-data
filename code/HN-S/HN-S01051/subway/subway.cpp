#include<bits/stdc++.h>

using namespace std;

const int MAXN = 5e2 + 5, MAXM = 5e5 + 5;
const long long e = 1e13;

int k[MAXN];
long long w[MAXM], f[MAXN][MAXN];
vector<long long> t[MAXN], ut[MAXM];
vector<int> a[MAXN], h[MAXM];

int c, n, m, d, q;

void add_edge(int x, int y, long long v){
  f[x][y] = min(f[x][y], v);
  f[y][x] = min(f[y][x], v);
}

void work(){
  for(int i = 0; i <= n; i++) for(int j = 0; j <= n; j++) if(i != j) f[i][j] = e;
  for(int i = 1; i <= m; i++){
    for(int x = 0; x < h[i].size(); x++){
      for(int y = 0; y < x; y++){
        add_edge(h[i][x], h[i][y], ut[i][x] + ut[i][y]);
      }
    }
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      for(int mid = 1; mid <= n; mid++){
        f[i][j] = min(f[i][j], f[i][mid] + f[mid][j]);
      }
    }
  }
}

void solve(){
  int x, y;
  long long ans = e;
  cin >> x >> y;
  if(x == y){
    cout << 0 << '\n';
    return;
  }
  for(int i = 0; i < h[x].size(); i++){
    for(int j = 0; j < h[y].size(); j++){
      ans = min(ans, ut[x][i] + ut[y][j] + f[h[x][i]][h[y][j]]);
    }
  }
  cout << ans + w[x] + w[y] << '\n';
}

int main(){
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> c >> n >> m >> d >> q;
  for(int i = 1; i <= m; i++){
    cin >> w[i];
  }
  for(int i = 1; i <= n; i++){
    cin >> k[i];
    for(int j = 1, x, y; j <= k[i]; j++){
      cin >> x >> y;
      a[i].emplace_back(x), t[i].emplace_back(y);
      h[x].emplace_back(i), ut[x].emplace_back(y);
    }
  } 
  work();
  while(q--){
    solve();
  }
  return 0;
}
