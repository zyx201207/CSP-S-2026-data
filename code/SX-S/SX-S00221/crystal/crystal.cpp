#include <bits/stdc++.h>
using namespace std;

long long n, m, c = 100000000, d = 0, e = 0;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 0; i < n - m + 1; i++) {
		if (a[i + m - 1] - a[i] < c) {
			c = a[i + m - 1] - a[i];
		}
	}
	for (int i = 0; i < n - m + 1; i++) {
		if (a[i + m - 1] - a[i] == c) {
			while (i + m - 1 != i + e) {
				d += a[i + m - 1] - a[i + e];
				e++;
			}
		}
	}
	cout << d;
	return 0;
}