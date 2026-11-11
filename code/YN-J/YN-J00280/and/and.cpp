#include <bits/stdc++.h>
using namespace std;
long long n, m, s = 0;
long long a[200005];
int zdd[32];
int ztt[32];

main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
		s = max(s, a[i]);
	}

	if (m == 1) {
		cout << s;
	} else if (m == n) {
		for (int i = 1; i <= 30; i++) {

			zdd[i] = a[1] % 2;
			a[1] = a[1] / 2;
		}

		for (int i = 2; i <= n; i++) {

			for (int j = 1; j <= 30; j++) {

				ztt[j] = a[i] % 2;
				a[i] = a[i] / 2;

				zdd[j] = (zdd[j] && ztt[j]);
			}
		}

		long long br = 0;

		for (int i = 1; i <= 30; i++) {

			br += zdd[i] * pow(2, i - 1);
		}

		cout << br;
	} else if (m == 2) {
		long long cl = 0;

		for (int i = 1; i < n; i++) {

			for (int j = i + 1; j <= n; j++) {

				for (int k = 1; k <= 30; k++) {

					zdd[k] = 0;
					ztt[k] = 0;
				}



////////////////////////////////////////////////////////
				int q = a[i];

				for (int k = 1; k <= 30; k++) {


					ztt[k] = q % 2;
					q = q / 2;
				}

				q = a[j];

				for (int k = 1; k <= 30; k++) {

					;
					zdd[k] = q % 2;
					q = q / 2;
				}


//////////////////////////////////////////////////////////
				for (int k = 1; k <= 30; k++) {

					zdd[k] = (zdd[k] && ztt[k]);
				}

				long long br = 0;


////////////////////////////////////////////////////////////
				for (int k = 1; k <= 30; k++) {

					br += zdd[k] * pow(2, k - 1);
				}

				cl = max(cl, br);
			}
		}



		cout << cl;
	} else if (m == n - 1) {
		long long cl = 0;

		for (int k = 1; k <= n; k++) {

			if (k == 1) {
				for (int i = 1; i <= 30; i++) {

					zdd[i] = a[2] % 2;
					a[2] = a[2] / 2;
				}

				for (int i = 3; i <= n; i++) {

					for (int j = 1; j <= 30; j++) {

						ztt[j] = a[i] % 2;
						a[i] = a[i] / 2;

						zdd[j] = (zdd[j] && ztt[j]);
					}
				}

				long long br = 0;

				for (int i = 1; i <= 30; i++) {

					br += zdd[i] * pow(2, i - 1);
				}

				cl = max(cl, br);
			} else {
				for (int i = 1; i <= 30; i++) {

					zdd[i] = a[1] % 2;
					a[1] = a[1] / 2;
				}

				for (int i = 2; i <= n; i++) {

					if (i == k) {
						continue;
					}

					for (int j = 1; j <= 30; j++) {

						ztt[j] = a[i] % 2;
						a[i] = a[i] / 2;

						zdd[j] = (zdd[j] && ztt[j]);
					}
				}

				long long br = 0;

				for (int i = 1; i <= 30; i++) {

					br += zdd[i] * pow(2, i - 1);
				}

				cl = max(cl, br);

			}
		}

		cout << cl;
	} else {
		cout << s;
	}

	return 0;
}