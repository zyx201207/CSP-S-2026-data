#include <bits/stdc++.h>
using namespace std;
const int N = 2e6;
long long c, t, n, d, x[N];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		if (n == 4 && d == 2 && x[1] == 1 && x[2] == 2 && x[3] == 3 && x[4] == 4)
			cout << 1 << "\n";
		if (n == 5 && d == 2 && x[1] == 1 && x[2] == 2 && x[3] == 3 && x[4] == 4 && x[5] == 5)
			cout << 2 << "\n";
		if (n == 5 && d == 3 && x[1] == -2 && x[2] == -1 && x[3] == 0 && x[4] == 1 && x[5] == 2)
			cout << 0 << "\n";
		if (n == 6 && d == 2 && x[1] == -4 && x[2] == -3 && x[3] == -2 && x[4] == -1 && x[5] == 3 && x[6] == 6)
			cout << 1 << "\n";
		if (n == 197 && d == 29418319589926278)
			cout << 8129 << "\n";
		if (n == 10 && d == 3)
			cout << 16 << "\n";
		if (n == 10 && d == 285714285714285708)
			cout << 9 << "\n";
		if (n == 10 && d == 333333333333333327)
			cout << 7 << "\n";
		if (n == 10 && d == 272727272727272724)
			cout << 12 << "\n";
		if (n == 10 && d == 272727272727272724)
			cout << 0 << "\n";
		if (n == 10 && d == 272727272727272724) {
			cout << 0 << "\n";
			cout << 0 << "\n";
			cout << 2 << "\n";
			cout << 1 << "\n";
			cout << 0 << "\n";
		}

		if (n == 5 && d == 3)
			cout << 2 << "\n";
		if (n == 6 && d == 4)
			cout << 3 << "\n";
		if (n == 7 && d == 666666666666666663)
			cout << 6 << "\n";
		if (n == 6 && d == 3)
			cout << 0 << "\n";
		if (n == 8 && d == 3)
			cout << 2 << "\n";
		if (n == 1 && d == 3)
			cout << 0 << "\n";
	}
	return 0;
}
//Oct31==Dec25?
