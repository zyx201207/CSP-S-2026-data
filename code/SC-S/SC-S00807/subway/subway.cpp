#include<bits/stdc++.h>
using namespace std; 
struct node
{
	long long w;
	int to,nxt;
}g[501000];
int head[501000],tot;
long long a[500010];
void add(int u,int v,int w)
{
	tot++;
	g[tot].to=v;	
	g[tot].w=w;
	g[tot].nxt=head[u];
	head[u]=tot;
}
int vis[500010];
long long ans[500010];
void dij(int u)
{
	vis[u]=1;
	priority_queue<pair<long,long>,deque<pair<long,long> >,greater<pair<long long,long long> > >q;
	for(int i=head[u];i!=0;i=g[i].nxt)
	{
		int v=g[i].to;
		q.push(make_pair(g[i].w,v));
		ans[v]=g[i].w;
	}
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		vis[u]=1;
		for(int i=head[u];i!=0;i=g[i].nxt)
		{
			int v=g[i].to;
//			cout<<ans[u];
			ans[v]=min(ans[v],ans[u]+g[i].w);
			if(vis[v]==1)continue;
			q.push(make_pair(ans[v],v));
		}
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int l=1;l<=k;l++)
		{
			int t,s;
			cin>>s>>t;
			add(s,500000+i,t);
			add(500000+i,s,t);
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		for(int i=1;i<=m;i++)
		{
			vis[i]=0;
			ans[i]=1000000000000000;
		}
		for(int i=500000;i<=500000+n;i++)
		{
			vis[i]=0;
			ans[i]=1000000000000000;
		}
		dij(x);
		cout<<a[x]+a[y]+ans[y]<<endl;
	}
	return 0;
}
