#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, w[500005];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++)
	{
		int x;
		for (int j = 1; j <= n; j++)
		{
			int y, z;
			cin >> y >> z;
		}
	}
	for (int i = 1; i <= q; i++)
	{
		int r, t;
		cin >> r >> t;
		cout << w[r] + w[t];
	}
	return 0;
}

