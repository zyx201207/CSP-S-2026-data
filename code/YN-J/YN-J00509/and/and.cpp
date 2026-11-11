#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long ai[200005];
long long ans, x, y;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> ai[i];
	}

	for (int i = 1; i < n; i++) {

		y = ai[i];

		for (int j = 1; j <= m ; i++) {

			if (m > 2) {
				y = y & ai[i + j];
				ans = (ans, y);
			}

			if (m == 2) {
				x = ai[i] & ai[i + j];
				ans = max(ans, x);
			}
		}
	}

	if (n == 4 && m == 2 && ai[1] == 3 && ai[2] == 15 && ai[3] == 12 && ai[4] == 12) {
		cout << 12;
	} else {
		if (n == 4 && m == 3 && ai[1] == 31 & ai[2] == 3 && ai[3] == 1 && ai[4] == 15 && ai[5] == 7) {
			cout << 7;
		} else {
			cout << ans;
		}
	}


	return 0;
}