#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long n, a[N], ans;
char c[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	int l = 1, r = n;
	while (l < r) {
		if (a[l] > a[r]) {
			if (c[l] != c[r]) {
				ans += a[r];
			}
			a[l] -= a[r];
			r--;

		} else if (a[l] == a[r]) {
			if (c[l] != c[r]) {
				ans += a[l];
			}
			l++;
			r--;
		} else {
			if (c[l] != c[r]) {
				ans += a[l];
			}
			a[r] -= a[l];
			l++;

		}
	}
	cout << ans;
	return 0;
}
