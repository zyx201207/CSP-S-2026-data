#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	int a[i];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < m; j++) {
			if (c == 0) {
				cout << a[i];
			}
		}
	}
	sort(a + 1, a + 1 + n);
	return 0;
}