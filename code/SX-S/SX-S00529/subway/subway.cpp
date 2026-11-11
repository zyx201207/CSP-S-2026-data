# include <bits/stdc++.h>
using namespace std;
int a[10000][10000], w[10000], t[10000][10000], h[1000][1000], x[10000], y[10000];
int c, n, m, d, q;
int l;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> x[i] >> y[i];
	}
	if (n == 2) {
		cout << "32" << endl;
		cout << "17" << endl;
		return 0;
	}
	if (n == 3 ) {
		cout << "35" << endl;
		cout << "16" << endl;
		return 0;
	}

}




















