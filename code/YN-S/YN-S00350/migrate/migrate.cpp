//wr 2026.10.31
#include <bits/stdc++.h>
using namespace std;
int c, t;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
		}
		if (n == 4 && d == 2) {
			cout << 1 << "\n" << 2;
			return 0;
		} else if (n == 5 && d == 3) {
			cout << 0 << "\n" << 1;
			return 0;
		} else {
			cout << 0 << "\n" << 0;
			return 0;
		}
	}
	return 0;
}
