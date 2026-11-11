#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505,M=500005;
const ll INF=1e18+10;
int c,n,m,d,q,x,y,w[M],k[N];
ll dis[N][N];
vector<int> a[N],t[N];
vector<pair<int,int> > g[M],e[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i]*2;j++)
		{
			if(j%2==1)
			{
				scanf("%d",&x);
				a[i].push_back(x);
			}
			else
			{
				scanf("%d",&x);
				t[i].push_back(x);
				g[a[i][j/2-1]].push_back({i,t[i][j/2-1]});
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dis[i][j]=INF;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<g[i].size();j++)
		{
			for(int p=j+1;p<g[i].size();p++)
			{
				int line1=g[i][j].first,line2=g[i][p].first;
				ll t1=g[i][j].second,t2=g[i][p].second;
				dis[line1][line2]=dis[line2][line1]=min(dis[line1][line2],t1+t2);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		dis[i][i]=0;
	}
	for(int p=1;p<=n;p++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][p]+dis[p][j]);
			}
		}
	}
	while(q--)
	{
		ll ans=INF;
		scanf("%d%d",&x,&y);
		for(int i=0;i<g[x].size();i++)
		{
			for(int j=0;j<g[y].size();j++)
			{
				int line1=g[x][i].first,line2=g[y][j].first;
				int t1=g[x][i].second,t2=g[y][j].second;
				ans=min(ans,dis[line1][line2]+t1+t2);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
