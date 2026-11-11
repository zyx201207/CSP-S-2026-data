#include <iostream>
#include <vector>
using namespace std;

vector <long long> g[1000001];
long long father[1000001], d[1000001], dis[1001][1001];
bool flag[1000001], vis[1000001];

long long query(long long x)
{
	if (father[x] == x)
	{
		return x;
	}
	father[x] = query(father[x]);
	return father[x];
}

void merge(long long x, long long y)
{ 
	x = query(x);
	y = query(y);
	father[x] = y;
}

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	long long c, t;
	cin >> c >> t;
	while (t--)
	{
		long long n, k;
		cin >> n >> k;
		for (long long i = 0; i < n; ++i)
		{
			g[i].clear();
		}
		for (long long i = 0; i < n; ++i)
		{
			for (long long j = i + 1; j < n; ++j)
			{
				dis[i][j] = 1e18;
				dis[j][i] = 1e18;
			}
		}
		for (long long i = 1; i < n; ++i)
		{
			long long u, v;
			cin >> u >> v;
			u -= 1;
			v -= 1;
			g[u].push_back(v);
			g[v].push_back(u);
			dis[u][v] = 1;
			dis[v][u] = 1;
		}
		for (long long k = 0; k < n; ++k)
		{
			for (long long i = 0; i < n; ++i)
			{
				for (long long j = i + 1; j < n; ++j)
				{
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
					dis[j][i] = dis[i][j];
				}
			}
		}
		long long ans = 1e18;
		for (long long i = 0; i < (1 << n); ++i)
		{
			for (long long j = 0; j < n; ++j)
			{
				flag[j] = false;
				father[j] = j;
				vis[j] = false;
				d[j] = 1e18;
			}
			int one = 0;
			for (long long j = 0; j < n; ++j)
			{
				if (((i >> j) & 1) == 1)
				{
					one += 1;
					flag[j] = true;
				}
			}
			if (one != k)
			{
				continue;
			}
			for (long long j = 0; j < n; ++j)
			{
				if (flag[j] == false)
				{
					continue;
				}
				for (long long k = 0; k < g[j].size(); ++k)
				{
					long long nxt = g[j][k];
					if (flag[nxt] == false)
					{
						continue;
					}
					merge(j, nxt);
				}
			}
			long long cnt = 0;
			for (long long j = 0; j < n; ++j)
			{
				if (flag[j] == false)
				{
					continue;
				}
				if (vis[father[j]] == false)
				{
					cnt += 1;
				}
				vis[father[j]] = true;
			}
			if (cnt > 2)
			{
				continue;
			}
			for (long long j = 0; j < n; ++j)
			{
				for (long long k = 0; k < n; ++k)
				{
					if (flag[k] == false)
					{
						continue; 
					}
					d[j] = min(d[j], dis[j][k]);
				}
			}
			long long maxn = 0;
			for (long long j = 0; j < n; ++j)
			{
				maxn = max(maxn, d[j]);
			}
			ans = min(ans, maxn);
		}
		cout << ans << "\n";
	}
	
	return 0;
}
