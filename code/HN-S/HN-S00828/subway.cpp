#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int,int> >v[505];
int dis[505][505],ww[500005];
vector<pair<int,int> >v2[500005];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>ww[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dis[i][j]=1e18;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x,w;
			cin>>x>>w;
			v2[x].push_back({i,w});
			v[i].push_back({x,w});
		}
		sort(v[i].begin(),v[i].end());
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int xx=0,yy=0;
			while(xx<v[i].size()&&yy<v[j].size())
			{
				if(v[i][xx].first<v[j][yy].first) xx++;
				else if(v[i][xx].first>v[j][yy].first) yy++;
				else dis[i][j]=dis[j][i]=min(dis[i][j],v[i][xx].second+v[j][yy].second),xx++,yy++;
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(dis[i][k]!=1e18&&dis[k][j]!=1e18)
				{
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		for(auto i:v2[x])
		{
			for(auto j:v2[y])
			{
				ans=min(ans,dis[i.first][j.first]+i.second+j.second+ww[x]+ww[y]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
