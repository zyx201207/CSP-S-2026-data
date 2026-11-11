#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <ctime>
using namespace std;

#define int long long
#define f(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout);

const int N = 1e6 + 6, M = 2e6 + 6;

int C, T, n, k;
int h[M + N], oh[M + N], ne[M], e[M], idx;
int seq[N], maxx, ans, dist[N];
bool st[N];

void add(int a, int b)
{
	ne[idx] = h[a], e[idx] = b, h[a] = idx ++;
}

void dijkstra(int u)
{
	memset(st, 0, sizeof st);
	memset(dist, 0x3f, sizeof dist);
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({0, u});
	dist[u] = 0;
	
	while (q.size())
	{
		int t = q.top().second, d = q.top().first;
		q.pop();
		
		if (st[t]) continue;
		st[t] = 1;
		
		for (int i = h[t]; ~i; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > dist[t] + 1) 
			{
				dist[j] = dist[t] + 1;
				maxx = max(maxx, dist[j]);
				q.push({dist[j], j});
			}
		}
	}
}

bool chs[N];

void dfs(int u, int fa = -1)
{
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (j == fa) continue;
		if (chs[j]) dfs(j, u);
	}
	chs[u] = 0;
}

bool valid()
{
	int cnt = 0;
	for (int i = 1; i <= n; ++ i)
	{
		if (chs[i]) dfs(i), cnt ++;
	}
	return cnt <= 2;
}

signed main()
{
	f(hub);
	scanf("%lld%lld", &C, &T);
	
	for (int _ = 0; _ < T; ++ _)
	{
		scanf("%lld%lld", &n, &k);
		for (int i = 1; i <= n + 1; ++ i) h[i] = -1;
		for (int i = 1; i < n; ++ i)
		{
			int x, y;
			scanf("%lld%lld", &x, &y);
			add(x, y), add(y, x);
		}
		
		for (int i = 1; i <= n; ++ i) seq[i] = i;
	
		int oidx = idx;
		for (int i = 1; i <= n + 1; ++ i) oh[i] = h[i];
		
		int ans = 1e18;
		
		clock_t start = clock();
		
		while (clock() - start <= 830 / T)
		{
			for (int i = 1; i <= 100; ++ i)
			{
				memset(chs, 0, sizeof chs);
				random_shuffle(seq + 1, seq + 1 + n);
				for (int j = 1; j <= k; ++ j) chs[seq[j]] = 1;
				if (valid())
				{
					for (int j = 1; j <= k; ++ j) add(n + 1, seq[j]);
					
					maxx = -1e18;
					dijkstra(n + 1);
					
					ans = min(ans, maxx - 1);
					idx = oidx;
					for (int i = 1; i <= n + 1; ++ i) h[i] = oh[i];
				}
			}
		}
		
		printf("%lld\n", ans);
	}
	
	return 0;
}