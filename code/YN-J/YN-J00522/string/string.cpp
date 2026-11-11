#include <bits/stdc++.h>
using namespace std;
long long n, c, su;
string a, b, s, d;

int main() {
	cin >> n;
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	for (int i = 1; i <= n; i++) {
		cin >> c >> s;
		for (int j = 1; j <= c; j++) {
			a += s;
		}
	}
	int x = (a.size() + 1) / 2;
	for (int i = 0; i < x; i++) {
		b += a[i];
	}
	for (int i = a.size() - 1; i >= x - 1; i--) {
		d += a[i];
	}
	for (int j = 0; j < x; j++) {
		if (b[j] != d[j]) {
			su += 1;
		}
	}
	cout << su;
	return 0;
}