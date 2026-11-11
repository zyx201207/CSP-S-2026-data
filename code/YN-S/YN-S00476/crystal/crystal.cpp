#include <bits/stdc++.h>
using namespace std;
freeopen("crystal.in", 'r', stdin);
freeopen("crystal.out", 'w', stdout);

int main() {
	long long n, m;
	cin >> n >> m;
	long long a[n], b[n] = {0}, c = 0, ci = 0, max = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 1; i < n; i++) {
		b[i - 1] = a[i] - a[i - 1];
	}
	int sum[50000] = {0};
	for (int i = 0; i < n; i++) {
		sum[a[i]]++;
		if (sum[a[i]] >= 2) {
			c++;
		}
	}
	if (c <= 1) {
		for (int i = 1; i < n; i++) {
			if (m - b[i]*i >= 0)
				m = m - b[i] * i;
			else {
				cout << i + 1 << ' ';
				return 0;
			}
		}
	} else if (c >= 2) {
		for (int i = 0; i < n; i++) {
			if (b[i] == 0) {
				ci = i - 1;
			}
		}
		for (int i = ci - 1; i >= 0; i--) {
			if (m - b[i] >= 0) {
				cout << m << ' ' << b[i];
				m = m - b[i];
				c++;
			} else {
				break;
			}
		}
		cout << c;
	}
}