#include <bits/stdc++.h>
using namespace std;

long long n, m, s, c, x;
long long a[500001];


int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	s = 1;
	for (long long i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	x = m;
	for (long long i = 0; i < n; i++) {
		if (x >= 0) {
			c = (a[i + 1] - a[i]) * s;
			if (c == 0) {
				s++;
			} else {
				if (c <= x && c >= 0) {
					s++;
					x -= c;
				} else {
					i = n;
					break;
				}
			}
		}
	}
	cout << s;
}