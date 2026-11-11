#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=515,M=5e5+1000;
const ll inf=0x3f3f3f3f3f3f3f3fll;
int testcase,n,m,d,q;
ll weight[M],a[N][N];
vector<pair<int,ll> >g[M];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&testcase,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&weight[i]);
	}
	//cerr<<"Weight finished\n";
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			int stp;
			ll tt;
			scanf("%d%lld",&stp,&tt);
			g[stp].push_back(make_pair(i,tt));
		}
		/*
		if(i%10==0)
		{
			cerr<<"! "<<i<<"\n";
		}
		*/
	}
	//cerr<<"Read finished\n";
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=n;i++)
	{
		a[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<g[i].size();j++)
		{
			int u=g[i][j].first;
			ll tx=g[i][j].second;
			for(int k=j+1;k<g[i].size();k++)
			{
				int v=g[i][k].first;
				ll ty=g[i][k].second;
				ll nwt=min(a[u][v],tx+ty);
				a[u][v]=a[v][u]=nwt;
			}
		}
	}
	//cerr<<"Graph finished\n";
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i][k]>=inf)
			{
				continue;
			}
			for(int j=1;j<=n;j++)
			{
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x==y)
		{
			printf("0\n");
			continue;
		}
		ll as=inf;
		for(int i=0;i<g[x].size();i++)
		{
			for(int j=0;j<g[y].size();j++)
			{
				as=min(as,g[x][i].second+a[g[x][i].first][g[y][j].first]+g[y][j].second);
			}
		}
		as+=(weight[x]+weight[y]);
		printf("%lld\n",as);
	}
	return 0;
}
