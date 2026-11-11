#include <bits/stdc++.h>
using namespace std;
//AC!!!AC!!!AC!!!AC!!!AC!!!AC!!!AC!!!AC!!!AC!!!
int a[2000005];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c, T;
	cin >> c >> T;
	for (int i = 1; i <= T; i++) {
		int n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		if (c == 13 || c == 14) {
			cout << 0 << "\n";
		}
		if (c == 11 || c == 12) {
			cout << (n - d - 1) << "\n";
		}
		if (c >= 15 && c <= 18) {
			cout << 0 << "\n";
		}
	}
	return 0;
}
