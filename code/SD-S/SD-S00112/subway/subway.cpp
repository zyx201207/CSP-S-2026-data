#include <bits/stdc++.h>
using namespace std;

struct Node
{
	long long a, t;
};

constexpr long long N = 510;
constexpr long long M = 5e5 + 10;
constexpr long long INF = 0x3f3f3f3f3f3f3f3f;

static long long dist[N][N];
static long long w[M];
static vector<Node> g[M];

int main ()
{
	memset(dist, 0x3f, sizeof(dist));
	for(long long i = 0; i < N; i++)
		dist[i][i] = 0;
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef DEBUG
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
#endif // DEBUG
#ifdef DEBUG
#endif // DEBUG
	long long c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for(long long i = 1; i <= m; i++)
		cin >> w[i];
	for(long long i = 1; i <= n; i++)
	{
		long long k;
		cin >> k;
		for(long long j = 1; j <= k; j++)
		{
			long long x, t;
			cin >> x >> t;
			for(auto temp : g[x])
			{
				long long v = temp.a;
				long long c = temp.t;
				dist[v][i] = c + t;
				dist[i][v] = c + t;
			}
			g[x].push_back({i, t});
		}
	}
	for(long long k = 1; k <= n; k++)
		for(long long i = 1; i <= n; i++)
			for(long long j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	while(q--)
	{
		long long x, y;
		cin >> x >> y;
		long long ans = INF;
		for(auto i : g[x])
			for(auto j : g[y])
				ans = min(ans, dist[i.a][j.a] + w[x] + w[y] + i.t + j.t);
		cout << ans << '\n';
	}

	return 0;
}

