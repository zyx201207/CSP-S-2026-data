#include <bits/stdc++.h>
using namespace std;

long long vis[100001], vist[100001], a[501][100001], t[501][100010], k[501], w[100010];

int main()
{
	long long c, n, m, d, q;
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (long long i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	for (long long i = 1; i <= n; i++)
	{
		cin >> k[i];
		for (long long j = 1; j <= k[i]; j++)
		{
			cin >> a[i][j];
			vis[a[i][j]] = i;
			cin >> t[i][j];
			vist[a[i][j]] = t[i][j];
		}
	}
	while (q--)
	{
		long long time11 = 0;
		long long x, y;
		cin >> x >> y;
		time11 = w[x] + w[y];
		long long target = vis[y], gogogo = vis[x];
		time11 += vist[x] + vist[y];
		if (vis[x] == vis[y])
		{
			cout << time11 << endl;
			continue;
		}
		time11 += vist[x + 1] + vist[y - 1];
		cout << time11 << endl;
	}
	
	return 0;
}
