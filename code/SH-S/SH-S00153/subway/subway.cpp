#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
	int u,w;
	bool operator < (const struct node & t  ) const
	{
		return w>t.w;
	}
}NODE,*PNODE;
priority_queue<NODE> pq;
int nxt[2200001],to[2200001],head[1500005],weight[2200001],tot;
int arr[500005],t[500005],dist[1500005],sub[500005],pla[500005][21],tot1;
bool vis[500005];
void add_edge(int u,int v,int w)
{
	nxt[++tot]=head[u];
	to[tot]=v;
	weight[tot]=w;
	head[u]=tot;
}
void dijkstra(int st)
{
	pq.push((NODE){st,0});
	NODE tmp;
	int i,v;
	while(!pq.empty())
	{
		tmp=pq.top();
		pq.pop();
		if(vis[tmp.u])
			continue;
		vis[tmp.u]=true;
		dist[tmp.u]=tmp.w;
		for(i=head[tmp.u];i;i=nxt[i])
		{
			v=to[i];
			if(vis[v])
				continue;
			pq.push((NODE){v,tmp.w+weight[i]});
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,N,M,d,Q,p,i,j,k,st,ed;
	scanf("%d %d %d %d %d",&c,&N,&M,&d,&Q);
	tot1=M;
	for(i=1;i<=M;++i)
	{
		scanf("%d",&k);
		sub[i]=++tot1;
		add_edge(i,sub[i],k);
		add_edge(sub[i],i,k);
	}
	for(i=1;i<=N;++i)
	{
		scanf("%d",&p);
		for(j=1;j<=p;++j)
			scanf("%d %d",&arr[j],&t[j]);
		for(j=1;j<p;++j)
		{
			if(!pla[arr[j]][i])
				pla[arr[j]][i]=++tot1;
			if(!pla[arr[j+1]][i])
				pla[arr[j+1]][i]=++tot1;
			add_edge(pla[arr[j]][i],pla[arr[j+1]][i],0);
			add_edge(pla[arr[j+1]][i],pla[arr[j]][i],0);
			add_edge(pla[arr[j]][i],arr[j],t[j]);
			add_edge(arr[j],pla[arr[j]][i],t[j]);
		}
		add_edge(arr[p],pla[arr[p]][i],t[p]);
		add_edge(pla[arr[p]][i],arr[p],t[p]);
	}
	while(Q--)
	{
		for(i=1;i<=tot1;++i)
			vis[i]=false;
		scanf("%d %d",&st,&ed);
		dijkstra(sub[st]);
		printf("%d\n",dist[sub[ed]]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

56642*2000=113284000=1.13*10^8
*/
