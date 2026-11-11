// File Memory Longlong Calm

#include <bits/stdc++.h>

const int N = 1e6 + 10;

using namespace std;

vector<int> G[N];
long long x[N];
long long dp[N], dis[N], vis[N];

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c, T;
	
	scanf("%d %d", &c, &T);
	if(c == 11 || c == 12)
	{
		while(T--)
		{
			int n;
			long long d, q;
			scanf("%d %lld", &n, &d);
			for(int i = 1; i <= n; i++) scanf("%lld", &x[i]);
			q = x[2] - x[1];
//			printf("%lld %lld ", d, q);
			int cnt = d / q;
			if(cnt >= 2) printf("%d\n", max(0, n - 2 * cnt + 1));
			else printf("%d\n", 0);
		}
	}
	else
	{
		while(T--)
		{
			int n;
			long long d;
			scanf("%d %lld", &n, &d);
			for(int i = 1; i <= n; i++) G[i].clear();
			for(int i = 1; i <= n; i++) scanf("%lld", &x[i]);
			for(int i = 1; i <= n; i++) 
			{
				for(int j = i + 1; j <= n; j++) 
				{
					if(abs(x[j] - x[i]) <= d) G[i].push_back(j);
					else break;
				} 
			}
			int ans = 0;
			for(int i = 1; i <= n; i++) 
			{
				for(int j = 1; j <= n; j++) dp[j] = 0, dis[j] = 1e18;
				queue<int> Q;
				dp[i] = 1;
				dis[i] = 0;
				Q.push(i);
				while(!Q.empty())
				{
					int u = Q.front(); Q.pop();
					for(int v : G[u])
					{
						if(dis[v] > dis[u] + 1)
						{
							dis[v] = dis[u] + 1;
							dp[v] = dp[u];
							Q.push(v);
						}
						else if(dis[v] == dis[u] + 1)
						{
							dp[v] += dp[u];
						}
					}
				}
				for(int j = i+1; j <= n; j++) 
				{
					ans += dp[j] == 2;
				}
			}
			
			printf("%d\n", ans);
		}
	}
	
	return 0;
}
