#include <bits/stdc++.h>
using namespace std;
long long n, m, maxn, k = 1, cnt;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	string a, b;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		int x;
		cin >> x;
		a[i] = x;
	}

	for (int i = 1; i <= n; i++) {

		if (a.length() == 1) {
			cout << a[i];
		}

		int x = m;

		for (int j = 1; j <= n; j++) {

			if (a[j] == a[j + 1]) {
				cnt++;
			}

		}

		while (x > 0) {
			x -= k * (a[i + 1] - a[i]);
			k += 1;
			cnt++;
		}

		maxn = max (cnt, maxn);

		if (a[i] + m > a[i + 1]) {
			break;
		}
	}

	cout << maxn;
	return 0;
}
