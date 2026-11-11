#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
long long c, n, m, d, q, k;
long long w[500010], a[510][500010], t[510][500010];

int main() {
	//freopen("subway.in", "r", stdin);
	//freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= m; j++) {
			cin >> a[k][j] >> t[k][j];
		}
	}
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
	}
	return 0;
}