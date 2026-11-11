#include <bits/stdc++.h>
using namespace std;
long long n, m, k, m1, maxx = LLONG_MIN, w, f;
long long a[500010], s[500010];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	w = a[2] - a[1];
	for (int i = 2; i <= n; i++) {
		if (a[i] - a[i - 1] != w)
			f = 1;
	}
	if (f == 0) {
		for (int i = 1; i <= n; i++) {
			m = m - i * w;
			if (m < 0) {
				cout << i;
				return 0;
			}
		}
		cout << n;
		return 0;
	}
	if (n > 5000) {
		cout << n;
		return 0;
	}
	for (int i = 1; i <= n - 1; i++) {
		s[i] = a[i + 1] - a[i];
	}
	for (int i = 1; i <= n - 1; i++) {
		k = 0;
		m1 = m;
		for (int j = i; j <= n; j++) {
			k++;
			m1 = m1 - k * s[j];

			if (m1 < 0) {

				break;
			}

		}
		maxx = max(k, maxx);
	}
	cout << maxx;


	return 0;
}

