#include <bits/stdc++.h>
using namespace std;
int n;
string s, a, b;
long long e, f;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long x;
		string y;
		cin >> x >> y;
		for (int j = 0; j < x; j++) {
			s += y;
		}
	}
	long long  m = s.length() / 2;
	for (int i = 0; i < m; i++) {
		a += s[i];
	}
	for (int i = m + 1; i < s.length(); i++) {
		b += s[i];
	}
	for (int i = 0; i < m; i++) {
		if (a[i] != b[i]) {
			e++;
		}
	}
	for (int i = 0; i < m; i++) {
		if (b[i] != a[i]) {
			f++;
		}
	}
	if (e > f) {
		cout << f;
	} else {
		cout << e;
	}
	return 0;
}