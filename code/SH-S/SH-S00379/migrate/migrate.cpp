#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long LL;
const int N = 5005;
int c, t, n, ans, a[N][N], r[N][N], g[N][N], f[N][N];
LL d, x[N];
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
		{
			cin >> x[i];
		}
		for (int i = 1; i <= n; i++)
		{
			f[i][i] = 0;
			for (int j = i + 1; j <= n; j++)
			{
				f[i][j] = 1e9;
				for (int k = i; k < j; k++)
				{
					if (x[j] - x[k] <= d)
					{
						f[i][j] = min(f[i][j], f[i][k] + 1);
					}
				}
//				cout << i << " " << j << " " << f[i][j] << endl;
//				r[i][f[i][j]] = j;
			}
		}
		ans = 0;
		for (int i = 1; i <= n; i++)
		{
			g[i][i] = 1;
			for (int j = i + 1; j <= n; j++)
			{
				g[i][j] = 0;
				for (int k = i; k <= j - 1; k++)
				{
					if (x[j] - x[k] <= d && f[i][k] + 1 == f[i][j])
					{
						g[i][j] += g[i][k];
					}
				}
				ans += (g[i][j] == 2);
				if (g[i][j] > 2) g[i][j] = 3;
			}
		}
		cout << ans << endl;
	}
}
