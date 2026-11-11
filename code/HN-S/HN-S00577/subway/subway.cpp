#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=505,M=5e5+5;
const ll inf=1e18;
int c,n,m,D,q,w[M];
ll d[N][N];
struct node{
  int id,t;
};
node ve[M][25];
int tot[M];
void floyed(){
  for(int i=1;i<=m;i++){
    for(int j=1;j<=tot[i];j++){
      auto [x,xt]=ve[i][j];
      for(int k=1;k<=tot[i];k++){
        auto [y,yt]=ve[i][k];
        d[x][y]=min(d[x][y],(ll)xt+yt);
      }
    }
  }
  for(int k=1;k<=n;k++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    }  
  }
  return ;
}
int main(){
  freopen("subway.in","r",stdin);
  freopen("subway.out","w",stdout);
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  cin>>c>>n>>m>>D>>q;
  for(int i=1;i<=m;i++) cin>>w[i];
  for(int i=1;i<=n;i++){
    int k;cin>>k;
    while(k--){
      int x,t;cin>>x>>t;
      ve[x][++tot[x]]={i,t};
    }
    for(int j=1;j<=n;j++) d[i][j]=inf;
    d[i][i]=0ll;
  }
  floyed();
  while(q--){
    int s,t;ll ans=inf;
    cin>>s>>t;
    for(int j=1;j<=tot[s];j++){
      auto [x,xt]=ve[s][j];
      for(int k=1;k<=tot[t];k++){
        auto [y,yt]=ve[t][k];
        ans=min(ans,d[x][y]+xt+yt);
      }
    }
    cout<<ans+w[s]+w[t]<<'\n';
  }
  return 0;
}
//感觉有被卡的风险