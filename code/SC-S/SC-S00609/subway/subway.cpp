#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 505,M = 5e5 + 10;
int c,n,m,d,q,dis[M],w[M],k[N];
struct str
{
	int v,val;
};
struct Com
{
	bool operator()(const str& sx,const str& sy)
	{
		return sx.val > sy.val;
	}
};
vector <str> g[M + N];
bool vis[M];
int dijk(int x,int y)
{
	memset(vis,0,sizeof vis);
	memset(dis,0x3f,sizeof dis);
	priority_queue<str,vector<str>,Com> q;
	q.push({x,0});
	vis[x] = true;
	dis[x] = 0;
	while(!q.empty())
	{
		str tmp = q.top();
		q.pop();
		int u = tmp.v;
		vis[u] = true;
		for(int i=0;i<g[u].size();i++)
		{
			dis[g[u][i].v] = min(dis[u] + g[u][i].val,dis[g[u][i].v]);
			if(!vis[g[u][i].v])
			{
				q.push({g[u][i].v,g[u][i].val});
			}
		}
	}
	return dis[y];
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int aij,tij;
			cin>>aij>>tij;
			g[aij].push_back({m + i,tij});
			g[m + i].push_back({aij,tij});
		}
	}
	while(q -- )
	{
		int x,y;
		cin>>x>>y;
		int ans = dijk(x,y);
		cout<<ans + w[x] + w[y]<<endl;
	}
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