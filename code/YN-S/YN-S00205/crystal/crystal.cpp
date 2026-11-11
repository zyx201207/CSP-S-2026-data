#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500000];
long long ans[500000], ans1[500000];

bool aa(int c, int b) {
	return c < b;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	int p=m;
	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	if (n % 2 == 1) {
		for (int i = 1; i <= n; i++) {

			ans[i] = abs(a[n / 2 + 1] - a[i]);
		}

		sort(ans + 1, ans + 1 + n, aa);
		int i1 = 0;

		while (true) {
			i1++;
			m = m - ans[i1];

			if (m < 0) {
				i1--;
				break;
			}

			if (i1 == n) {
				break;
			}
		}

		cout << i1;
	} else {
		for (int i = 1; i <= n; i++) {

			ans[i] = abs(a[n / 2 ] - a[i]);
		}

		sort(ans + 1, ans + 1 + n, aa);
		int i1 = 0;

		while (true) {
			i1++;
			m -= ans[i1];

			if (m < 0) {
				i1--;
				break;
			}

			if (i1 == n) {
				break;
			}
		}
		m=p;
		for (int j = 1; j <= n; j++) {

			ans[j] = abs(a[n / 2 + 1] - a[j]);
		}

		sort(ans1 + 1, ans1 + 1 + n, aa);
		int j1 = 0;

		while (true) {
			j1++;
			m -= ans1[j1];

			if (m < 0) {
				j1--;
				break;
			}

			if (j1 == n) {
				break;
			}
		}

		cout << min(i1, j1);
	}

	return 0;
}
