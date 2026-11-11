#include <bits/stdc++.h>
using namespace std;
long long c, t, n, d, minn = 0x3f3f3f3f, maxn = 0, maxx = 0;
long long a[2000005];
int ans = 0, cnt = 0;

void lu(int cf, int zd) {

	for (int i = cf + 1; i <= n; i++) {

		if (a[i] - a[cf] <= d && i != zd) {
			maxn++;
			lu(i, zd);
		} else if (a[i] - a[cf] <= d + 1 && i == zd  ) {
			if (maxn == maxx) {
				ans++;
				maxn--;
			} else if (maxn > maxx) {
				maxx = maxn;
				ans = 1;
				maxn--;
			}


			return;
		} else {
			maxn--;
			break;
		}
	}


	return;

}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;

	while (t--) {
		for (int i = 1; i <= n; i++) {

			a[i] = 0;
		}

		cin >> n >> d;

		for (int i = 1; i <= n; i++) {

			cin >> a[i];
			minn = min(minn, a[i]);
		}

		if (minn < 0) {
			for (int i = 1; i <= n; i++) {

				a[i] -= minn;

			}
		}

		for (int i = 1; i <= n; i++) {

			for (int j = i + 1; j <= n; j++) {

				ans = 0;
				maxn = 0;
				maxx = 0;

				lu(i, j);

				if (ans == 2) {
					cnt++;

				}
			}
		}

		cout << cnt << endl;

		cnt = 0;
	}

	return 0;

}



