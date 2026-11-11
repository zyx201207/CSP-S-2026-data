#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[500005];
long long cnt[500005];
long long x;
long long minn = 10000005;
long long cnti;
long long y[500005];
long long e;
long long ans = 1;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i ++) {

		cin >> a[i];
	}

	for (int i = 1; i <= n; i ++) {

		for (int j = 1; j <= n; j ++) {

			if (a[i] <= a[j]) {
				x += a[j] - a[i];
			} else {
				x += a[i] - a[j];
			}
		}


		cnt[i] = x;
		x = 0;
	}

	for (int i = 1; i <= n; i ++) {

		if (cnt[i] < minn) {
			minn = cnt[i];
			cnti = i;
		}
	}

	for (int i = 1; i <= n; i ++) {

		if (a[i] < a[cnti]) {
			y[i] = a[cnti] - a[i];
			e += y[i];
			ans ++;
		}
	}

	for (int i = 1; i <= n; i ++) {

		if (a[i] == a[i + 1]) {
			ans ++;
		}
	}

	if (e <= m) {
		cout << ans;
	} else {
		if (m - e <= m) {
			cout << ans - 1;
		}

		if (m - e > m) {
			cout << ans - 2;
		}
	}

	return 0;
}
