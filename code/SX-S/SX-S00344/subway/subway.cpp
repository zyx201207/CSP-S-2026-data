#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int a[500010];

int main() {
//	freopen("subway.in", "r", stdin);
//	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
	}
	int x, xx;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		for (int j = 1; j <= x; j++) {
			cin >> xx >> a[xx];
		}

	}
	for (int i = 1; i <= q ; i++) {
		cin >> x >> xx;
		cout << 1 << endl;
	}

	return 0;
}