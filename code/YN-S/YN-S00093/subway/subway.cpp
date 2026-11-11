#include <bits/stdc++.h>
#include <queue>
using namespace std;
long long c, n, m, d, q;
queue<long long> qx, qy;
long long w[500005], a[25][100005], t[25][100005], k[25], x, y;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (long long i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> x >> y;
		for (int i = 1; i <= d; i++) {

		}
	}
	return 0;
}