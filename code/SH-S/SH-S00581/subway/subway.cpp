#include <iostream>
#include <vector>
using namespace std;

long long w[500005], sum[500005], dp[505][505];
vector < pair <long long, long long> > v[500005];

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	long long c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (long long i = 1; i <= m; ++i)
	{
		cin >> w[i];
	}
	for (long long i = 1; i <= n; ++i)
	{
		long long k;
		cin >> k;
		for (long long j = 1; j <= k; ++j)
		{
			long long a, t;
			cin >> a >> t;
			pair <long long, long long> p;
			p.first = i;
			p.second = t;
			v[a].push_back(p);
		}
	}
	for (long long i = 1; i <= n; ++i)
	{
		for (long long j = i + 1; j <= n; ++j)
		{
			dp[i][j] = 1e18;
			dp[j][i] = 1e18;
		}
	}
	for (long long i = 1; i <= m; ++i)
	{
		for (long long j = 0; j < v[i].size(); ++j)
		{
			for (long long k = j + 1; k < v[i].size(); ++k)
			{
				dp[v[i][j].first][v[i][k].first] = min(dp[v[i][j].first][v[i][k].first], v[i][j].second + v[i][k].second);
				dp[v[i][k].first][v[i][j].first] = dp[v[i][j].first][v[i][k].first];
			}
		}
	}
	for (long long k = 1; k <= n; ++k)
	{
		for (long long i = 1; i <= n; ++i)
		{
			for (long long j = i + 1; j <= n; ++j)
			{
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
				dp[j][i] = dp[i][j];
			}
		}
	}
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		long long ans = 1e18;
		for (long long j = 0; j < v[x].size(); ++j)
		{
			for (long long k = 0; k < v[y].size(); ++k)
			{
				ans = min(ans, w[x] + v[x][j].second + dp[v[x][j].first][v[y][k].first] + w[y] + v[y][k].second);
			}
		}
		cout << ans << "\n";
	}
	
	return 0;
}
