#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5 , M = 505;
int a[M][N] , t[M][N] , w[N] , k[N];
signed main()
{
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c , n , m , d , q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i];
		cin >> a[i][1] >> t[i][1];
		for (int j = 1; j <= k[i] * 2; j++)
		{
			cin >> a[i][j] >> t[i][1];
		}
	}
	while (q--)
	{
		int l , r;
		cin >> l  >> r;
		int ans = 0;
		for (int i = l; i <= r; i++) ans += t[1][i];
		cout << ans << "\n";
	}
	return 0;
}

