#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>


using namespace std;

const int N=6e5;
struct Edge
{
	int v,nx,w;
};
Edge e[N<<1];
int h[N];
int id;

void build(int u,int v,int w)
{
	id++;
	e[id].v=v;
	e[id].w=w;
	e[id].nx=h[u];
	h[u]=id;
	id++;
	e[id].v=u;
	e[id].w=w;
	e[id].nx=h[v];
	h[v]=id;
}

struct Point
{
	int id;
	long long dis;
/*	friend bool operator<(Point a,Point b)
	{
		return a.dis<b.dis;
	}*/

	friend bool operator>(Point a,Point b)
	{
		return a.dis>b.dis;
	}
};

priority_queue<Point,vector<Point>,greater<Point> >q;
bool vis[N];
long long dis[N];
long long dij(int s,int t)
{
	while(!q.empty())
		q.pop();
	memset(dis,0x7f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	Point tmp;
	tmp.id=s;
	tmp.dis=0;
	dis[s]=0;
	q.push(tmp);
	while(!q.empty())
	{
		tmp=q.top();
		int u=tmp.id;
		vis[u]=true;
		q.pop();
		if(u==t)
		break;//cout<<u<<endl;
		for(int i=h[u];i;i=e[i].nx)
		{//<<e[i].v<<endl;
			if(vis[e[i].v])
				continue;
			if(dis[e[i].v]>dis[u]+e[i].w)
			{
				dis[e[i].v]=dis[u]+e[i].w;
				tmp.id=e[i].v;
				tmp.dis=dis[e[i].v];
				q.push(tmp);
			}
		}
	}
	return dis[t];
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,w;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&w);
		build(i,i+m,w);
	}
	int k;
	int sum=m<<1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		int a;
		int t;
		for(int j=1;j<=k;j++)
		{
			scanf("%d%d",&a,&t);
			build(sum+i,a+m,t);
		}
	}
	int x,y;
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&x,&y);
		printf("%lld\n",dij(x,y));
	}
	return 0;
}
