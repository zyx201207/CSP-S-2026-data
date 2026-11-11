#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
int c,T,n,d,a[2000005],dis[2005][2005],vis[2005][2005],cnt[2005][2005];
vector<int> g[2005];
void dij(int s)
{
	priority_queue<pii,vector<pii>,greater<pii> > q;
	memset(dis[s],0x3f3f3f3f,sizeof(dis[s]));
	dis[s][s]=0;
	cnt[s][s]=1;
	q.push({0,s});
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vis[s][u]) continue;
		vis[s][u]=1;
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i];
			if(dis[s][v]>dis[s][u]+1)
			{
				dis[s][v]=dis[s][u]+1;
				cnt[s][v]+=cnt[s][u];
				q.push({dis[s][v],v});
			}else if(dis[s][v]==dis[s][u]+1) cnt[s][v]+=cnt[s][u];
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		memset(dis,0,sizeof(dis));
		memset(vis,0,sizeof(vis));
		memset(cnt,0,sizeof(cnt));
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i],g[i].clear();
		sort(a+1,a+n+1);
		if(c<=10)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(a[j]-a[i]<=d) g[i].push_back(j);
				}
			}
			for(int i=1;i<=n;i++) dij(i);
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++) ans+=(cnt[i][j]==2);
			}
			cout<<ans<<'\n';
			continue;
		}
	}
	return 0;
}
/*
exp:40pts
writer:1419936
*/