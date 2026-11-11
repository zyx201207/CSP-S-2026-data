#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, n, num = 0;
	cin >> c >> n;
	if (c == 0) {
		for (int i = 1; i <= n; i++) {
			int a, b;
			cin >> a >> b;
			int q[a + 5];
			for (int j = 1; j <= a; j++) {
				cin >> q[i];
			}
			for (int j = 1; j <= a; j++) {
				for (int l = 1; l <= b; l++) {
					for (int t = 1; t <= b; t++) {
						if (q[j] + l == q[j + t]) {
							for (int e = 1; e <= b; e++) {
								if (q[j + t] == q[j + t + e]) {
									num++;
								}
							}
						}
					}
				}
			}
			cout << num << endl;
		}
	}
	return 0;
}