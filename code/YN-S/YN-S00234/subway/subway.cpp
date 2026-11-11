#include <bits/stdc++.h>
using namespace std;
int tk[500005];

struct xl {
	int zhan[505];
	int tz[505];
	int k;
} x[505];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 0; i < m; i++) {
		cin >> tk[i];
	}
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		x[i].k = k;
		for (int j = 0; j < k; j++) {
			int a, c;
			cin >> a >> c;
			x[i].zhan[j] = a;
			x[i].tz[j] = c;
		}
	}
	while (q--) {
		long long sum = 0;
		int x, y;
		cin >> x >> y;
		sum += tk[x] * 2 + tk[y] * 2;
		bool l = true;
		for (int i = 0; i < n && l; i++) {
			if (x[i].zhan[0] != x) {
				continue;
			}
			for (int j = 0; j < 2 && l; j++) {
				sum += x[i].tz[j];
				if (x[i].zhan[j] == y) {
					l = false;
				}
			}
			sum += x[i].tz[j];
		}
		cout << sum << endl;
	}
	return 0;
}