#include <bits/stdc++.h>
using namespace std;
int c, t1, n, d, x[2000005], tu[5005][5005];
int zdl = INT_MAX;

void t2(int l, int y, int yuan, int lu) {
	if (l == y) {
		zdl = min(zdl, lu);
		return;
	}
	for (int i = l; i <= y; i++) {
		if (tu[l][i] == 1)
			t2(i, y, yuan, lu + 1);
	}
}

void t(int l, int y, int yuan, int lu) {
	if (l == y) {
		if (zdl == lu) {
			tu[yuan][y]++;
		}
		return;
	}
	for (int i = l; i <= y; i++) {
		if (tu[l][i] == 1)
			t(i, y, yuan, lu + 1);
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t1;
	while (t1--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (x[j] <= x[i] + d) {
					tu[i][j] = 1;
				} else {
					break;
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + d + 1; j <= n; j++) {
				t2(i, j, i, 1);
				t(i, j, i, 1);
				if (tu[i][j] == 2) {
					ans++;
				}
			}
		}
		cout << ans << endl;
		ans = 0;
		zdl = INT_MAX;
		for (int i = 1; i <= 5000; i++) {
			for (int j = 1; j <= 5000; j++) {
				tu[i][j] = 0;
			}
		}
	}

	return 0;
}