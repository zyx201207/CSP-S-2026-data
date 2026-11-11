#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, w[1000005], k[505][500005], f[505][400005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for (int i = 1;i <= n;i++)
	{
		int x;
		cin >> x;
		for (int j = 1;j <= x;j++)
		{
			int t;
			cin >> t;
			cin >> k[i][t];
		}
	}
	for (int i = 1;i <= q;i++)
	{
		int x, y, sum = 0;
		cin >> x >> y;
		for (int j = 1;j <= n;j++)
		{
			if (k[j][x] > 0)
			{
				sum += k[j][x];
				break;
			}
		}
		for (int j = 1;j <= n;j++)
		{
			if (k[j][y] > 0)
			{
				sum += k[j][y];
				break;
			}
		}
		cout << w[x] + w[y] + sum;
	}
	return 0;
}
