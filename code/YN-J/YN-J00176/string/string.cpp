#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long int a[200000] = {0};
	char c[200000];
	int n = 0;
	long long int len = 0, x = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> c[i];
		len = a[i] + len;
	}
	int cc = 0, f = 0, h = 0;
	len = len / 2 + 1;
	for (int i = 0; i < len; i++) {
		if (f == 0) {
			h = n - i - 1;
		}
		f = 0;
		if (c[i] == c[h]) {
			cc = a[i] - a[h];
			if (cc == 0) {
				len = len - a[i];
			} else if (a[i] > a[h]) {
				len = len - a[n - 1 - i];
				f = 1;
			} else if (a[i] < a[h]) {
				len = len - a[i];
				cc = cc * -1;
				f = -1;
			}
			if (f == 1) {
				a[i] = cc;
				i = i - 1;
				h = n - 1 - i;
			} else if (f == -1) {
				a[h] = cc;
			}
		} else {
			cc = a[i] - a[h];
			if (cc == 0) {
				len = len - a[i];
				x = x + a[i];
			} else if (a[i] > a[h]) {
				f = 1;
				len = len - a[h];
				x = x + a[h];
			} else if (a[i] < a[h]) {
				f = -1;
				len = len - a[i];
				x = x + a[i];
				cc = cc * -1;
			}
			if (f == 1) {
				a[i] = cc;
				i = i - 1;
				h = n - 1 - i;
			} else if (f == -1) {
				a[h] = cc;
			}
		}
	}
	cout << x;
	return 0;
}