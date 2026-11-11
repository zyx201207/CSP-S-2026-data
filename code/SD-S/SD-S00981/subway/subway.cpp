#include<bits/stdc++.h>
using namespace std;
using llt=long long;
#define pr pair<int,llt>
#define ft first
#define sd second
const int maxn=505,maxm=5e5+5;
int c,n,m,d,q;
llt w[maxm],dis[maxn][maxn];
vector<pr> g[maxm];
int main()
{
//	system("fc subway7.ans subway.out");
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int u;
			llt www;
			cin>>u>>www;
			g[u].push_back({i,www});
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<g[i].size();j++)
		{
			pr u=g[i][j];
			for(int k=j+1;k<g[i].size();k++)
			{
				pr v=g[i][k];
				dis[u.ft][v.ft]=dis[v.ft][u.ft]=min(dis[u.ft][v.ft],u.sd+v.sd);
			}
		}
	}////////////////////////////////
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
		int x,y;
		cin>>x>>y;
		llt ans=dis[0][0];
		for(auto u:g[x])
		{
			for(auto v:g[y])
			{
				ans=min(ans,w[x]+u.sd+dis[u.ft][v.ft]+v.sd+w[y]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
