#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, i, ans = 0;
	cin >> n;
	long long a[n + 1];
	char s[n + 1];
	for (i = 1; i <= n; i++) {
		cin >> a[i] >> s[i];
	}
	int l = 1, r = n;
	while (l < r) {
		if (a[l] > a[r]) {
			if (s[l] != s[r]) {
				ans += a[r];
			}
			a[l] -= a[r];
			r--;
		} else if (a[l] < a[r]) {
			if (s[l] != s[r]) {
				ans += a[l];
			}
			a[r] -= a[l];
			l++;
		} else {
			if (s[l] != s[r]) {
				ans += a[r];
			}
			l++, r--;
		}
	}
	cout << ans;
	return 0;
}