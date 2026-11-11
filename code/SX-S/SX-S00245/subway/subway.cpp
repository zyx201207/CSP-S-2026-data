#include <bits/stdc++.h>
using namespace std;

const int M = 5e5+10, Q = 1e5+10;
int c, n, m, d, q;
int a[510], b[M], f[510][M], t[510][M], x[Q], y[Q], v[510][M];
long long ans = 0, o;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> f[i][j] >> t[i][j];
			v[i][f[i][j]]++;
		}
	}
	for (int i = 1; i <= q; i++) {
		ans = 0;
		cin >> x[i] >> y[i];
		ans = ans + b[x[i]] + b[y[i]];
		cout << ans;
	}

	return 0;
}
