#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,k,u,v,tot,cnt[4000005],vis[400005],dis[400005],head[400005],w[20005],a[20005],t[20005];
struct edge
{
	int u,v,w;
}e[2000005];
void add(int u,int v,int w)
{
	e[++tot].u=u;
	e[tot].v=v;
	e[tot].w=w;
	head[u]=tot;
}
void dij(int s)
{
	for(int i=1;i<=m*(d+1);i++)vis[i]=false;
	for(int i=1;i<=m*(d+1);i++)dis[v]=1e15;
	priority_queue<pair<int,int> >q;
	dis[s]=0;
	vis[s]=true;
	q.push({0,s});
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		for(int v=head[u];v;v=e[v].v)
		{
			int x=e[v].u;
			if(dis[x]>dis[u]+e[x].w)
			{
				dis[x]=dis[u]+e[x].w;
				vis[x]=true;
				q.push({dis[x],x});
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c<=8||(c>=12&&c<=15))
	{
		for(int i=1;i<=m;i++)cin>>w[i];
		for(int i=1;i<=n;i++)
		{
			cin>>k;
			for(int j=1;j<=k;j++)
			{
				cin>>a[j]>>t[j];
				cnt[a[j]]++;
				w[a[j]]=(d+1)*a[j]+cnt[a[j]];
				if(j>1)
				{
					add(w[a[j]],w[a[j-1]],0ll);
					add(w[a[j-1]],w[a[j]],0ll);
				}
				add(w[a[j]],(d+1)*a[j],t[j]);
				add((d+1)*a[j],w[a[j]],t[j]);
			}
		}
		for(int i=1;i<=q;i++)
		{
			cin>>u>>v;
			dij((d+1)*u);
			cout<<dis[(d+1)*v]+w[u]+w[v]<<"\n";
		}
	}
	return 0;
}


