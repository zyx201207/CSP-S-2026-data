#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define int long long
using namespace std;

priority_queue<pii, vector<pii>, greater<pii> > q;
vector<int> g[505];
int C, n, m, d, Q;
int ex[20005];
int t[505][20005];
int a[505][20005];
int dis[505][20005];
int dp[20005];
int cnt[505];

void bfs(int st, int ed)
{
	for(int i = 1;i <= m;i++)
		dp[i] = 1e18;
	
	q.push({0, st});
	dp[st] = 0;
	while(q.size())
	{
		int u = q.top().second;
		q.pop(); 
		for(int i = 0;i < (int)(g[u].size());i++)
			for(int j = 1;j <= cnt[g[u][i]];j++)
			{
				int v = a[g[u][i]][j];
				if(u == v)
					continue;				
				if(dp[u] + dis[g[u][i]][u] + dis[g[u][i]][v] < dp[v])
				{
					dp[v] = dp[u] + dis[g[u][i]][u] + dis[g[u][i]][v];
					q.push({dp[v], v});
				}
			}
	}
}

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld %lld %lld %lld %lld", &C, &n, &m, &d, &Q);
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			dis[i][j] = 1e18;
	for(int i = 1;i <= m;i++)
		scanf("%lld", &ex[i]);
	for(int i = 1;i <= n;i++)
	{
		scanf("%lld", &cnt[i]);
		for(int j = 1;j <= cnt[i];j++)
		{
			scanf("%lld %lld", &a[i][j], &t[i][j]);
			g[a[i][j]].push_back(i);
			dis[i][a[i][j]] = t[i][j];
		}
	}
	
	while(Q--)
	{
		int x, y;
		scanf("%lld %lld", &x, &y);
		bfs(x, y);
		printf("%lld\n", dp[y] + ex[x] + ex[y]);
	} 
	return 0;
}
