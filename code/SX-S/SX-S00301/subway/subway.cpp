#include <bits/stdc++.h>
using namespace std;
int c, n, m, dd, q;
int sbw[500100], d[1010][1010], a[500100], t[500100], kd[1010][1010];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	for (int i = 1; i <= 1000; i++) {
		for (int j = 1; j <= 1000; j++) {
			d[i][j] = 100000010;
			kd[i][j] = 100000010;
		}
	}
	cin >> c >> n >> m >> dd >> q;
	for (int i = 1; i <= m; i++) {
		cin >> sbw[i];
	}
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		for (int j = 1; j <= x; j++) {
			cin >> a[j] >> t[j];
			d[i][a[j]] = min(d[i][a[j]], t[j]);
		}
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 1; k <= n; k++) {
				kd[i][j] = min(kd[i][j], d[k][i] + d[k][j]);
			}

		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 1; k <= m ; k++) {
				kd[i][j] = min(kd[i][j], kd[i][k] + kd[k][j]);
			}
		}
	}
	cout << endl;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			cout << kd[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << kd[x][y] + sbw[x] + sbw[y] << endl;
	}
}