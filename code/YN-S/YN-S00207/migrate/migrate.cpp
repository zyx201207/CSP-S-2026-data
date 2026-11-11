#include <bits/stdc++.h>
using namespace std;
int a[2000001];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;

	while (t--) {
		int n, d;
		cin >> n >> d;

		for (int i = 1; i <= n; i++) {

			cin >> a[i];
		}

		int l = a[2] - a[1];
		d /= l;

		if (d < 2) {
			cout << "0" << endl;
		} else {
			cout << n - 2 * d + 1 << endl;
		}
	}

	return 0;
}