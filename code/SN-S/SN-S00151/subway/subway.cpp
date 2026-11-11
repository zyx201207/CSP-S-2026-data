#include<bits/stdc++.h>
#define ll long long
#define pr pair<ll,ll>
#define fr first
#define se second
using namespace std;
const int N=500010,M=510;
ll subtask,n,m,mxd,q,ans,a[N],dis[M][M];
bool f[M];
vector<pr> E[M],G[N];
priority_queue<pr,vector<pr>,greater<pr>> que;
inline void dijsktra(int bg)
{
	for(int i=1;i<=n;i++)
	{
		dis[bg][i]=1e16;
		f[i]=false;
	}
	dis[bg][bg]=0;
	que.push({0ll,bg});
	while(!que.empty())
	{
		ll p=que.top().se;
		que.pop();
		if (f[p])
			continue;
		f[p]=true;
		int sz=E[p].size();
		for(int i=0;i<sz;i++)
		{
			ll k=E[p][i].fr,v=E[p][i].se;
			if (dis[bg][k]>dis[bg][p]+v)
			{
				dis[bg][k]=dis[bg][p]+v;
				if (!f[k])
					que.push({dis[bg][k],k});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>subtask>>n>>m>>mxd>>q;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int sz;
		cin>>sz;
		for(int j=1;j<=sz;j++)
		{
			ll u,v;
			cin>>u>>v;
			G[u].push_back({i,v});
		}
		for(int j=1;j<=n;j++)
			dis[i][j]=1e16;
	}
	for(int i=1;i<=m;i++)
	{
		int sz=G[i].size();
		for(int j=0;j<sz;j++)
			for(int k=0;k<sz;k++)
				if (j!=k)
				{
					ll u=G[i][j].fr,v=G[i][k].fr;
					dis[u][v]=min(dis[u][v],G[i][j].se+G[i][k].se);
					dis[v][u]=dis[u][v];
				}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if (i!=j&&dis[i][j]!=1e16)
				E[i].push_back({j,dis[i][j]});
	for(int i=1;i<=n;i++)
		dijsktra(i);
	for(int i=1;i<=q;i++)
	{
		int bg,ed;
		cin>>bg>>ed;
		ans=1e16;
		int szb=G[bg].size(),sze=G[ed].size();
		for(int j=0;j<szb;j++)
			for(int k=0;k<sze;k++)
			{
				ll u=G[bg][j].fr,v=G[ed][k].fr;
				ans=min(ans,dis[u][v]+G[bg][j].se+G[ed][k].se);
			}
		cout<<ans+a[bg]+a[ed]<<"\n";
	}
}
