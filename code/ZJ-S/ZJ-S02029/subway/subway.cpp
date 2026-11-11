#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,n,m,d,q,i,j,fu[500005],k,v,w,ans,dis[600005];
const ll inf=1e18;
struct edge
{
	ll v,w;
	bool operator<(const edge &e)const
	{
		return w>e.w;
	}
};
priority_queue<edge>qu;
vector<edge>way[600001];
bitset<600001>vis;
void dij(ll s)
{
	for(i=1;i<=m+n;i++)
	{
		dis[i]=inf;
	}
	while(!qu.empty())
	{
		qu.pop();
	}
	qu.push({s,0});
	vis=0;
	dis[s]=0;
	while(!qu.empty())
	{
		edge u=qu.top();
		qu.pop();
		if(vis[u.v])continue;
		vis[u.v]=1;
		if(u.v==w)break;
		for(edge ed:way[u.v])
		{
			if(dis[u.v]+ed.w<dis[ed.v])
			{
				dis[ed.v]=dis[u.v]+ed.w;
				if(!vis[ed.v])
				{
					qu.push({ed.v,dis[ed.v]});
				}
			}
		}
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;i++)
	{
		cin>>fu[i];
	}
	for(i=1;i<=n;i++)
	{
		cin>>k;
		for(j=1;j<=k;j++)
		{
			cin>>v>>w;
			way[m+i].push_back({v,w});
			way[v].push_back({m+i,w});
		}
	}
	while(q--)
	{
		cin>>v>>w;
		dij(v);
		cout<<fu[v]+fu[w]+dis[w]<<"\n";
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