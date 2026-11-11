#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[200005],k[507],u,v;
vector<long long>t[507];
vector<int>a[507];
vector<int>edg[200005];
long long bfs(int u,int v)
{
	long long sum[200005];
	bool vis[200005];
	memset(sum,-1,sizeof(sum));
	memset(vis,0,sizeof(vis));
	vis[u] = 1;
	sum[u] = 0;
	int nw = u;
	while(nw != -1)
	{
		u = nw,nw = -1;
		for(int i = 0;i < edg[u].size();i++)
		{
			int x = edg[u][i];
			long long wt;
			for(int j = 0;j < k[x];j++)
			{
				if(a[x][j] == u)
				{
					wt = t[x][j];
					break;
				}
			}
			for(int j = 0;j < k[x];j++)
			{
				if(a[x][j] == u)continue;
				if(sum[a[x][j]] == -1||sum[a[x][j]] > sum[u]+wt+t[x][j])
				{
					sum[a[x][j]] = sum[u]+wt+t[x][j];
				}
			}
		}
		for(int i = 1;i <= m;i++)
		{
			if(vis[i])continue;
			if((nw == -1||sum[i] < sum[nw])&&sum[i] != -1)
			{
				nw = i;
			}
		}
		if(nw != -1)vis[nw] = 1;
	}
	return sum[v];
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++)
	{
		cin >> k[i];
		a[i].resize(k[i]+1);
		t[i].resize(k[i]+1);
		for(int j = 0;j < k[i];j++)
		{
			cin >> a[i][j] >> t[i][j];
			edg[a[i][j]].push_back(i);
		}
	}
	while(q--)
	{
		cin >> u >> v;
		long long ans = w[u]+w[v]+bfs(u,v);
		cout << ans << "\n";
	}
}
