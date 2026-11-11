#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
struct nod
{
	ll v,w,road,c;
	friend bool operator<(const nod &a,const nod &b)
	{
		if(a.road==b.road)
		{
			return a.w>b.w;
		}
		else
		{
			return a.w+a.c>b.w;
		}
	}
};
int co,n,m,d,q,x,s,t,a[N];
ll dis[N];
bool vis[N];
vector<nod>g[N];
void dijkstra(int st)
{
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	priority_queue<nod>q;
	dis[st]=0;
	q.push({st,dis[st],0,0});
	while(!q.empty())
	{
		nod cur=q.top();
		q.pop();
		int u=cur.v;
		if(vis[u])
		{
			continue;
		}
		vis[u]=1;
		for(auto e:g[u])
		{
			int v=e.v,w=e.w,road=e.road,c=e.c;
			if(vis[v])
			{
				continue;
			}
			if(cur.road==road)
			{
				if(dis[u]+w<dis[v])
				{
					dis[v]=dis[u]+w;
					q.push({v,dis[v],road,c});
				}
			}
			else
			{
				if(dis[u]+w+c<dis[v])
				{
					dis[v]=dis[u]+w+c;
					q.push({v,dis[v],road,c});
				}
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>co>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		int v[x+5],w[x+5];
		for(int j=1;j<=x;j++)
		{
			cin>>v[j]>>w[j];
			for(int k=1;k<=j;k++)
			{
				if(j!=k)
				{
					g[v[k]].push_back({v[j],w[j],i,w[k]});
					g[v[j]].push_back({v[k],w[j],i,w[j]});
				}
			}
		}
	}
	while(q--)
	{
		cin>>s>>t;
		dijkstra(s);
		cout<<dis[t]+a[s]+a[t]<<"\n";
	}
}
