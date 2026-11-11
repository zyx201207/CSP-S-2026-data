#include <bits/stdc++.h>
using namespace std;
long long c, t, n, d, x, ans, r;
long long xd[2000005];

bool ch(int y, int z) {
	long long a = 0;
	long long b = 0;
	long long w = d;

	while (w >= 0 && a + z + 1 < n - 1) {
		w -= xd[y + a];
		a++;
	}

	w = d;

	while (w >= 0 && a + b < n - 1) {
		w -= xd[n - 1 - b - r];
		b++;
	}

	if (a + b - 1 == n - 1 - z) {
		return 1;
	} else
		return 0;

}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;

	while (t > 0) {
		cin >> n >> d;
		ans = 0;

		if (n <= 3) {
			cout << 0 << endl;
			continue;
		}

		for (int i = 2; i <= n + 1; i++)

			cin >> xd[i];

		for (int i = 1; i <= n - 1; i++) {

			xd[i] = xd[i + 2] - xd[i + 1];
		}

		for (int i = 1; i <= n - 2; i++) {

			for (int j = 0; j + i <= n - 1; j++) {

				if (ch(i, j))
					ans++;
			}
		}

		cout << ans-- << endl;
		ans = 0;
		t--;
	}

	return 0;
}