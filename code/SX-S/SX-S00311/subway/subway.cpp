#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q;
int a[1010][1010];
int w[1010];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	if (c >= 7 && c <= 11) {
		int ki;
		for (int i = 1; i <= n; i++) {
			cin >> ki;
			int zi, zt;
			cin >> zi >> zt;
			int li = zi, lt = zt;
			for (int j = 2; j <= ki; j++) {
				cin >> zi >> zt;
				a[li][zi] = zt + lt;
				a[zi][li] = zt + lt;
				li = zi;
				lt = zt;
			}
		}
	} else {
		int kj;
		for (int i = 1; i <= n; i++) {
			cin >> kj;
			int zid[n + 1], zti[n + 1];
			for (int j = 1; j <= kj; j++) {
				cin >> zid[j] >> zti[j];
			}
			for (int j = 1; j <= kj; j++) {
				for (int k = j + 1; k <= kj; k++) {
					if (a[zid[j]][zid[k]] == 0 || zti[j] + zti[k] < a[zid[j]][zid[k]]) {
						a[zid[j]][zid[k]] = zti[j] + zti[k];
					}
				}
			}
		}
	}
	/*
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	*/
	for (int k = 1; k <= m; k++) {
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {
				if ((a[i][k] != 0 && a[k][j] != 0 && i != j) && (a[i][j] == 0 || a[i][k] + a[k][j] < a[i][j])) {
					a[i][j] = a[i][k] + a[k][j];
					//cout << "---" << i << " " << j << a[i][j] << endl;
				}
			}
		}
	}
	int x, y;
	for (int i = 1; i <= q; i++) {
		cin >> x >> y;
		cout << a[x][y] + w[x] + w[y] << endl;
	}
	return 0;
}
/*
0 3 4 2 10
1 1 1 1
2 1 1 2 1
2 2 1 3 1
2 3 1 4 1

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
