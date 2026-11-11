#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, n, m, d, q, a[505][50005], t[505][50005], w[500005];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	cout << w[1] + w[m];
	return 0;
}