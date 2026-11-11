#include <bits/stdc++.h>
#define P pair<long long,int>
using namespace std;
const int INF=2e9+12,M=5e5+12;
int c,n,m,d,q;
int ci[M],a[M],b[M];
int used[M];
long long dis[M];
struct edge{
	int to;
	long long cost;
};
vector<edge> G[M];
vector<long long> dist[M];
priority_queue<P,vector<P>,greater<P> > qu;
int read()
{
	char k=getchar();
	int f=1;
	int s=0;
	if(k=='-')
	{
		f=-1;
		k=getchar();
	}
	while(k>='0'&&k<='9')
	{
		s*=10;
		s+=k-'0';
		k=getchar();
	}
	return s*f;
}
void dijkstra(int st)
{
	for(int i=1;i<=m;i++)
	{
		dis[i]=INF;
	}
	dis[st]=0;
	qu.push(P{0,st});
	while(!qu.empty())
	{
		P p=qu.top();
		qu.pop();
		if(dis[p.second]<p.first) continue;
		for(int i=0;i<G[p.second].size();i++)
		{
			edge e=G[p.second][i];
			if(dis[e.to ]>dis[p.second]+e.cost )
			{
				dis[e.to ]=dis[p.second]+e.cost;
				qu.push(P{dis[e.to ],e.to });
			}
		}
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for(int i=1;i<=m;i++)
	{
		ci[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		k=read();
		for(int j=1;j<=k;j++)
		{
			a[j]=read();
			b[j]=read();
		}
		for(int j=1;j<=k;j++)
		{
			for(int l=j+1;l<=k;l++)
			{
				G[a[j]].push_back(edge{a[l],b[j]+b[l]});
				G[a[l]].push_back(edge{a[j],b[j]+b[l]});
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int start,fin;
		start=read();
		fin=read();
		if(used[start]==1)
		{
			cout<<(dis[fin]+ci[start]+ci[fin])<<endl;
			continue;
		}
		dijkstra(start);
		for(int i=1;i<=m;i++)
		{
			dist[start].push_back(dis[i]);
		}
		used[start]=1;
		cout<<(dis[fin]+ci[start]+ci[fin])<<endl;
	} 
	return 0;
}
