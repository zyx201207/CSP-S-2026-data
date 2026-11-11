//SN-S00412 YangRuibin TYZ
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=505,M=5e5+5;
int c,n,m,d,q;
int w[M];
vector<int>a[N],t[N];
vector<pair<int,int> >g[M];
ll dis[N][N];
void work(int st,int ed)
{
	ll ans=2e18;
	for(auto &pi:g[st])
		for(auto &pj:g[ed])
		{
			if(dis[pi.first][pj.first]>ans)continue;
			ans=min(ans,pi.second+dis[pi.first][pj.first]+pj.second+w[st]+w[ed]);
		}
	printf("%lld\n",ans);
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",w+i);
	for(int i=1,k;i<=n;i++)
	{
		scanf("%d",&k);
		for(int j=1,x,tt;j<=k;j++)
		{
			scanf("%d%d",&x,&tt);
			a[i].push_back(x);
			t[i].push_back(tt);
			g[x].push_back({i,tt});
		}	
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int p=1;p<=m;p++)
	{
		for(int i=0;i<(int)g[p].size();i++)
			for(int j=i+1;j<(int)g[p].size();j++)
			{
				int x=g[p][i].first,y=g[p][j].first;
				ll dd=g[p][i].second+g[p][j].second;
				dis[x][y]=min(dis[x][y],dd);
				dis[y][x]=min(dis[y][x],dd);
			}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=1,x,y;i<=q;i++)
		scanf("%d%d",&x,&y),work(x,y);
	return 0;
}

