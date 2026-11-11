#include <iostream>
#include <algorithm>
using namespace std;
int w[500005], k[505], a[505][50005], t[505][50005];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++)
		{
			cin >> a[i][j] >> t[i][j];
		}
	}
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		cout << w[x] + w[y] + t[x][1] + t[y][1] << "\n";
	}
	return 0;
}