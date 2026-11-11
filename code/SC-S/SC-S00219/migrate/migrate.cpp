#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int maxn = 2e6 + 7;

int n;
LL d, a[maxn];

namespace subtask_1_2_3
{
	LL g[5007][5007];
	int f[5007][5007];
	
	void solve()
	{
		memset(f, 0, sizeof(f)), memset(g, 0, sizeof(g));
		g[1][1] = 0, f[1][1] = 1;
		int s = 1;
		for (int i = 2; i <= n; i ++)
		{
			int p = 0;
			for (int j = 1; j < i; j ++)
			{
				if (a[i] - a[j] <= d)
				{
					p = j;
					break;
				}
			}
			f[i][i] = 1, g[i][i] = 0;
			if (p == 0)
			{
				s = i;
				continue;
			}
			f[i - 1][i] = 1, g[i - 1][i] = 1;
			for (int j = s; j <= i - 2; j ++)
			{
				if (j > p) p ++;
				g[j][i] = g[j][p] + 1;
				if (f[j][p] > 2) f[j][i] = 3;
				if (f[j][p] == 2)
				{
					if (p == i - 1) f[j][i] = 2;
					else if (g[j][p] != g[j][p + 1]) f[j][i] = 2;
					else f[j][i] = 3;
				}
				if (f[j][p] == 1)
				{
					if (p == i - 1) f[j][i] = 1;
					else if (g[j][p] != g[j][p + 1]) f[j][i] = 1;
					else
					{
						if (p == i - 2) f[j][i] = 2;
						else if (g[j][p] != g[j][p + 2]) f[j][i] = 2;
						else f[j][i] = 3;
					}
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i ++)
			for (int j = i + 1; j <= n; j ++)
				if (f[i][j] == 2) ans ++;
		cout << ans << '\n';
	}
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c, T;
	cin >> c >> T;
	while (T --)
	{
		cin >> n >> d;
		for (int i = 1; i <= n; i ++) cin >> a[i];
		subtask_1_2_3::solve();
	}
	return 0;
}