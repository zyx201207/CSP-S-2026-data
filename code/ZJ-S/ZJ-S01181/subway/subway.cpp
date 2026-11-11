#include<bits/stdc++.h>
#define pii pair<int,int>
#define int long long
using namespace std;
int c,n,m,d,q,t[500005],k[505],f[505][505];
vector<pii>zt[500005];//1st bianhao 2nd time
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	// in + out
	for(int i=1;i<=m;i++)cin>>t[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int x,y;
			cin>>x>>y;
			zt[x].push_back({i,y});
		}
	}
//	for(int i=0;i<zt[2].size();i++)
//	  cout<<zt[2][i].first<<' '<<zt[2][i].second<<' ';
//	cout<<"________";
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++)
	  f[i][i]=0;
	for(int x=1;x<=m;x++)
	{
		for(int i=0;i<zt[x].size();i++)
		  for(int j=i+1;j<zt[x].size();j++)
		  {
		  	int u=zt[x][i].first,v=zt[x][j].first,w=zt[x][i].second+zt[x][j].second;
		  	f[u][v]=f[v][u]=min(f[u][v],w);
		  }
	}
	for(int k=1;k<=n;k++)
	  for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
	      if(i!=j&&i!=k&&j!=k)
	        f[i][j]=min(f[i][j],f[i][k]+f[j][k]);
//	for(int i=1;i<=n;i++)
//	  for(int j=i+1;j<=n;j++)
//	    cout<<f[i][j];
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		//from which to which
		int ans=1e17;
		for(int i=0;i<zt[x].size();i++)
		  for(int j=0;j<zt[y].size();j++)
		  {
		  	int u=zt[x][i].first,v=zt[y][j].first;
//		  	cout<<u<<' '<<v<<' '<<t[x]<<' '<<zt[x][i].second<<' '<<f[u][v]<<' '<<zt[y][j].second<<' '<<t[y]<<endl;
		  	ans=min(ans,t[x]+zt[x][i].second+f[u][v]+zt[y][j].second+t[y]);//down + in + take + in + down
		  }
		cout<<ans<<'\n';
	}
	return 0;
}
