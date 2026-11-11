#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long  a = 0, b = 0, n = 0, x = 0;
	string c, d;
	cin >> a;
	for (int i = 0; i < a; i++) {
		cin >> b >> c;
		for (int j = 0; j < b; j++) {
			d += c;
		}
		n += b;
	}
	int l = 0, r = n - 1;
	while (l <= r) {
		if (d[l] != d[r]) {
			x++;
		}
		l += 1;
		r -= 1;
	}
	cout << x;
	return 0;
}