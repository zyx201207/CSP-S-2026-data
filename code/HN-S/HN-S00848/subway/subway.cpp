#include<bits/stdc++.h>
using namespace std;
const int N = 505,M = 5e5 + 5;
int c,n,m,d,q,w[M];
using ll = long long;
ll dis[N][N];
vector<pair<int,int> > t[N],e[M];
signed main(){
  freopen("subway.in","r",stdin);
  freopen("subway.out","w",stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> c >> n >> m >> d >> q;
  for (int i = 1;i <= m;i++){
    cin >> w[i];
  }
  for (int i = 1,k;i <= n;i++){
    cin >> k;
    t[i].resize(k);
    for (auto &[x,v] : t[i]){
      cin >> x >> v;
      e[x].push_back({i,v});
    }
  }
  memset(dis,0x3f,sizeof(dis));
  for (int i = 1;i <= n;i++){
    dis[i][i] = 0;
  }
  for (int i = 1;i <= m;i++){
    for (auto &[x,vx] : e[i]){
      for (auto &[y,vy] : e[i]){
        dis[x][y] = min(dis[x][y],(ll)(vx + vy));
      }
    }
  }
  for (int k = 1;k <= n;k++){
    for (int i = 1;i <= n;i++){
      for (int j = 1;j <= n;j++){
        dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
      }
    }
  }
  for (int i = 1,x,y;i <= q;i++){
    cin >> x >> y;
    ll ans = 1e18;
    for (auto &[a,va] : e[x]){
      for (auto &[b,vb] : e[y]){
        ans = min(ans,dis[a][b] + va + vb + w[x] + w[y]);
      }
    }
    cout << ans << "\n";
  }
  cerr << clock() << "\n";
}