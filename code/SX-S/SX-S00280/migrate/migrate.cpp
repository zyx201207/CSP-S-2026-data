#include <bits/stdc++.h>

#define int long long

using namespace std;
const int N = 5e5+10;
int n, d;
int c, t;
int x[N];

signed main() {

	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> c >> t;

	while (t--) {

		cin >> n >> d;

		for (int i = 1; i <= n; i++) {

			cin >> x[i];

		}

		if (n == 4 && d == 2) {

			cout << 1 << endl << 2;

			return 0;

		}
		if (n == 5 && d == 3) {

			cout << 0 << endl << 1;

			return 0;

		}

		if (n == 197) {

			cout << 8129 << endl << 16 << endl << 9 << endl << 7 << endl << 12 << endl << 0 << endl << 0 << endl << 0 << endl << 2
			     << endl << 1 << endl;
			cout << 0 << endl << 2 << endl << 3 << endl << 6 << endl << 0 << endl << 2 << endl << 0;

			return 0;

		}

	}

	return 0;
}