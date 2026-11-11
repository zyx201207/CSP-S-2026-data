#include <cstdio>
#include <queue>

typedef long long int ll;
constexpr int N = 2e6 + 5, INF = 0x3f3f3f3f;

struct Node
{
	int u, v, w;
};

ll c, t, n, d, ans, a[N], dis[N], cnt[N];

int main(void)
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	scanf("%lld %lld", &c, &t);
	
	while (t --> 0)
	{
		scanf("%lld %lld", &n, &d);
		ans = 0;
		
		for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
		
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cnt[j] = 0;
				if (j != i) dis[j] = INF;
			}
			
			std::queue<Node> q;
			q.push({i, i, 0});
			cnt[i] = 1;
			
			while (!q.empty())
			{
				int u = q.front().u, v = q.front().v, w = q.front().w;
				q.pop();

				if (cnt[u] && u != i)
				{
					if (w == dis[u]) cnt[u] += cnt[v];
					continue;
				}
				
				cnt[u] = cnt[v];
				dis[u] = w;
				
				for (int j = u + 1; j <= n; j++)
				{
					if (a[j] - a[u] > d) break;
					q.push({j, u, w + 1});
				}
			}
			
			for (int j = 1; j <= n; j++) if (cnt[j] == 2) ans++;
		}
		
		printf("%lld\n", ans);
	}
	
	#define _ 0
	return ~~(0^_^0);
	#undef _
}

