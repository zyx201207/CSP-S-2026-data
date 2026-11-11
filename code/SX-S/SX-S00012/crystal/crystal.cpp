#include <bits/stdc++.h>
using namespace std;
long long n, m, a[1100000], l = INT_MIN, s, p;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		s = 0;
		p = m;
		for (int j = 1; j <= i; j++) {
			if (a[i] - a[j] <= p) {
				s++;
				p -= a[i] - a[j];
			}

		}
		l = max(l, s);
	}
	cout << l;
	return 0;
}
