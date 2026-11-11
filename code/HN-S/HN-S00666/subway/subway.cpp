#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int c,n,m,d,Q;
int w[N],dis[N*3];
bool vis[N*3];
struct node
{
	int x,w;
	bool operator < (const node&tmp) const
	{
		return tmp.w<w;
	}
};
vector<node> g[N*3];
void dij(int s)
{
	for(int i=1;i<=m*3;i++)
	{
		dis[i]=1e18;
		vis[i]=0;
	}
	dis[s]=0;
	priority_queue<node> q;
	q.push({s,dis[s]});
	while(!q.empty())
	{
		int x=q.top().x;
		q.pop();
		if(vis[x])
			continue;
		vis[x]=true;
		for(int i=0;i<g[x].size();i++)
		{
			int y=g[x][i].x,w=g[x][i].w;
			if(dis[x]+w<dis[y])
			{
				dis[y]=dis[x]+w;
				q.push({y,dis[y]});
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a,t;
			cin>>a>>t;
			g[i+m].push_back({a,t});
			g[a].push_back({i+m,t});
		}
	}
	while(Q--)
	{
		int x,y;
		cin>>x>>y;
		dij(x);
		cout<<dis[y]+w[x]+w[y]<<"\n";
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
