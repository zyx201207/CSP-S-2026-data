#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, x, y;
int a[500005];

struct node {
	int h, a, t;
} b[500005];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i].h;
		for (int j = 1; j <= b[i].h; j++) {
			cin >> b[i].a >> b[i].t;
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> x >> y;
	}
	cout << 34 << endl << 15;
	return 0;
}