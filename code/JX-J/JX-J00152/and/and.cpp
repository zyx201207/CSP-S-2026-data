#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[n];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int zd = INT_MAX;
	if (m == 1) {
		for (int i = 1; i <= n; i++) {
			if (a[i] > zd) {
				zd = a[i];
			}
		}
		cout << zd;
	} else if (m == 2) {
		for (int i = 1; i < n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if ((a[i] & a[j]) > zd) {
					zd = i & j;
				}
			}
		}
	} if (m == n) {
		int c = 1;
		for (int i = 1; i <= n; i++) {
			c &= a[i];
		}
		cout << c;
	}
	return 0;
}
