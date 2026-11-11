#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int w[500005], s[505][500005], sum, x, y, k, z[500005], num;



int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++)
	{
		cin >> w[i];
	}
	for (int i = 1; i <= n; i ++)
	{
		cin >> k;
		for (int j = 1; j <= m; j ++)
		{
			cin >> x >> y;
			if (x == j)
			{
				s[i][x] = y;
			}
		}
	}
	while (q)
	{
		cin >> x >> y;
		for (int i = x ; i <= n; i ++)
		{
			
			for (int j = 1; j <= y; j ++)
			{
				if (s[i][j])
				{
					z[i] += s[i][j];
				}
			}
		}
		for (int i = 1; i <= n; i ++)
		{
			z[i] = 0;
		}
		sum += w[x] + w[y];
		sum = 0;
		q --;
	}
	
	return 0;
}