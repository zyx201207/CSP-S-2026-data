#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 6;
int c, n, m, d, q, w[N], k[N], a[500][N], t[500][N], x[N], y[N];
int b[N];
queue<int> q;
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++)
		{
			cin >> a[i][j] >> t[i][j];
		}
	}
	for (int i = 1; i <= q; i++)
	{
		cin >> x[i] >> y[i];
	}
	q.push(1);
	b[1] = 1;
	while (q.size()) 
	{
		int u = q.front();
		q.pop();
	}
	return 0;
}
