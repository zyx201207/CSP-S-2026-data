#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

#define int long long
#define f(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout);

const int N = 505, M = 5e5 + 5;

int c, n, m, d, q;
int a[M], k;
int ans[N][N];
bool vis[N], st[N];

struct query
{
	int x, y;
	friend bool constexpr operator<(const query &x, const query &y)
	{
		return x.x < y.x;
	}
} qu[M];

int h[N + M], ne[M << 2], e[M << 2], w[M << 2], idx;
void add(int a, int b, int c)
{
	ne[idx] = h[a], e[idx] = b, w[idx] = c, h[a] = idx ++;
}

void dijkstra(int u)
{
	if (vis[u]) return ;
	vis[u] = 1;
	memset(st, 0, sizeof st);
	memset(ans[u], 0x3f, sizeof ans[u]);
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({0, u});
	ans[u][u] = 0;
	
	while (q.size())
	{
		int t = q.top().second, d = q.top().first;
		q.pop();
		
		if (st[t]) continue;
		st[t] = 1;
		
		for (int i = h[t]; ~i; i = ne[i])
		{
			int j = e[i];
			if (ans[u][j] > ans[u][t] + w[i]) 
			{
				ans[u][j] = ans[u][t] + w[i];
				q.push({ans[u][j], j});
			}
		}
	}
	
//		printf("u: %lld\n", u);
//	for (int i = 1; i <= m + n; ++ i) 
//	{
//		printf("\t, %lld: %lld\n", i, ans[u][i]);
//	}
}

signed main()
{
	f(subway);
	scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
	
	for (int i = 0; i <= n + m + 1; ++ i) h[i] = -1;
	
	for (int i = 1; i <= m; ++ i)
	{
		scanf("%lld", a + i);
	}
	
	for (int i = 1; i <= n; ++ i)
	{
		scanf("%lld", &k);
		
		for (int j = 1; j <= k; ++ j)
		{
			int a, t;
			scanf("%lld%lld", &a, &t);
			add(a, m + i, t), add(m + i, a, t);
		}
	}
	
	for (int i = 1; i <= q; ++ i)
	{
		int x, y;
		scanf("%lld%lld", &x, &y);
		if (x > y) swap(x, y);
		dijkstra(x);
		
		printf("%lld\n", ans[x][y] + a[x] + a[y]);
	}
	
	return 0;
}