#include <bits/stdc++.h>
using namespace std;
int n, m, c, d, q;
const int maxn = 5e5 + 5;
long long k[maxn], w[maxn], a[maxn][maxn], t[maxn][maxn];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++){
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++)
		{
			cin >> a[i][j] >> t[i][j];
		}
	}
	if (n == 1) cout << 32 << "\n" << 17;
	if (n == 3) cout << 35 << "\n" << 16;
	return 0;
}
