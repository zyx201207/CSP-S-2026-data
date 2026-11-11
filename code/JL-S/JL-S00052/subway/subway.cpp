#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int c, n, m, d, q, w[N], a[N][N], sum = 0, t;
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= n; i++)
	{
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++)
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	while(q--)
	{
		sum = 0;
		int x, y;
		cin >> x >> y;
		sum += w[x];
		for(int i = 1; i <= n; i++)
		{
			if(a[i][1] == x)
			{
				x = i + 1;
				sum += a[i][2];
				break;
			}
		}
		for(int i = x; i <= n; i++)
		{
			sum += a[i][2];
			sum += a[i + 1][2];
		}
		cout << sum;
	}
	return 0;
}
