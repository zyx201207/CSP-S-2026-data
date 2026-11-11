#include<bits/stdc++.h>
#define rep(i, a, b) for (int i=(a),i##_E_=(b);i<=i##_E_;++i)
#define drep(i, a, b) for (int i=(a),i##_E_=(b);i>=i##_E_;--i)
using namespace std;
using ll = long long;

void ofile(string s){
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}

int n,m,d,q;
ll W[500010],dis[510][510];
vector<pair<int,ll>>A[500010];

int main(){
  ofile("subway");
  memset(dis,0x3f,sizeof(dis));
  scanf("%*d%d%d%d%d",&n,&m,&d,&q);
  rep(i,1,n)dis[i][i]=0;
  rep(i,1,m)scanf("%lld",&W[i]);
  rep(i,1,n){
    int c;
    scanf("%d",&c);
    while (c--){
      int o;
      ll x;
      scanf("%d%lld",&o,&x);
      A[o].push_back({i,x});
      // cout<<o<<' '<<i<<' '<<x<<'\n';
    }
  }
  rep(o,1,m)for (auto [i1,x1]:A[o])
    for (auto [i2,x2]:A[o]){
      // cout<<i1<<' '<<i2<<'\n';
      dis[i1][i2]=min(dis[i1][i2],x1+x2);
    }
  rep(k,1,n)rep(i,1,n)rep(j,1,n)
    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
  while (q--){
    int x,y;
    scanf("%d%d",&x,&y);
    ll ans=1e18;
    for (auto [i1,w1]:A[x])
      for (auto [i2,w2]:A[y])
        ans=min(ans,w1+w2+dis[i1][i2]+W[x]+W[y]);
    printf("%lld\n",ans);
  }
  return 0;
}