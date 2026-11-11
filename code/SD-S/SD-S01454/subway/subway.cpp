#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500010];
int vis[1000010];
long long dis[1000010];
long long f[500010];
struct E{
	int to,w;
};
vector<E>g[1000010];
int a[500010];
struct node{
	int x,w;
	friend bool operator<(node a,node b)
	{
		return a.w>b.w;
	}
};
priority_queue<node>pq;
void dij(int s)
{
	memset(dis,0x3f,sizeof dis);
	pq.push((node){s,0});
	vis[s]=1;
	dis[s]=0;
	while(!pq.empty())
	{
		int x=pq.top().x;
		pq.pop();
		for(int i=0;i<g[x].size();i++)
		{
			int t=g[x][i].to;
			int ww=g[x][i].w;
			if(!vis[t])
			{
				if(dis[t]>dis[x]+ww)
				{
					vis[t]=1;
					dis[t]=dis[x]+ww;
					pq.push((node){t,dis[t]});
				}
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio();cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	long long cnt=m;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int t;
			cin>>a[j]>>t;
			if(f[a[j]]==0)
			{
				g[a[j]].push_back((E){m+a[j],t});
				g[m+a[j]].push_back((E){a[j],t});
				if(j!=1)
				{
					if(f[a[j-1]]==1)
					{
						g[(f[a[j-1]]-1)*m+a[j-1]].push_back((E){a[j],0});
						g[a[j]].push_back((E){(f[a[j-1]]-1)*m+a[j-1],0});
					}
					else
					{
						g[f[a[j-1]]*m+a[j-1]].push_back((E){a[j],0});
						g[a[j]].push_back((E){f[a[j-1]]*m+a[j-1],0});
					}
				}
				cnt++;
				f[a[j]]++;
			}
			else
			{
				g[(f[a[j]]+1)*m+a[j]].push_back((E){m+a[j],t});
				g[m+a[j]].push_back((E){(f[a[j]]+1)*m+a[j],t});
				if(j!=1)
				{
					if(f[a[j-1]]==1)
					{
						g[(f[a[j-1]]-1)*m+a[j-1]].push_back((E){(f[a[j]]+1)*m+a[j],0});
						g[(f[a[j]]+1)*m+a[j]].push_back((E){(f[a[j-1]]-1)*m+a[j-1],0});
					}
					else
					{
						g[f[a[j-1]]*m+a[j-1]].push_back((E){(f[a[j]]+1)*m+a[j],0});
						g[(f[a[j]]+1)*m+a[j]].push_back((E){f[a[j-1]]*m+a[j-1],0});
					}
				}
				f[a[j]]++;
			}
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		memset(vis,0,sizeof vis);
		dij(m+x);
		cout<<dis[m+y]+w[x]+w[y]<<"\n";
	}
	return 0;
}
