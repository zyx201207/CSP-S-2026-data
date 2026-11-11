#include <bits/stdc++.h>
#define int long long
using namespace std;
int w[500005],dis[500005],n,m,qq,c,d;
bool vis[500005];
struct node2
{
	int u,w;
};
vector <node2> v[500005];
struct node
{
	int dis,u;
	bool operator>(const node &a) const {return a.dis<dis;}
};
priority_queue<node,vector<node>,greater<node> > q;
void dij(int s)
{
	memset(dis,0x3f3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	q.push({0,s});
	dis[s]=0;
	while(!q.empty())
	{
		int u=q.top().u;
		q.pop();
		if(vis[u]==1)continue;
		vis[u]=1;
		for(int i = 0;i<v[u].size();i++)
		{
			int t=v[u][i].u,w=v[u][i].w;
			if(dis[t]>dis[u]+w)
			{
				dis[t]=dis[u]+w;
				q.push({dis[t],t});
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> qq;
	for(int i = 1;i<=m;i++)
	{
		cin >> w[i];
	}
	for(int i = 1;i<=n;i++)
	{
		int k,lastx=-1,x,lasty=-1,y;
		cin >> k;
		for(int i = 1;i<=k;i++)
		{
			cin >> x >> y;
			if(i==1)lastx=x,lasty=y;
			else
			{
				v[lastx].push_back({x,lasty+y});
				v[x].push_back({lastx,lasty+y});
				lastx=x;lasty=y;
			}
		}
	}
	while(qq--)
	{
		int x,y;
		cin >> x >> y;
		dij(x);
		cout << dis[y]+w[x]+w[y]<< "\n";
	}
	return 0;
}
