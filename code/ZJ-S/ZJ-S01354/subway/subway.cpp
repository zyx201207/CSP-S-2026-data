#include<bits/stdc++.h>
using namespace std;
int cc,n,m,d,q,w[500010],k[510];
//vector <int> a[510],t[510];
vector <int> v[500010],aa[500010];
long long b[510][510],f[510][510];
//建模时以地铁线为点
int main()
{freopen("subway.in","r",stdin);
 freopen("subway.out","w",stdout);
 ios::sync_with_stdio(0);cin.tie(0);
 cin>>cc>>n>>m>>d>>q;
 for(int i=1;i<=m;i++) cin>>w[i];
 for(int i=1;i<=n;i++)
 {cin>>k[i];
  //for(int j=0;j<=k[i];j++) a[i].emplace_back(0),t[i].emplace_back(0);
  for(int j=1;j<=k[i];j++)
  {int a,t;cin>>a>>t;
   v[a].emplace_back(i);
   aa[a].emplace_back(t);
  }
 }
 for(int i=1;i<=n;i++)
 {for(int j=1;j<=n;j++)
  b[i][j]=f[i][j]=1e18;
 }
 for(int i=1;i<=m;i++)
 {for(int j=0;j<v[i].size();j++)
  {for(int jj=0;jj<v[i].size();jj++)
   b[v[i][j]][v[i][jj]]=min(b[v[i][j]][v[i][jj]],(long long)aa[i][j]+aa[i][jj]);
  }
 }
 for(int i=1;i<=n;i++)
 {for(int j=1;j<=n;j++)
  f[i][j]=b[i][j];
  f[i][i]=0;
 }
 //folyd
 for(int k=1;k<=n;k++)
 {for(int i=1;i<=n;i++)
  {for(int j=1;j<=n;j++)
   f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
  }
 }
 while(q--)
 {int x,y;cin>>x>>y;
  long long s=w[x]+w[y],ans=1e18;
  for(int i=0;i<v[x].size();i++)
  {for(int j=0;j<v[y].size();j++)
   ans=min(ans,aa[x][i]+aa[y][j]+f[v[x][i]][v[y][j]]);
  }
  cout<<s+ans<<'\n';
 }
}
