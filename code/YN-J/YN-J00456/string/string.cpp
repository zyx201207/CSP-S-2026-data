#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, j = 0, p = 0, mm = 0, k = 0;
	long long c = 0, a[100005];
	char b[10005];
	cin >> n;
	string s, x;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		c = c + a[i];
	}
	p = a[0];
	for (int i = 0; i < c; ++i) {
		if (i + 1 > p ) {
			j++;
			p = p + a[j];
		}
		s[i] = b[j];
		x[i] = b[j];
	}
	int h;
	if (c % 2 == 0) {
		h = c / 2;
	} else {
		h = c / 2 + 1;
	}
	for (int i = c - 1; i >= h; --i) {
		if (s[i] != s[k]) {
			mm++;
		}
		k++;
	}
	cout << mm;
	return 0;
}