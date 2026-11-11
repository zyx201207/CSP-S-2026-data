#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=512,M=5e5+5;
vector<pair<int,int>>bel[M];
int w[M],dis[N][N];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;cin>>k;
		for(int j=1;j<=k;j++)
		{
			int v,w;cin>>v>>w;
			bel[v].push_back({i,w});
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=(i==j?0:1e18);
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<bel[i].size();j++)
		{
			pair<int,int>it1=bel[i][j];
			for(int k=0;k<j;k++)
			{
				pair<int,int>it2=bel[i][k];
				int w=it1.second+it2.second;
				dis[it1.first][it2.first]=dis[it2.first][it1.first]=min(dis[it1.first][it2.first],w);
			}
		}
	}
	for(register int k=1;k<=n;k++)
		for(register int i=1;i<=n;i++)
			for(register int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--)
	{
		int x,y,ans=1e18;cin>>x>>y;
		for(auto it:bel[x])
			for(auto it2:bel[y])
				ans=min(ans,dis[it.first][it2.first]+it.second+it2.second);
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
//-std=c++14-static