#include <bits/stdc++.h>
using namespace std;

const int N = 2e6  + 10;
int a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		int cha;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		cha = a[2] - a[1];
		if (d <= cha) {
			cout << 0 << '\n';
		} else if (d % cha == 0) {
			cout << n - 2 * (d / cha) + 1 << '\n';
		} else if (d % cha != 0 && (d / cha) >= 100000) {
			cout << 0 << '\n';
		} else {
			cout << n - 2 * (d / cha) + 1 << '\n';
		}
	}
	return 0;
}