#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,c,m,d,q;
int k;
vector<int> g[2];
int f[2][200007];
int w[200007];
int v[2][200007];
signed main() {
 freopen("subway.in","r",stdin);
 freopen("subway.out","w",stdout);
 memset(v,0x3f3f3f,sizeof(v[1]));
 memset(v,0x3f3f3f,sizeof(v[0]));
 cin>>c>>n>>m>>d>>q;
 for (int i=1;i<=m;i++){
  cin>>w[i];
 }
 int u;
 for (int i=0;i<n;i++){
  cin>>k;
  for (int j=1;j<=k;j++){
   cin>>u>>v[i][j];
   g[i].push_back(u);
   f[i][u]=1;
  }
  v[i][0]=k;
 }
 int mi=1e18;
 for (int i=1;i<=200007;i++){
  mi=min(mi,v[0][i]+v[1][i]);
 }int q1,q2;
 while (q--){
  cin>>q1>>q2;
  if (f[1][q1]==1&&f[1][q2]==1){
   cout<<w[q1]+w[q2]+v[1][q1]+v[1][q2]<<"\n";
  }
  else if (f[0][q1]==1&&f[0][q2]==1){
   cout<<w[q1]+w[q2]+v[0][q1]+v[0][q2]<<"\n";
  }
  else cout<<mi+w[q1]+w[q2]+min(v[0][q1],v[1][q1])+min(v[0][q2],v[1][q2])<<"\n";
 }
 return 0;
}
