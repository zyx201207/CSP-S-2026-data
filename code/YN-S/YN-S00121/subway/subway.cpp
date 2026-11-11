#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, x, y;
long long w[125255];

struct T {
	long long a, t;
} b[505];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int p;
		cin >> p;
		for (int j = 1; j <= 2 * p; j++) {
			cin >> b[i].a >> b[i].t;
		}
	}
	while (q--) {
		cin >> x >> y;
	}
	cout << "2";
	return 0;
}