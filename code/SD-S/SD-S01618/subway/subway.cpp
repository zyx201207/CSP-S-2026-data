#include<bits/stdc++.h>
using namespace std;
long long w[500005];
int n,m,cnt,tot=m;
int q,D,c;
bool vis[5000005];
long long d[5000005];
int l[5000005];
struct dian
{
	long long dis,id;
};
struct edge
{
	long long nxt,to,v;
}e[5000005];
map<int,int> mp;
bool operator<(dian a,dian b)
{
	return a.dis>b.dis;
}
void add(int u,int v,int w)
{
	e[++cnt].nxt=l[u];
	l[u]=cnt;
	e[cnt].to=v;
	e[cnt].v=w;
}
long long dijkstra(int s,int t)
{
	memset(d,0x3f,sizeof(d));
	memset(vis,0,sizeof(vis));
	priority_queue<dian> q;
	q.push((dian){0,s});
	d[s]=0;
	while(!q.empty())
	{
		dian tq=q.top();
		q.pop();
		if(vis[tq.id]) continue;
		vis[tq.id]=1;
		for(int i=l[tq.id];i;i=e[i].nxt)
		{
			int now=e[i].to;
			if(vis[now]) continue;
			if(d[now]>d[tq.id]+e[i].v);
			{
				if(d[now]<=d[tq.id]+e[i].v) continue;
				d[now]=d[tq.id]+e[i].v;
				q.push((dian){d[now],now});
			}
		}
	}
	return d[t]+w[s]+w[t];
}
struct node
{
	int x,w;
}a[500005];
bool cmp(node a,node b)
{
	return a.x<b.x;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>D>>q;
	tot=m;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k,lst=0;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[j].x>>a[j].w;
		}
		sort(a+1,a+k+1,cmp);
		for(int j=1;j<=k;j++)
		{
			mp[a[j].x]=++tot;
			if(lst)
			{
				add(lst,mp[a[j].x],0);
				add(mp[a[j].x],lst,0);
			}
			add(a[j].x,mp[a[j].x],a[j].w);
			add(mp[a[j].x],a[j].x,a[j].w);
			lst=mp[a[j].x];
		}
	}
	while(q--)
	{
		int u,v;
		cin>>u>>v;
		cout<<dijkstra(u,v)<<'\n';
	}
	return 0;
}
