#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q, w[1010], ma[1010][1010];
struct me
{
	int a, t;
}su[1010];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	memset(ma, 0x3f, sizeof(ma));
	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		memset(su, 0, sizeof(su));
		for (int j = 1; j <= k; j++)
		{
			cin >> su[j].a >> su[j].t;
		}
		for (int j = 1; j <= k; j++)
		{
			for (int l = j; l <= k; l++)
			{
				ma[su[l].a][su[j].a] = ma[su[j].a][su[l].a] = min(ma[su[j].a][su[l].a], su[j].t+su[l].t);
			}
		}
	}
	for (int kk = 1; kk <= m; kk++)
	{
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				ma[i][j] = ma[j][i] = min(ma[i][j], ma[i][kk]+ma[kk][j]);
			}
		}
	}
	for (int i = 1; i <= q; i++)
	{
		int x, y;
		cin >> x >> y;
		cout << ma[x][y] + w[x] + w[y] << endl;
	}
	return 0;
}
