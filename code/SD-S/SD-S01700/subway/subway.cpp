#include<bits/stdc++.h>
using namespace std;
#define maxn 505
int c, n, m, d, q;
int w[maxn], t[maxn][maxn];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++)
		{
			int a;
			cin >> a;
			cin >> t[i][a];
		}
	}
	for (int i = 1; i <= q; i++)
	{
		int xr, yr;
		cin >> xr >> yr;
		int ans = w[xr] + w[yr];
		for (int j = xr; j < yr; j++)
			ans += t[j][j] + t[j][j + 1];
		cout << ans << endl;
	}
	return 0;
}
