#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e6 + 5, maxx = 5e3 + 5;
ll x[maxn];
vector<int> G[maxx];
bool vis[maxn];
int dis[maxx][maxx];
int cnt[maxx][maxx];
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	scanf("%d%d", &c, &t);
	while(t--)
	{
		int n;
		ll d;
		scanf("%d%lld", &n, &d);
		for(int i = 1; i <= n; i++)scanf("%lld", &x[i]);
		for(int i = 1; i <= n; i++)G[i].clear();
		memset(dis, 0, sizeof(dis));
		memset(cnt, 0, sizeof(cnt));
		int a = 0;
		for(int i = 1; i <= n; i++)
			for(int j = i + 1; j <= n; j++)
				if(x[j] - x[i] <= d)G[i].push_back(j);
		for(int i = 1; i <= n; i++)
		{
			queue<int> q;
			memset(vis, 0, sizeof(vis));
			q.push(i);
			dis[i][i] = 0;
			cnt[i][i] = 1;
			vis[i] = 1;
			while(!q.empty())
			{
				int u = q.front();
				q.pop();
				for(auto v : G[u])
					if(!vis[v])
					{
						dis[i][v] = dis[i][u] + 1;
						cnt[i][v] = cnt[i][u];
						vis[v] = 1;
						q.push(v);
					}
					else if(dis[i][v] == dis[i][u] + 1)cnt[i][v] += cnt[i][u];
			}
		}
		int ans = 0;
		for(int i = 1; i <= n; i++)
			for(int j = i + 1; j <= n; j++)
				if(cnt[i][j] == 2)ans++;
		printf("%d\n", ans);
	}
	return 0;
}
