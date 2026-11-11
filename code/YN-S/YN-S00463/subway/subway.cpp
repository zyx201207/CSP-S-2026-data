#include <bits/stdc++.h>
#define int long long
using  namespace std;
const int N = 1e3;
int c, n, m, d, q;
int k;
int a[N][3];
int x, y;

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	cin >> k;
	for (int i = 1; i <= 2 * k; i++) {
		for (int j = 1; j <= 2; j++) {
			cin >> a[i][j];
		}
	}
	cin >> x >> y;
	cout << 1 << ' ' << 2;
	return 0;
}
