#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,int> PII;
const int N=510,M=5e5+10;
const LL inf=1e18;
int c,n,m,d,Q;
vector<PII>e[N+M];
vector<LL>dis[N];
int w[M];
bool st[N+M];
priority_queue<PII,vector<PII>,greater<PII>>q;
inline int read()
{
	int res=0;char c;
	do c=getchar();while(c<'0' || c>'9');
	do res=res*10+(c^48),c=getchar();while(c>='0' && c<='9');
	return res;
}
inline void dijkstra(int s)
{
	fill(st,st+n+m+1,0);
	dis[s][s]=0;
	q.push({0,s});
	while(q.size())
	{
		int u=q.top().second;q.pop();
		if(st[u])continue;
		st[u]=1;
		for(PII t:e[u])
		{
			int v=t.first;LL D=t.second;
			if(dis[s][v]>dis[s][u]+D)
			{
				dis[s][v]=dis[s][u]+D;
				q.push({dis[s][v],v});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),Q=read();
	for(int i=1;i<=n;++i)
	{
		dis[i].reserve(m+N+10);
		for(int j=1;j<=m+n;++j)
			dis[i][j]=inf;
	}
	for(int i=1;i<=m;++i)w[i]=read();
	for(int i=1;i<=n;++i)
	{
		int k=read();
		for(int j=1;j<=k;++j)
		{
			int a=read(),t=read();
			e[i].push_back({a+n,t});
			e[a+n].push_back({i,t});
		}
	}
	for(int i=1;i<=n;++i)
		dijkstra(i);
	while(Q--)
	{
		int x=read(),y=read();
		LL ans=inf;
		for(int i=1;i<=n;++i)
			ans=min(ans,dis[i][x+n]+dis[i][y+n]);
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
