#include <bits/stdc++.h>
using namespace std;
int n, m, a[1000000], c, s = 1, b = 0, h, s1;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= n - i; j++) {
			if (a[j] < a[j + 1]) {
				c = a[j + 1];
				a[j + 1] = a[j];
				a[j] = c;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		s1 = 1;
		h = m;
		for (int j = i + 1; j <= n; j++) {
			if (a[j] == a[i])
				s1++;
			else {
				if (a[i] - a[j] <= h) {
					s1++;
					h -= a[i] - a[j];
				}
			}
		}
		if (s1 > s)
			s = s1;
	}
	cout << s;
	return 0;
}