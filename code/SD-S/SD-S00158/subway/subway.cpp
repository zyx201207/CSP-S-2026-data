#include <bits/stdc++.h>
using namespace std;

const int MX = 5e5, NX = 1e5, TX = 5e2;
int w[MX + 10], k[TX + 10], a[TX + 10][MX + 10], t[TX + 10][MX + 10], x[NX + 10], y[NX + 10];
int cnt1[MX + 10], cnt2[MX + 10];

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c, n, m, d, q, i, j;
	bool f = true;
	cin >> c >> n >> m >> d >> q;
	for (i = 1; i <= m; i ++ )
	{
		cin >> w[i];
	}
	for (i = 1; i <= n; i ++ )
	{
		cin >> k[i];
		for (j = 1; j <= k[i]; j ++ )
		{
			cin >> a[i][j] >> t[i][j];
			cnt1[a[i][j]] = i;
			cnt2[a[i][j]] = j;
		}
		if (k[i] >= 2)
		{
			f = false;
		}
	}
	for (i = 1; i <= q; i ++ )
	{
		cin >> x[i] >> y[i];
	}
	if (f == true)
	{
		for (i = 1; i <= q; i ++ )
		{
			cout << w[x[i]] + w[y[i]] + t[cnt1[x[i]]][cnt2[x[i]]] + t[cnt1[y[i]]][cnt2[y[i]]] << '\n';
		}
	}
	return 0;
}

