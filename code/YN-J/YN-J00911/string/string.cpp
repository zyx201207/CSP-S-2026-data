#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long a, n, m = 0, g = 0, h = 0, b = 0;
	string c, s;
	cin >> n;

	for (int i = 1; i <= n; i++) {

		cin >> a;
		cin >> c;
		m += a;

		for (int j = 1; j <= a; j++) {

			s += c;
		}
	}

	h += m - 1;

	if (m % 2 != 0) {
		while (g != h) {
			if (s[g] != s[h]) {
				b++;
			}

			g++;
			h--;
		}
	} else {
		while (h - g != 1) {
			if (b != 0) {
				g++;
				h--;
			}

			if (s[g] != s[h]) {
				b++;
			}


		}
	}

	cout << b;

	return 0;
}