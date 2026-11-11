#include<bits/stdc++.h>
using namespace std;

int ans=0;
int _c,T,n;
long long d;
bool vis[2000001];
long long x[2000001];

int pos=0,head[2000001];

struct edge
{
	int u,v,nxt;
}e[4000001];

inline void addedge(int u,int v)
{
	e[++pos]={u,v,head[u]};
	head[u]=pos;
}

struct DIS
{
	int d;
	int cnt;
}dis[2000001];

inline void dijkstra(int s)
{
	queue<int>q;
	q.push(s);
	for(int i=1;i<=n;i++)
	{
		vis[i]=0;
		dis[i].d=0x3f3f3f3f;
		dis[i].cnt=0;
	}
	dis[s].d=0;
	dis[s].cnt=1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		if(vis[u])
		{
			continue;
		}
		vis[u]=1;
		for(int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].v;
			if(v<u)
			{
				continue;
			}
			if(dis[u].d+1<dis[v].d)
			{
				dis[v].d=dis[u].d+1;
				dis[v].cnt=dis[u].cnt;
				q.push(v);
			}
			else if(dis[u].d+1==dis[v].d)
			{
				dis[v].cnt+=dis[u].cnt;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		ans+=(dis[i].cnt==2);
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&_c,&T);
	for(int _=1;_<=T;_++)
	{
		pos=0;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&x[i]);
			head[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(x[j]-x[i]<=d)
				{
					addedge(i,j);
					//addedge(j,i);
				}
			}
		}
		ans=0;
		for(int i=1;i<=n;i++)
		{
			dijkstra(i);
		}
		printf("%d\n",ans);
	}
	return 0;
}
