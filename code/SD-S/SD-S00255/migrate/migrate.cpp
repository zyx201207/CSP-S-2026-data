#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
long long c, t, n, d, x[2000005], nowi, l[2000005], f[5][2000005], g[3][2000005], ans;
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(0)->ios::sync_with_stdio(false);
	cout.tie(0);
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> d;
		nowi = 1;
		for (int i = 1;i <= n;++i)
		{
			cin >> x[i];
			while (x[i] - d > x[nowi])
			{
				++nowi;
			}
			l[i] = nowi;
		}
		if (c == 11 || c == 12)
		{
			if (d < (x[2] - x[1]) * 2)
			{
				cout << "0\n";
				continue;
			}
			else
			{
				cout << max(0ll, n - (d / (x[2] - x[1])) * 2 + 1) << "\n";
				continue;
			}
		}
		ans = 0;
		for (int i = 1;i <= n;++i)
		{
			f[3][i] = f[2][i] = f[1][i] = g[2][i] = g[1][i] = 0;
			if (i > 1)
			{
				g[2][i] += min(l[i], i - 1ll) - l[i - 1];
				if (min(l[i], i - 1ll) - l[i - 1] >= 2)
				{
					g[2][i] += g[2][l[i - 1] + 1];
				}
				else if (min(l[i], i - 1ll) - l[i - 1] == 1)
				{
					g[2][i] += g[1][l[i - 1]];
				}
			}
			g[1][i] += i - l[i];
			if (i - l[i] >= 2)
			{
				g[1][i] += g[2][l[i] + 1];
			}
			else if (i - l[i] == 1)
			{
				g[1][i] += g[1][l[i]];
			}
			if (i > 2)
			{
				f[3][i] += min(l[i], i - 2ll) - min(l[i - 1], i - 2ll);
				if (min(l[i - 1], i - 2ll) - l[i - 2] >= 3)
				{
					f[3][i] += f[3][l[i - 2] + 2];
				}
				else if (min(l[i - 1], i - 2ll) - l[i - 2] == 2)
				{
					f[3][i] += f[2][l[i - 2] + 1];
				}
				else if (min(l[i - 1], i - 2ll) - l[i - 2] == 1)
				{
					f[3][i] += f[1][l[i - 2]];
				}
				else if (min(l[i], i - 2ll) - min(l[i - 1], i - 2ll) >= 2)
				{
					f[3][i] += g[2][min(l[i - 1], i - 2ll) + 1];
				}
				else if (min(l[i], i - 2ll) - min(l[i - 1], i - 2ll) == 1)
				{
					f[3][i] += g[1][min(l[i - 1], i - 2ll)];
				}
			}
			if (i > 1)
			{
				f[2][i] += i - 1 - min(i - 1ll, l[i]);
				if (min(l[i], i - 1ll) - l[i - 1] >= 3)
				{
					f[2][i] += f[3][l[i - 1] + 2]; 
				}
				else if (min(l[i], i - 1ll) - l[i - 1] == 2)
				{
					f[2][i] += f[2][l[i - 1] + 1];
				}
				else if (min(l[i], i - 1ll) - l[i - 1] == 1)
				{
					f[2][i] += f[1][l[i - 1]];
				}
				else if (i - 1 - min(i - 1ll, l[i]) >= 2)
				{
					f[2][i] += g[2][min(i - 1ll, l[i]) + 1];
				}
				else if (i - 1 - min(i - 1ll, l[i]) == 1)
				{
					f[2][i] += g[1][min(i - 1ll, l[i])];
				}
			}
			if (i - l[i] >= 3)
			{
				f[1][i] = f[3][l[i] + 2];
			}
			else if (i - l[i] >= 2)
			{
				f[1][i] = f[2][l[i] + 1];
			}
			else if (i - l[i] == 1)
			{
				f[1][i] = f[1][l[i]];
			}
			ans += f[1][i];
		}
		cout << ans << "\n";
	}
	return 0;
}
