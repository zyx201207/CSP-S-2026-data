#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pii pair<int,int>
#define fi first
#define se second
int w[500005],k[505];
int c,n,m,d,q;
int dis[1005][1005];
int diss[505];
bool vis[500005];
int tto[500005][25];
int tcur[500005];
vector<int> ok[505];
vector<vector<int>> a,t;
vector<int> temp;
struct edge
{
	int v,w;
};
vector<edge> aa[500005];
priority_queue<pii,vector<pii>,greater<pii>> pq;
queue<int> qqq;
void dijkstra(int s)
{
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=m;i++)	dis[s][i]=2e18;
	dis[s][s]=0;
	vis[s]=0;
	pq.push({0,s});
	while (!pq.empty())
	{
		int tt=pq.top().se;
		pq.pop();
		if (vis[tt])	continue;
		vis[tt]=true;
		for (int i=0;i<aa[tt].size();i++)
		{
			if (dis[s][aa[tt][i].v]>dis[s][tt]+aa[tt][i].w)
			{
				dis[s][aa[tt][i].v]=dis[s][tt]+aa[tt][i].w;
				pq.push({dis[s][aa[tt][i].v],aa[tt][i].v});
			}
		}
	}
}
int y;
int bfs()
{
	while (!qqq.empty())
	{
		int tt=qqq.front();
		//cout<<tt<<endl;
		qqq.pop();
		for (int i=1;i<=tcur[y];i++)
		{
			if (tto[y][i]==tt)	return diss[tt];
		}
		for (int i=0;i<ok[tt].size();i++)
		{
			if (!vis[ok[tt][i]])
			{
				vis[ok[tt][i]]=true;
				qqq.push(ok[tt][i]);
				diss[ok[tt][i]]=diss[tt]+2;
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)	cin>>w[i];
	for (int i=0;i<=m;i++)	temp.push_back(0);
	a.push_back(temp);
	t.push_back(temp);
	int ttt=0;
	for (int i=1;i<=n;i++)
	{
		cin>>k[i];
		a.push_back(temp);
		t.push_back(temp);
		for (int j=1;j<=k[i];j++)
		{
			int p,qq;
			cin>>p>>qq;
			a[i][j]=p;
			t[i][j]=qq;
			tto[p][++tcur[p]]=i;
			ttt=qq;
		}
	}
	if (c<=11)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=k[i];j++)
			{
				for (int l=1;l<=k[i];l++)
				{
					if (j==l)	continue;
					aa[a[i][j]].push_back({a[i][l],t[i][j]+t[i][l]});
				}
			}
		}
		for (int i=1;i<=m;i++)
		{
			dijkstra(i);
		}
		while (q--)
		{
			int x;
			cin>>x>>y;
			cout<<w[x]+w[y]+dis[x][y]<<endl;
		}
	}
	else if (c<=19)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=k[i];j++)
			{
				for (int l=1;l<=tcur[a[i][j]];l++)
				{
					ok[i].push_back(tto[a[i][j]][l]);
					ok[tto[a[i][j]][l]].push_back(i);
				}
			}
		}
		while (q--)
		{
			int x;
			cin>>x>>y;
			while (!qqq.empty())	qqq.pop();
			memset(diss,0,sizeof(diss));
			memset(vis,0,sizeof(vis));
			for (int i=1;i<=tcur[x];i++)
			{
				qqq.push(tto[x][i]);
				vis[tto[x][i]]=true;
				diss[tto[x][i]]=2;
			}
			cout<<bfs()*ttt+w[x]+w[y]<<endl;
		}
	}
	return 0;
}


