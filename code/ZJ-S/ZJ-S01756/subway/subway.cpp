#include<bits/stdc++.h>
using namespace std;
long long w[500010];
long long dis[510][510];
vector<pair<long long,long long>> v[500010];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		long long k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			long long x,w;
			cin>>x>>w;
			v[x].push_back({i,w});
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dis[i][j]=1e18;
			if(i==j)
			{
				dis[i][j]=0;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			for(int k=0;k<v[i].size();k++)
			{
				long long a=v[i][j].first,b=v[i][j].second;
				long long c=v[i][k].first,d=v[i][k].second;
				dis[a][c]=min(dis[a][c],b+d);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--)
	{
		long long x,y;
		cin>>x>>y;
		long long ans=1e18;
		for(int i=0;i<v[x].size();i++)
		{
			for(int j=0;j<v[y].size();j++)
			{
				ans=min(ans,dis[v[x][i].first][v[y][j].first]+v[x][i].second+v[y][j].second);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
