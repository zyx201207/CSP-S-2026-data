#include <bits/stdc++.h>
using namespace std;
int c,n,m,w[1005],dl,q,k[1005],a[25][1005],t[25][1005];
int x,y,d[1005][1005];
void dijkstr()
{
	for (int k = 1; k <= m; k++)
	{
		for (int i = k; i <= m; i++)
		{
			for (int j = i; j <= m; j++)
			{
				d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> dl >> q;
	for (int i = 1; i <= m; i++)
	{
		cin >> w[i];
		for (int j = 1; j <= m; j++)
		{
			d[i][j] = 2147483647;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++)
		{
			cin >> a[i][j] >> t[i][j];
			for (int _ = 1; _ < j; _++)
			{
				d[_][j] = d[j][_] = t[i][j] + t[i][_];
			}
		}
	}
	dijkstr();
	while (q--)
	{
		cin >> x >> y;
		cout << d[x][y] + w[x] + w[y] << endl;
	}
	return 0;
}