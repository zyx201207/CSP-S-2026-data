#include <bits/stdc++.h>
using namespace std;

const int N1 = 3e2 + 5, N2 = 2e6 + 5;
const long long mod = 2e8;
const long long inf = 2e9;
using ll = long long;

ll c, t, a[N2], d, n;

struct node1{
  ll w, p;
}dis[N1][N1];

namespace sn1{
  void init(ll n){
    for(int i = 0; i <= n; i++){
      for(int j = 0; j <= n; j++){
        dis[i][j] = {inf, 0};
      }
    }
  }
  void solve(){
    init(n);
    for(int i = 1; i <= n; i++){
      for(int j = i + 1; j <= n; j++){
        if(a[j] - a[i] <= d){
          dis[i][j] = {1, 1};
        }
      }
    }
    for(int len = 2; len <= n - 1; len++){
      for(int i = 1; i + len <= n; i++){
        int j = i + len;
        for(int k = i + 1; k < j; k++){
          if(dis[i][k].w != inf && dis[k][j].w != inf && dis[i][j].w > dis[i][k].w + dis[k][j].w){
            dis[i][j].w = dis[i][k].w + dis[k][j].w;
            dis[i][j].p = min(dis[i][k].p * dis[k][j].p, mod);
          }else if(dis[i][k].w != inf && dis[k][j].w != inf && dis[i][j].w == dis[i][k].w + dis[k][j].w){
            dis[i][j].p = min(dis[i][j].p + dis[i][k].p * dis[k][j].p, mod);
          }
        }
        if(dis[i][j].p < mod && dis[i][j].w != inf && dis[i][j].w > 1){
          dis[i][j].p = dis[i][j].p / (dis[i][j].w - 1);
        }
      }
    }
    /*
    for(int i = 1; i <= n; i++){
      for(int j = i + 1; j <= n; j++){
        cout << dis[i][j].p << ' ';
      }
      cout << '\n';
    }
    cout << '\n';
    return;
    */
    ll ans = 0;
    for(int i = 1; i <= n; i++){
      for(int j = i + 1; j <= n; j++){
        if(dis[i][j].p == 2){
          ans++;
        }
      }
    }
    cout << ans << '\n';
  }
}

void solve(){
  cin >> n >> d;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  if(n <= N1){
    sn1::solve();
  }
}

int main(){
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> c >> t;
  while(t--){
    solve();
  }
  return 0;
}
