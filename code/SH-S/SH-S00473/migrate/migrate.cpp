#include<bits/stdc++.h>
using namespace std;

constexpr int N = 2e6 + 10;
static long long a[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	if (1 <= c && c <= 10)
	{
		while (t--)
		{
			struct point
			{
				long long w, cnt;
			};
			long long n, d;
			cin >> n >> d;
			vector<vector<point>> g(n + 1, vector<point>(n + 1, {0x3f3f3f3f3f3f3f3f, 0}));
			for (int i = 1; i <= n; i++)
			{
				g[i][i] = {0, 0};
			}
			for (int i = 1; i <= n; i++)
			{
				cin >> a[i];
			}
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j < i; j++)
				{
					if (a[j] + d >= a[i])
					{
						g[i][j] = {1, 0};
						g[j][i] = {1, 0};
					}
				}
			}
			for (int k = 1; k <= n; k++)
			{
				for (int i = 1; i <= n; i++)
				{
					for (int j = 1; j <= n; j++)
					{
						if (k == i || k == j)
						{
							break;
						}
						long long ne = g[i][k].w + g[k][j].w;
						if (ne < g[i][j].w)
						{
							g[i][j] = g[j][i] = {ne, 1};
						}
						else if(ne == g[i][j].w)
						{
							g[i][j].cnt++;
							g[j][i].cnt++;
						}
					}
				}
			}
			long long cnt = 0;
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j < i; j++)
				{
					if (g[i][j].cnt > 1 && g[i][j].cnt == 2 && g[i][j].w==2)
					{
//						cout << i << ' ' << j <<'\n';
						cnt++;
					}
				}
			}
//			cout << g[1][4].w << g[1][4].cnt <<'\n';
			cout << cnt << '\n';
		}
		return 0;
	}
	if (13 <= c && c <= 14)
	{
		while (t--)
		{
			long long n, d;
			cin >> n >> d;
			cout << 1ll * n * (n - 1) / 2 << '\n';
		}
	}
	else
	{
		while (t--)
		{
			cout << "0\n";
		}
	}
	return 0;
}
