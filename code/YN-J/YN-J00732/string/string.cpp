#include <bits/stdc++.h>
#define int long long
using namespace std;
string s;
int a[300009];
char c[300009];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.in", "w", stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	int n, sum = 0, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		sum += a[i];
	}
	int mid = sum / 2;
	if (sum % 2 != 0) {
		mid++;
	}
	int i = 1, j = n;
	while (sum > 1) {
		int t = min(a[i], a[j]);
		if (c[i] == c[j]) {
			a[i] -= t;
			a[j] -= t;
			sum -= (2 * t);
		}
		if (c[i] != c[j]) {
			ans += t;
			a[i] -= t;
			a[j] -= t;
			sum -= (2 * t);
		}
		if (a[i] == 0) {
			i++;
		}
		if (a[j] == 0) {
			j--;
		}
	}
	cout << ans;
	return 0;
}