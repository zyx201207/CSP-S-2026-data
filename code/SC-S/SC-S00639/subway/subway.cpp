#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> a[505];//第i个地铁站经过的所有线路 
bool f[501][500005];
int w[500005],t[501][500005];//t:第i号线的j站从站台到站厅的时间 
int dis[501][501];//dis:第i号线路到第j号线路花费的最短时间 
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	int c,n,m,d,q;
	cin>>n>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)//i:当前输入的线路编号 
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x;
			cin>>x;
			cin>>t[i][x];//x:当前输入的地铁站号  
			if(f[i][x]==1) continue;
			f[i][x]=1;
			a[x].push_back(i);
			if(a[x].size()>=2) 
			{
				for(int l=0;l<a[x].size()-1;l++) 
				{
					int u=a[x][l];//u:经过当前地铁站的其他的线路编号 
					dis[i][u]=min(dis[i][u],t[u][x]+t[i][x]);
					dis[u][i]=dis[i][u];
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)
			{
				dis[i][j]=0;
				continue;
			}
			for(int l=1;l<=n;l++)
			{
				dis[i][j]=min(dis[i][j],dis[i][l]+dis[l][j]);
			}
		}
	}
	while(q--)
	{
		int x,y,ans=1e9,t1,t2;
		cin>>x>>y;
		for(int i=0;i<a[x].size();i++)
		{
			for(int j=0;j<a[y].size();j++)
			{
				int u=a[x][i],v=a[y][j];
				if(ans>dis[u][v]+t[u][x]+t[v][y])
				{
					ans=min(ans,dis[u][v]+t[u][x]+t[v][y]);
				}
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	 } 
	return 0;
}