#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e2+10,M=5e5+10;
int c,n,m,d,qu,w[M],dist[N][N];
vector<pair<int,int>>e[M];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>qu;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dist[i][j]=1e18;
		}
		dist[i][i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int y,w;
			cin>>y>>w;
			e[y].push_back({i,w});
		}
	}
	for(int k=1;k<=m;k++)
	{
		if(e[k].size()!=1)
		{
			for(int i=0;i<e[k].size();i++)
			{
				for(int j=i+1;j<e[k].size();j++)
				{
					int x=e[k][i].first,y=e[k][j].first,wx=e[k][i].second,wy=e[k][j].second;
					if(x!=y)
					{
						dist[x][y]=min(dist[x][y],wx+wy);
						dist[y][x]=min(dist[y][x],wx+wy);
					}
				}
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	while(qu--)
	{
		int x,y,sum=1e18;
		cin>>x>>y;
		for(auto i:e[x])
		{
			for(auto j:e[y])
			{
				sum=min(sum,dist[i.first][j.first]+i.second+j.second);
			}
		}
		cout<<sum+w[x]+w[y]<<endl;
	}
	return 0;
}

