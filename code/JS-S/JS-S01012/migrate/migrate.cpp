// duipai
#include<bits/stdc++.h>
#define rep(i, a, b) for (int i=(a),i##_E_=(b);i<=i##_E_;++i)
#define drep(i, a, b) for (int i=(a),i##_E_=(b);i>=i##_E_;--i)
using namespace std;
using ll = long long;

void ofile(string s){
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}

int n,lto[2000010],rto[2000010];
ll d,a[2000010],f[2000010],g[2000010];
vector<int>UL[2000010],UR[2000010];

void solve(){
  cin>>n>>d;
  rep(i,1,n)cin>>a[i];
  rep(i,0,n+1){
    lto[i]=rto[i]=i;
    UL[i]=UR[i]={};
    f[i]=g[i]=0;
  }
  {
    int j=1;
    rep(i,1,n){
      while (a[i]-a[j]>d)++j;
      lto[i]=j;
    }
  }
  {
    int j=n;
    drep(i,n,1){
      while (a[j]-a[i]>d)--j;
      rto[i]=j;
    }
  }
  rep(i,1,n){
    if (lto[i]!=i)UL[lto[i]].push_back(i);
    if (rto[i]!=i)UR[rto[i]].push_back(i);
  }
  rep(i,1,n){
    int xj=n+1;
    for (auto j:UR[i])++f[i],xj=min(xj,j);
    if (f[i])f[i]+=f[xj]-1;
    ++f[i];
  }
  drep(i,n,1){
    int xj=0;
    for (auto j:UL[i])++g[i],xj=max(xj,j);
    if (g[i])g[i]+=g[xj]-1;
    ++g[i];
  }
  // cout<<g[4]<<'\n';
  ll ans=0;
  rep(i,1,n-1){
    ll sf=0,sg=0;
    int xj=n+1,yj=0;
    for (auto j:UR[i+1])if (j<i)++sf,xj=min(xj,j);
    for (auto j:UL[i])if (j>i+1)++sg,yj=max(yj,j);
    if (sf&&sg){
      if (rto[xj-1]!=i)sf+=f[xj]-1;
      if (lto[yj+1]!=i+1)sg+=g[yj]-1;
      ans+=sf*sg;
      // cout<<"?? "<<i<<' '<<sf-1+f[xj]<<' '<<sg-1+g[yj]<<' '<<ans<<'\n';
    }
  }
  cout<<ans<<'\n';
}

int main(){
  ofile("migrate");
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int c,tt;
  cin>>c>>tt;
  while (tt--)solve();
  return 0;
}