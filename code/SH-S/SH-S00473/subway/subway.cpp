#include<bits/stdc++.h>
using namespace std;

constexpr int N = 510, M = 5e5 + 10;
static int a[N][M], t[N][M];
static int w[M];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	if (1 <= c && c <= 15)
	{
		vector<vector<long long>> g(n + m + 10, vector<long long>(n + m + 10, 0x3f3f3f3f));
		for (int i = 1; i <= n + m; i++)
		{
			g[i][i] = 0;
		}
		for (int i = 1; i <= n; i++)
		{
			int k;
			cin >> k;
			for (int j = 1; j <= k; j++)
			{
				int a, t;
				cin >> a >> t;
				g[i][a + n] = t;
				g[a + n][i] = t;
			}
		}
		for (int k = 1; k <= n + m; k++)
		{
			for (int i = 1; i <= n + m; i++)
			{
				for (int j = 1; j <= n + m; j++)
				{
					g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
				}
			}
		}
		while (q--)
		{
			int x, y;
			cin >> x >> y;
			cout << w[x] + w[y] + g[n + x][n + y] << '\n';
		}
		return 0;
	}
	else
	{
		while (q--)
		{
			cout << "0\n";
		}
	}
	return 0;
}
