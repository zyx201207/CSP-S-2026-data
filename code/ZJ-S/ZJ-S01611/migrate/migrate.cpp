#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 310;
int n, d;
int a[N];
int dist[N][N];
int f[N][N];
void floyd()
{
	for (int k = 1; k <= n; k ++)
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}
void init()
{
	memset(dist, 0x3f, sizeof dist);
	memset(f, 0, sizeof f);
}
signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t --)
	{
		init();
		cin >> n >> d;
		for (int i = 1; i <= n; i ++)
			cin >> a[i];
		if (a[1] < 0)
		{
			int num = abs(a[1]);
			for (int i = 1; i <= n; i ++)
				a[i] += num;
		}
		for (int i = 1; i <= n; i ++)
			dist[i][i] = 0;
		for (int i = 1; i <= n; i ++)
			for (int j = i + 1; j <= n; j ++)
				if (a[j] - a[i] <= d)
				{
					dist[i][j] = 1;
					dist[j][i] = 1;
				}
		floyd();
		for (int len = 1; len <= n; len ++)
			for (int i = 1;  i + len <= n; i ++)
			{
				int j = i + len;
				if (dist[i][j] == 1)
				{
					f[i][j] = 1;
					continue;
				}
				for (int k = i + 1; k <= j - 1; k ++)
					if (dist[i][k] + dist[k][j] == dist[i][j])
						f[i][j] += (f[i][k] * f[k][j]);
			}
		int ans = 0;
		for (int i = 1; i <= n; i ++)
			for (int j = i + 1; j <= n; j ++)
				if (f[i][j] == 2)
					ans ++;
		cout << ans << "\n";
	}
	return 0;
}
