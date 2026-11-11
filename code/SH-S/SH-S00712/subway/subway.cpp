#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
const int N=505,M=5e5+5;
int c,n,m,d,q,tot;
int a[M],tmp[M],w[M];
ll dis[M<<1],ans[M<<1];
bool vis[M<<1];
vector<pil>g[M<<1];
vector<pii>op[M];
struct node
{
	int u;
	ll dist;
};
bool operator<(const node& x,const node& y)
{
	return x.dist>y.dist;
}
void Dijkstra(int st)
{
	fill(dis+1,dis+tot+1,2e18);
	fill(vis+1,vis+tot+1,false);
	priority_queue<node>pq;
	pq.push({st,0});
	dis[st]=0;
	while(!pq.empty())
	{
		int u=pq.top().u;
		pq.pop();
		if(vis[u])continue;
		vis[u]=true;
		for(pil i:g[u])
		{
			int v=i.first;
			ll w=i.second;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				if(!vis[v])pq.push({v,dis[v]});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	tot=m;
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int z;
			cin>>tmp[j]>>z;
			tot++;
			g[tot].push_back({tmp[j],z});
			g[tmp[j]].push_back({tot,z});
			w[tmp[j]]=z;
		}
		for(int j=1;j<=k;j++)
			for(int jj=j+1;jj<=k;jj++)
			{
				g[tmp[j]].push_back({tmp[jj],w[tmp[j]]+w[tmp[jj]]});
				g[tmp[jj]].push_back({tmp[j],w[tmp[j]]+w[tmp[jj]]});
			}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		op[x].push_back({y,i}); 
	}
	for(int i=1;i<=m;i++)
		if(!op[i].empty())
		{
			Dijkstra(i);
			for(pii j:op[i])ans[j.second]=a[i]+dis[j.first]+a[j.first];
		}
	for(int i=1;i<=q;i++)cout<<ans[i]<<'\n';
	return 0;
}
/*
Ô¤¼Æ44
*/ 
