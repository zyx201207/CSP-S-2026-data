#include<bits/stdc++.h>
#define int long long
#define sn 1000005
#define vivian 0x7fffffffffffff
#define pi pair<int,int>
using namespace std;
int n,c,m,d,q,w[sn],k[sn],in[5],dis[505][505],ans;
vector<pi> vc[sn];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>in[2];
		for(int j=1;j<=in[2];j++)
		{
			cin>>in[0]>>in[1];
			vc[in[0]].push_back((pi){i,in[1]});
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j)
			{
				dis[i][j]=vivian;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<vc[i].size();j++)
		{
			for(int k=j+1;k<vc[i].size();k++)
			{
				dis[vc[i][j].first][vc[i][k].first]=min(dis[vc[i][j].first][vc[i][k].first],vc[i][j].second+vc[i][k].second);
				dis[vc[i][k].first][vc[i][j].first]=dis[vc[i][j].first][vc[i][k].first];
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
	for(int i=1;i<=q;i++)
	{
		cin>>in[0]>>in[1],ans=vivian;
		for(int j=0;j<vc[in[0]].size();j++)
		{
			for(int k=0;k<vc[in[1]].size();k++)
			{
				int l=vc[in[0]][j].first;
				int r=vc[in[1]][k].first;
				ans=min(ans,dis[l][r]+vc[in[0]][j].second+vc[in[1]][k].second);
			}
		}
		cout<<ans+w[in[0]]+w[in[1]]<<'\n';
	}
	return 0;
}
