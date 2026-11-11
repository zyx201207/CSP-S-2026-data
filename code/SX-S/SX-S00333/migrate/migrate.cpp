#include <bits/stdc++.h>
using namespace std;
int c, t;
int n;
int d;
int x[2000005];
int m;
int cnt = 0;
int zdl[1000005][1000005];
int lx = 1;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	m = -1;
	for (int i = 1; i <= t; i++) {
		cin >> n >> d;
		for (int j = 1; j <= n; j++) {
			cin >> x[j];
		}
		memset(zdl, 0x3f, sizeof(zdl));
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (x[j] - x[i] > d) {
					if (i != 1 && j != 1) {
						m = zdl[i][j - 1];
					}
					if (j - i == 1) {
						m = 1;
						continue;
					} else if (x[j - 1] - x[j] < x[j] - x[i] - d) {
						m++;
					}
				}

				zdl[i][j] = m;
			}
			for (int k = i + 1; k <= n; k++) {
				if (zdl[i][k] == zdl[i][k - 1]) {
					lx++;
				}
			}
			if (lx == 2)
				cnt++;
			m = -1;
		}
		cout << cnt << endl;
		memset(x, 0, sizeof(x));
	}
	return 0;
}