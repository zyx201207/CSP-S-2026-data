#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int a[N];
int k[505][N];
int c, n, m, d, q, sx, sy;

namespace subtask2 {
	void solve() {
		int sum = a[sx] + a[sy], sum1 = 0, sum2 = 0, minn = INT_MAX;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= k[i][0] * 2; j += 2) {
				if (k[i][j] == sx) {
					sum1 += k[i][j + 1];
				}
				if (k[i][j] == sy) {
					sum2 += k[i][j + 1];
				}
			}
			minn = min(minn, sum1 + sum2);
		}
		cout << sum + minn;
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
	}
	int f1 = 1, f2 = 1;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (x > 2)
			f1 = 0;
		k[i][0] = x;
		for (int j = 1; j <= x * 2; j += 2) {
			cin >> k[i][j] >> k[i][j + 1];
		}
		for (int j = 2; j <= x; j++) {
			if (k[i][j] != k[i][j - 1]) {
				f2 = 0;
				break;
			}
		}
		if (i != 1) {
			if (k[i][1] != k[i - 1][1])
				f2 = 0;
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> sx >> sy;
		subtask2::solve();
	}
	return 0;
}