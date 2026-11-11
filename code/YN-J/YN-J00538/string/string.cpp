#include <bits/stdc++.h>
using namespace std;
long long  a[200050], b[200050];
char s[200050];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n, m = 0, l, r, l_1 = 0, r_1 = 0, sum = 0, flag = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		m += a[i];
		cin >> s[i];
	}
	if (m % 2 != 0) {
		l = m / 2;
		r = m / 2 + 2;
	} else {
		l = m / 2;
		r = m / 2 + 1;
	}
	for (int i = 1; i <= n; i++) {
		if (flag) {
			l -= a[i];
		}

		r -= a[i];

		if (l <= 0) {
			l_1 = a[i] + l;
			l = i;
			flag = 0;
		}
		if (r <= 0) {
			r_1 = -1 * r + 1;
			r = i;
			break;
		}
	}
	while (l != 0 && l_1 != 0) {
		if (s[l] != s[r]) {
			sum += min(l_1, r_1);
		}
		l_1 -= min(l_1, r_1);
		r_1 -= min(l_1, r_1);

		if (l_1 == 0) {
			l--;
			l_1 = a[l];
		}
		if (r_1 == 0) {
			r++;
			r_1 = a[r];
		}
	}
	cout << sum;

	return 0;
}