#include<bits/stdc++.h>
using namespace std;
long long weight[500005][25],dist[1005][1005],chu[1005];
int id[500005][25],a[25][500005],cnt[500005],c,n,m,d,q;
typedef struct node
{
	int u,xian;
	long long w;
	bool operator < (const struct node &t)const
	{
		return w>t.w;
	}
}NODE,*PNODE;
priority_queue<NODE> pq;
int nxt[5005],to[5005],head[5005],visited[5005],tot;
void add_edge(int u,int v)
{
	nxt[++tot]=head[u];
	to[tot]=v;
	head[u]=tot;
}
void dij(int u,int xian)
{
	int i,v,k;
	NODE tmp;
	memset(visited,0,sizeof(visited));
	pq.push((NODE){u,xian,weight[xian][u]});
	while(!pq.empty())
	{
		tmp=pq.top();
//		printf("%d %d %lld\n",tmp.u,tmp.xian,tmp.w);
		pq.pop();
		if(visited[tmp.u])
			continue;
		visited[tmp.u]=1;
		if(dist[u][tmp.u])
			dist[u][tmp.u]=min(dist[u][tmp.u],tmp.w);
		else
			dist[u][tmp.u]=tmp.w;
		for(i=head[tmp.u];i;i=nxt[i])
		{
			v=to[i];
			if(visited[v])
				continue;
			if(abs(id[tmp.u][tmp.xian]-id[v][tmp.xian])==1)
				pq.push((NODE){v,tmp.xian,tmp.w});
			else
			{
				for(k=1;k<=n;++k)
				{
					if(id[v][k])
					{
//						printf("tmpu%d %d %d tmpxian%d %lld %lld\n",tmp.u,v,k,tmp.xian,weight[tmp.xian][tmp.u],weight[k][tmp.u]);
						pq.push((NODE){v,k,tmp.w+weight[tmp.xian][tmp.u]+weight[k][tmp.u]});
						break;
					}
				}
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	int i,j,k,aa,b;
	long long x;
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(i=1;i<=m;++i)
		scanf("%d",&chu[i]);
	for(i=1;i<=n;++i)
	{
		scanf("%d ",&k);
		for(j=1;j<=k;++j)
		{
			scanf("%d %lld",&a[i][j],&x);
			weight[i][a[i][j]]=x;
			id[a[i][j]][i]=j;//a[i][j]这个站在第i条线里排第j 
			if(j!=1)
			{
				add_edge(a[i][j],a[i][j-1]);
				add_edge(a[i][j-1],a[i][j]);
			}
		}
	}
//	printf("111\n");
	for(i=1;i<=m;++i)
	{
		for(j=1;j<=n;++j)
		{
			if(id[i][j])
			{
//				printf("u=%d xian=%d\n",i,j);
				dij(i,j);
			}
		}
	}
	for(k=1;k<=n;++k)
		for(i=1;i<=n;++i)
			for(j=i+1;j<=n;++j)
				dist[i][j]=dist[j][i]=min(dist[i][j],dist[i][k]+dist[k][j]);
	while(q--)
	{
		scanf("%d %d",&aa,&b);
		printf("%lld\n",chu[aa]+chu[b]+dist[aa][b]);
	}
	return 0;
}
