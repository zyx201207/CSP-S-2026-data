#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen( "string.in", "r", stdin);
	freopen( "string.out", "w", stdout);
	long long n, s = 0, x, cc = 0;
	char c, lc;
	cin >> n >> x >> lc;
	s += x;
	for (int i = 1; i < n; i++) {
		cin >> x >> c;
		s += x;
		if (c != lc) {
			cc++;
			lc = c;
		}
	}
	if (cc == 1)
		cc = 2;
	if (!cc)
		cout << 0;
	else
		cout << s / cc;

	return 0;
}