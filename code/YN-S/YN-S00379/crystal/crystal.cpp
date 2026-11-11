#include <bits/stdc++.h>
using namespace std;

int n;
long long m, a[500100], sum, d;
bool b, c;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != i) {
			b = true;
		}
		if (i >= 3) {
			if (a[i] - a[i - 1] != a[i - 1] - a[i - 2]) {
				c = true;
			}
		}
	}
	if (n <= 2) {
		if (abs(a[1] - a[2]) <= m) {
			cout << 2;
		} else {
			cout << 1;
		}
	} else {
		if (b == false) {
			sum = 1;
			int i = 1;
			while (m >= i) {
				m -= i;
				i++;
				sum++;
				if (sum >= 5) {
					break;
				}
			}
			cout << sum;
		} else if (c == false) {
			sum = 1;
			int i = abs(a[2] - a[1]);
			d = abs(a[2] - a[1]);
			while (m >= i) {
				m -= i;
				i += d;
				sum++;
				if (sum >= 5) {
					break;
				}
			}
			cout << sum;
		}
	}
	return 0;
}