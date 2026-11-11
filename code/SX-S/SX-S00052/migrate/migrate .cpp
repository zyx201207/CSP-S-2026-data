#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdin);
	long long c, t, n, d,  lj[20000], ans = 0, cha, ttt = 0, ljl;
	cin >> c >> t ;
	for (int q = 1; q <= t; q++) {

		cin >> n >> d;
		cin >> lj[1] >> lj[2];
		cha = lj[2] - lj[1];
		for (int i = 3; i <= n; i++) {
			cin >> lj[i];
			if (lj[i] - lj[i - 1] != cha)
				ttt++;
		}
		d = 2 * d - 1;
		if (cha != 0) {
			for (int i = 1; i <= n; i++)
				for (int j = i + 1; j <= n; j++) {
					if (lj[j] - lj[i] == d)
						ans++;
				}
			cout << ans - 1 << endl;
			ans = 0;
		} else {
			ljl = lj[n] - lj[1];

			if (d > ljl) {
				cout << 0 << endl;

			} else
				cout << ljl - d + 1 << endl;

		}
	}


	return 0;
}
