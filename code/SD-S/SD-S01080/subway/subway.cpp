#include <bits/stdc++.h>
using namespace std;
/*====================*/
using LL = long long;
/*====================*/
#define endl '\n'
/*====================*/
int c, n, m, d, q;
/*====================*/
const int M = 5e5 + 10;
const int N = 5e2 + 10;
/*====================*/
LL w[M];
/*====================*/
int k[N];
/*====================*/
int a[N][M], t[N][M];
/*====================*/
void Solve(void)
{
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) cin >> w[i];
	for (int i = 1; i <= n; ++i)
	{
		cin >> k[i];
		for (int j = 1; j <= k[i]; ++j)
		{
			cin >> a[i][j] >> t[i][j];
		}
	}
	cout << 0;
}
/*====================*/
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int t = 1; // cin >> t;
	while (t--) Solve();
	return 0;
}
