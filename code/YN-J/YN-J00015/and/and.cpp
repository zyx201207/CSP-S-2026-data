#include <bits/stdc++.h>
using namespace std;

long long a[200005] = {};

long long an_d (int x, int y) {
	string f = "", s = "", final = "00000000";
	while (x > 0) {
		f = (char)(x % 2 + '0') + f;
		x /= 2;
	}
	while (f.size() < 8) {
		f = '0' + f;
	}
	while (y > 0) {
		s = (char)(y % 2 + '0') + s;
		y /= 2;
	}
	while (s.size() < 8) {
		s = '0' + s;
	}
	for (int i = 0; i < 8; i++) {
		if (f[i] == '1' && s[i] == '1') {
			final[i] = '1';
		}
	}
	return (final[7] - '0') * 1 + (final[6] - '0') * 2 + (final[5] - '0') * 4 + (final[4] - '0') * 8 +
	       (final[3] - '0') * 16 +
	       (final[2] - '0') * 32 + (final[1] - '0') * 64 + (final[0] - '0') * 128;
}

long long a_nd(int x) {
	string f = "", final = "11111111";
	while (x > 0) {
		f = (char)(x % 2 + '0') + f;
		x /= 2;
	}
	while (f.size() < 8) {
		f = '0' + f;
	}
	for (int i = 0; i < 8; i++) {
		if (final[i] == '1' && f[i] == '1') {
			final[i] = '1';
		}
	}
	return (final[7] - '0') * 1 + (final[6] - '0') * 2 + (final[5] - '0') * 4 + (final[4] - '0') * 8 +
	       (final[3] - '0') * 16 +
	       (final[2] - '0') * 32 + (final[1] - '0') * 64 + (final[0] - '0') * 128;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	long long n, m, big = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (m == 2) {
		for (int i = 1; i <= n - m + 1; i++) {
			int x, y;
			x = a[i];
			for (int j = i + 1; j <= n; j++) {
				y = a[j];
				big = max(big, an_d (x, y));
			}
		}
	}
	if (m == 1) {
		for (int i = 1; i <= n - m + 1; i++) {
			big = max(big, a_nd(a[i]));
		}
	}

	cout << big;
	return 0;
}

