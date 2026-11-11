#include<bits/stdc++.h>
using namespace std;

int _c,n,m,d,q;
int T=-1;
int _u,_v,_t,_a,k;

long long w[500001];
bool vis[500501];
vector<vector<long long> >dis;

int pos=0,head[510001];

struct edge
{
	int u,v;
	long long w;
	int nxt;
}e[1000001];

inline void addedge(int u,int v,long long w)
{
	e[++pos]={u,v,w,head[u]};
	head[u]=pos;
}

struct node
{
	int u;
	long long dis;
	bool operator<(const node &_cmp)const
	{
		return dis>_cmp.dis;
	}
};

inline void dijkstra(int s)
{
	priority_queue<node>q;
	q.push({s+m,0});
	dis[s][s+m]=0;
	while(!q.empty())
	{
		int u=q.top().u;
		q.pop();
		if(vis[u])
		{
			continue;
		}
		vis[u]=1;
		for(int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].v;
			long long w=e[i].w;
			if(dis[s][u]+w<dis[s][v])
			{
				dis[s][v]=dis[s][u]+w;
				q.push({v,dis[s][v]});
			}
		}
	}
	for(int i=1;i<=n+m;i++)
	{
		vis[i]=0;
	}
}
inline void bfs(int s)
{
	queue<node>q;
	q.push({s+m,0});
	dis[s][s+m]=0;
	while(!q.empty())
	{
		int u=q.front().u;
		q.pop();
		if(vis[u])
		{
			continue;
		}
		vis[u]=1;
		for(int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].v;
			long long w=e[i].w;
			if(dis[s][u]+w<dis[s][v])
			{
				dis[s][v]=dis[s][u]+w;
				q.push({v,dis[s][v]});
			}
		}
	}
	for(int i=1;i<=n+m;i++)
	{
		vis[i]=0;
	}
}

inline void p1()
{
	for(int i=1;i<=n;i++)
	{
		dijkstra(i);
	}
	for(int _=1;_<=q;_++)
	{
		scanf("%d%d",&_u,&_v);
		long long ans=LONG_MAX;
		for(int i=1;i<=n;i++)
		{
			ans=min(ans,dis[i][_u]+dis[i][_v]);
		}
		printf("%lld\n",ans+w[_u]+w[_v]);
	}
}

inline void p2()
{
	for(int i=1;i<=n;i++)
	{
		bfs(i);
	}
	for(int _=1;_<=q;_++)
	{
		scanf("%d%d",&_u,&_v);
		long long ans=LONG_MAX;
		for(int i=1;i<=n;i++)
		{
			ans=min(ans,dis[i][_u]+dis[i][_v]);
		}
		printf("%lld\n",ans*T+w[_u]+w[_v]);
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&_c,&n,&m,&d,&q);
	bool spB=1;
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			scanf("%d%d",&_a,&_t);
			addedge(i+m,_a,_t);
			addedge(_a,i+m,_t);
			if(T==-1)
			{
				T=_t;
			}
			else if(_t!=T)
			{
				spB=0;
			}
		}
	}
	dis.resize(n+1);
	for(int i=1;i<=n;i++)
	{
		dis[i].resize(n+m+1);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n+m;j++)
		{
			dis[i][j]=0x7f7f7f7f7f7f7f7f;
		}
	}
	if(spB)
	{
		p2();
		return 0;
	}
	else
	{
		p1();
		return 0;
	}
	return 0;
}
