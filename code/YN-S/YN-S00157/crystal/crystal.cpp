#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long n, m, a[N], d[N], s[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		d[i] = a[i] + d[i - 1];
		long long x = a[i] * (i - 1) - d[i - 1];
		s[i] = x;
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] > m) {
			ans = i - 1;
			break;
		}
	}
	if (s[n] < m) {
		cout << n;
	} else {
		cout << ans;
	}
	return 0;
}