#include <iostream>
#include <algorithm>
#include <cstring> 
using namespace std;
long long w[500010], t[500010];
long long g[1010][1010];
int kk[510], a[500010];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	memset(g, 0x3f3f3f, sizeof(g));
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
	{
		cin >> w[i];
		g[i][i] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> kk[i];
		for (int j = 1; j <= kk[i]; j++)
		{
			cin >> a[j] >> t[j];
		}
		for (int j = 1; j < kk[i]; j++)
		{
			for (int k = j + 1; k <= kk[i]; k++)
			{
				g[min(a[j], a[k])][max(a[j], a[k])] = min(g[min(a[j], a[k])][max(a[j], a[k])], t[j] + t[k]);
			}
		}
	}
	for (int k = 1; k <= m; k++)
	{
		for (int i = 1; i <= k; i++)
		{
			for (int j = k; j <= m; j++)
			{
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
	for (int i = 1; i <= q; i++)
	{
		int x, y;
		cin >> x >> y;
		if (x > y) swap(x, y);
		cout << g[x][y] + w[x] + w[y] << endl;
	}
	return 0;
}
