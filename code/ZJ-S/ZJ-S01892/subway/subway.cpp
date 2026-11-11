#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1100;
const int M = 1100;
int c, n, m, d, q;
int w[M];
int g[N][M];
int a[N][N];
int s[M][M];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++)
		scanf("%d", &w[i]);
	memset(g, 0x3f, sizeof(g));
	memset(a, 0x3f, sizeof(a));
	memset(s, 0x3f, sizeof(s));
	for (int i = 1; i <= n; i++)
	{
		int k;
		scanf("%d", &k);
		for (int j = 1; j <= k; j++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			g[i][x] = y;
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
		{
			if (i == j || a[i][j] != 0x3f) continue;
			for (int k = 1; k <= m; j++)
				if (g[i][k] != 0x3f && g[j][k] != 0x3f)
					a[i][j] = min(a[i][j], g[i][k] + g[j][k]);
		}
	for (int i = 1; i <= m; i++)
		for (int j = i; j <= m; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				if (g[k][i] != 0x3f && g[k][j] != 0x3f) s[i][j] = min(s[i][j], g[k][i] + g[k][j]);
			}
		}
	for (int i = 1; i <= q; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		cout << s[x][y] + w[x] + w[y] << '\n';
	}
	return 0;
}
