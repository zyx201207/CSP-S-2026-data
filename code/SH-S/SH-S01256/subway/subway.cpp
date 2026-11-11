#include<bits/stdc++.h>
using namespace std;
int w[500005],a[505][500005],t[505][500005],dis[500005],vis[500005],m;
int nxt[1000005],head[500005],to[1000005],is[500005],tot;
typedef struct node
{
	int u,d;
	bool operator < (const struct node & t)const
	{
		return d>t.d;
	}
}NODE,*PNODE;
priority_queue<NODE> pq;
void dijkstra(int u)
{
	int i,v;
	for(i=1;i<=m;++i)
		dis[i]=0x3f3f3f3f,vis[i]=0;
	dis[u]=0;
	pq.push(NODE{u,0});
	NODE T;
	while(!pq.empty())
	{
		T=pq.top();
		pq.pop();
		if(vis[T.u])
			continue;
		vis[T.u]=1,dis[T.u]=T.d;
		for(i=head[T.u];i;i=nxt[i])
		{
			v=to[i];
			if(vis[v])
				continue;
			pq.push(NODE{v,T.d+t[1][v]});
			if(is[v]==2)
				pq.push(NODE{v,T.d+t[1][v]+t[2][v]});
		}
	}
}
void add_edge(int u,int v)
{
	nxt[++tot]=head[u];
	to[tot]=v;
	head[u]=tot;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,d,q,i,j,k,x,y;
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(i=1;i<=m;++i)
		scanf("%d",&w[i]);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&k);
		for(j=i;j<=k;++j)
			scanf("%d %d",&a[i][j],&t[i][j]);
		is[a[i][j]]++;
		add_edge(a[i][j],a[i][j-1]);
		add_edge(a[i][j-1],a[i][j]);
	}
	for(i=1;i<=q;++i)
	{
		scanf("%d %d",&x,&y);
		dijkstra(x);			
		printf("%d\n",dis[y]+w[x]+w[y]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
