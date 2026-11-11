#include <bits/stdc++.h>
using namespace std;
long long c, m, n, d, q, k[1005], a[1005][2505], t[1005][2505], w[1005], p[5];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++) cin >> w[i];
	for (int i = 1; i <= n; i ++)
	{
		cin >> k[i];
		for (int j = 1; j <= k[i]; j ++)
		{
			cin >> a[i][j] >> t[i][j];
		}
	}
	cin >> q;
	while(q --)
	{
		long long x, y, l = 1, r = 1;
		//cin >> x >> y;
		long long ans = w[x] + w[y];
		int vis[1005];
		int i = 0;
		while (i ++)
		{
			if (vis[i] < 0) cout << -1;
		}
	}
	return 0;
} 
