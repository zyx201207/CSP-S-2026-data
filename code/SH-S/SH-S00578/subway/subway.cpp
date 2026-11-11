#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500010];
int k[500010];
int a[505][500005];
int t[505][500005];
vector<pair<int,int>> stat[500005];
int gph[505][505];
int dist[505][505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			stat[a[i][j]].push_back({i,t[i][j]});
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(stat[i].size()>1)
		{
			for(int k=1;i<=stat[i].size();k++)
			{
				for(int j=k+1;j<=stat[i].size();j++)
				{
					if(gph[k][j]!=0) gph[k][j]=min(gph[k][j],stat[i][k].second+stat[i][j].second);
					else gph[k][j]=stat[i][k].second+stat[i][j].second;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=i;k<=j;k++)
			{
				if(gph[i][j]!=0) gph[i][j]=min(gph[i][j],gph[i][k]+gph[k][j]);
				else gph[i][j]=gph[i][k]+gph[k][j];
			}
		}
	}
	for(int zz=1;zz<=q;zz++)
	{
		int x,y;
		cin>>x>>y;
		int ret=2147483646;
		for(int i=0;i<stat[x].size();i++)
		{
			for(int j=0;j<stat[y].size();j++)
			{
				ret=min(ret,stat[x][i].second+stat[y][j].second+gph[stat[x][i].first][stat[y][j].first])+w[x]+w[y];
			}
		}
		cout<<ret<<endl;
	}
	return 0;
} 
