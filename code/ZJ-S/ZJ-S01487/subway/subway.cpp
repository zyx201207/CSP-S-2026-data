#include<bits/stdc++.h>
#define AKIOI ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int N=5e5+10,INF=1e18,M=1e3+10;
int c,n,m,d,q,w[N],k,a[N],t[N],f[M][M],u,v;
signed main()
{
  AKIOI;
  freopen("subway.in","r",stdin);
  freopen("subway.out","w",stdout);
  cin>>c>>n>>m>>d>>q;
  for(int i=1;i<=m;i++) cin>>w[i];
  for(int i=1;i<=m;i++)
  {
    for(int j=1;j<=m;j++)
    {
      f[i][j]=INF;
	}
  }
  for(int i=1;i<=n;i++)
  {
  	cin>>k;
  	for(int j=1;j<=k;j++)
  	{
  	  cin>>a[j]>>t[j];
	}
	for(int j=1;j<k;j++)
	{
	  for(int l=j+1;l<=k;l++)
	  {
	  	f[a[j]][a[l]]=min(f[a[j]][a[l]],t[j]+t[l]);
	  	f[a[l]][a[j]]=f[a[j]][a[l]];
	  }
	}
  }
  for(int l=1;l<=m;l++)
  {
  	for(int i=1;i<m;i++)
  	{
  	  for(int j=i+1;j<=m;j++)
  	  {
  	  	f[i][j]=min(f[i][j],f[i][l]+f[l][j]);
  	  	f[j][i]=f[i][j];
	  }
	}
  }
  while(q--)
  {
  	cin>>u>>v;
  	cout<<f[u][v]+w[u]+w[v]<<endl;
  }
  return 0;
}
