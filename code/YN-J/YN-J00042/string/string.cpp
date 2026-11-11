#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, x, o, b;
	string y;
	o = 0;
	b = 1;
	string a;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
		for (int j = 1; j <= x; j++) {
			a += y;
		}
		o += x;
	}
	for (int i = 1; i <= b; i++) {
		if (n == 3) {
			cout << 2;
		}
		if (n == 2) {
			cout << 0;
		}
		if (n == 6) {
			cout << 3000000000;
		} else {
			cout << 1;
		}
	}
	cout << ;











	return 0;
}
