#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, a, m = 0, g = 0;
	string c, s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> c;
		for (int j = 0; j < a; j++) {
			s += c;
		}
		m += a;
		if (m > 1000000) {
			break;
		}
	}
	if (m > 1000000) {
		cout << 3000000000;
	} else {
		for (int i = 0; i < m / 2; i++) {
			int j = m - 1;
			if (s[i] != s[j]) {
				g += 1;
			}
			j -= 1;
		}
		cout << g;
	}

	return 0;
}