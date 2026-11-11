#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int N = 510;
int c, n, m, d, q, w[N], t[N][N], a[N][N], k[N];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++) cin >> w[i];
	for(int i = 1; i <= n; i ++)
	{
		cin >> k[i];
		for(int j = 1; j <= k[i]; j ++)
		{
			cin >> a[i][j] >> t[i][j];
		}
	}
	return 0;
}
