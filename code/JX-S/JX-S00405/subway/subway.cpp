/*
uid=305928 last fight

azayagana risouhatasutsurukiyo
konoyonoyume subetenosete
ima ima saa kirisaite
tashikana kotowariminna urayamu
mitasarenu sekainoitadakide!

For lovely Tenshi Hinanawi
 */


/*
Tenshi's spirit encourages me.
*/

#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[1000005];
vector<pair<int,int> >e[1000005];
int dis[505][505];
signed main(){
  freopen("subway.in","r",stdin);
  freopen("subway.out","w",stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>c>>n>>m>>d>>q;
  for (int i=1;i<=m;i++)cin>>w[i];
  for (int i=1;i<=n;i++){
    int k;cin>>k;
    for (int j=1;j<=k;j++){
      int a,t;cin>>a>>t;
      e[a].push_back({i,t});
    }
  }
  memset(dis,0x3f,sizeof(dis));
  for (int i=1;i<=n;i++)dis[i][i]=0;
  for (int i=1;i<=m;i++){
    for (pair<int,int> x:e[i]){
      for (pair<int,int> y:e[i]){
	dis[x.first][y.first]=min(dis[x.first][y.first],x.second+y.second);
      }
    }
  }
  for (int z=1;z<=n;z++){
    for (int x=1;x<=n;x++){
      for (int y=1;y<=n;y++){
	dis[x][y]=min(dis[x][y],dis[x][z]+dis[z][y]);
      }
    }
  }
  while (q--){
    int u,v;cin>>u>>v;
    int ans=1e18;
    for (pair<int,int> x:e[u]){
      for (pair<int,int> y:e[v]){
	ans=min(ans,dis[x.first][y.first]+x.second+y.second+w[u]+w[v]);
      }
    }
    cout<<ans<<"\n";
  }
  return 0;
}
