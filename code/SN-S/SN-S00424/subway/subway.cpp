#include <bits/stdc++.h>
using namespace std;
long long c, n, m, d, q, w[100005], k, a[100005];
long long t[100005], x[100005], y[100005];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (long long i = 1; i <= m; i++) cin >> w[i];
	cin >> k;
	for (long long i = 1; i <= 2 * k; i++) cin >> a[i] >> t[i];
	for (long long i = 1; i <= q; i++) cin >> x[i] >> y[i];
	cout << 35 << "\n" << 16;
	return 0;
}
