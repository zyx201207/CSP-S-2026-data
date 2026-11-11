#include <bits/stdc++.h>
using namespace std;
const int N = 505, M = 5 * 1e5 + 5;
int c, n, m, d, q, w[M], k[N], a[N][3], t[N][3], x, y;
str
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &w[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &k[i]);
		for (int j = 1; j <= k[i]; j++)
		{
			scanf("%d%d", &a[i][j], &t[i][j]);
		}
	}
	return 0;
}

