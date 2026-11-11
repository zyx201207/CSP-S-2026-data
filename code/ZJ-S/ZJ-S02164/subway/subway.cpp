#include<bits/stdc++.h>
using namespace std;
const int M=5e5+7,N=507;
int C,n,m,d,q,W[M],k[M],
	dist[M],
	edgecnt;
vector<int> a[N],t[N];
vector< pair<int,int> > e[M];
void add(int x,int y,int w)
{
	e[x].push_back({y,w});
	e[y].push_back({x,w});
	return;
}
void makeedge()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k[i];j++)
		{
			for(int l=j+1;l<=k[i];l++)
			{
				add(a[i][j],a[i][l],t[i][j]+t[i][l]);
				edgecnt++;
			}
		}
	}
	return;
}
int dijkstra(int s,int due)
{
	priority_queue< pair<int,int> > q;
	memset(dist,0x7f,sizeof dist);
	dist[s]=0;
	q.push({-dist[s],s});
	bitset<M> vis;
	vis.reset();
	while(!q.empty())
	{
		int x=q.top().second;
		q.pop();
		if(vis[x])
			continue;
		vis[x]=true;
		if(dist[x]>dist[due]||x==due)
			continue;
		for(auto it:e[x])
		{
			int to=it.first,val=it.second;
			if(dist[to]>dist[x]+val)
			{
				dist[to]=dist[x]+val;
				q.push({-dist[to],to});
			}
		}
	}
	return dist[due];
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&C,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&W[i]);
	}
	for(int i=1;i<=n;i++)
	{
		a[i].push_back(-1);
		t[i].push_back(-1);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++)
		{
			int aa,tt;
			scanf("%d%d",&aa,&tt);
			a[i].push_back(aa);
			t[i].push_back(tt);
		}
	}
	makeedge();
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",dijkstra(x,y)+W[x]+W[y]);
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/ 