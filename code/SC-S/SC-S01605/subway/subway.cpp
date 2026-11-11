#include <bits/stdc++.h>
using namespace std;
int w[500010], x[510], biao[1010][1010];
int c, n, m, d, q;
void floyd()
{
	for (int k = 1; k <= m; k++)
	{
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= m; j++) biao[i][j] = min(biao[i][j], biao[i][k] + biao[k][j]);
		}
	}
}
int main()
{
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= m; j++) biao[i][j] = 1e9;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i];
		int a, t1, b, t2;
		cin >> a >> t1 >> b >> t2;
		biao[a][b] = min(t1 + t2, biao[a][b]);
		biao[b][a] = min(t1 + t2, biao[b][a]);
	}
	floyd();
	while (q--)
	{
		int a, b;
		cin >> a >> b;
		cout << biao[a][b] + w[a] + w[b] << endl;
	}
	return 0;
}//20pts go go go