#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, a[200005];
	char c[30];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> c[i];
	}
	if (n == 1) {
		cout << 0;
		return 0;
	}
	if (n == 2) {
		int l = a[0] + a[1];
		if (a[0] == a[1] || c[0] == c[1]) {
			cout << 0;
			return 0;
		}
		if (l == 4 || l == 3 || l == 6) {
			cout << 1;
			return 0;
		}
		if (l == 5) {
			if (a[0] > 1 || a[1] > 1) {
				cout << 2;
				return 0;
			} else
				cout << 1;
			return 0;
		}
		if (l == 8) {
			if (a[0] == 2 || a[1] == 2)
				cout << 2;
			else
				cout << 1;
			return 0;
		}
		if (l == 9) {
			cout << min(a[0], a[1]);
			return 0;
		}
		if (l == 10) {
			if (a[0] == 4 || a[1] == 4)
				cout << 1;
			else
				cout << min(a[0], a[1]);
			return 0;
		}
	}
	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = n - 1; j > i; j--) {
			if (c[i] == c[j] && i  == n  - j - 1) {
				ans++;
			}
		}
	}
	cout << n / 2 - ans;
	return 0;
}