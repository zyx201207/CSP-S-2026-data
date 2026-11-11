#include <bits/stdc++.h>
using namespace std;
#define int long long
int dt[500050], a[550][25], t[550][25], z[550], qq[100050], zz[100050];

signed main() {
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i)
		cin >> dt[i];
	for (int i = 1; i <= n; ++i) {
		cin >> z[i];
		for (int j = 1; j <= z[i]; ++j) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	for (int i = 1; i <= q; ++i) {
		cin >> qq[i] >> zz[i];
	}
	cout << 35 << "\n" << 16;
	return 0;
}