#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, w[500100], x[100100], y[100100], k[550], a[500100], t[500100], u, v;
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++)
	{
		cin >> k[i];
		for(int j = 1;j <= k[i];j++)
		{
			cin >> u >> v;
			a[u] = k[i];
			t[u] = v;
		}
	}
	for(int i = 1;i <= q;i++)
	{
		cin >> x[i] >> y[i];
	}
}
