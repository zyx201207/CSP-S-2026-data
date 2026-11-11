#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d1,q,w[500005],ans;
int d[505][505],k[500005];
int a[500005],t[500005];
vector<pair<int,int> >ve[500005];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int i,j,l,u,v;
	cin>>c>>n>>m>>d1>>q;
	for(i=1;i<=m;i++)cin>>w[i];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)d[i][j]=1e18;
		d[i][i]=0;
	}
	for(i=1;i<=n;i++)
	{
		cin>>k[i];
		for(j=1;j<=k[i];j++)
		{
			cin>>a[j]>>t[j];
			ve[a[j]].push_back({i,t[j]});
		}
	}
	for(i=1;i<=m;i++)
	{
		for(j=0;j<ve[i].size();j++)
		{
			for(l=j+1;l<ve[i].size();l++)
			{
				d[ve[i][j].first][ve[i][l].first]=min(d[ve[i][j].first][ve[i][l].first],ve[i][j].second+ve[i][l].second);
				d[ve[i][l].first][ve[i][j].first]=min(d[ve[i][l].first][ve[i][j].first],ve[i][j].second+ve[i][l].second);
			}
		}
	}
	for(l=1;l<=n;l++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				d[i][j]=min(d[i][j],d[i][l]+d[l][j]);
			}
		}
	}
	while(q--)
	{
		cin>>u>>v;
		ans=1e18;
		for(i=0;i<ve[u].size();i++)
		{
			for(j=0;j<ve[v].size();j++)
			{
				ans=min(ans,d[ve[u][i].first][ve[v][j].first]+w[u]+w[v]+ve[u][i].second+ve[v][j].second);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}