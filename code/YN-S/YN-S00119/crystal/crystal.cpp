#include <bits/stdc++.h>
using namespace std;
long long a[100000];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	long long n, m, x;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		a[x]++;
	}
	long long t = -99999, l = 0, c = 99999, k = 0;
	for (int i = 1; i <= 100000; i++) {
		if (a[i] > t) {
			t = a[i];
			l = i;
		}
		if (a[i] < c) {
			c = a[i];
			k = i;
		}
	}
	sort(a + 1, a + n + 1);
	long long s = 0, b = m, v = 0;
	for (int i = 1; i <= m; i++) {
		if (b == 0) {
			break;
		}
		for (int j = 1; j <= m; j++) {
			if (a[i] < l) {
				a[i]++;
				b--;
			}
			if (a[i] == l) {
				s++;
				v++;
			}
		}
		s = s - b;
		v = v - i;
	}
	long long o = abs(n - m);
	cout << v - s + k - l + o;
	return 0;
}