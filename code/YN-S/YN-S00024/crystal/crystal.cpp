#include <bits/stdc++.h>
using namespace std;
long long a[500010], b[500010];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	long long mid = 0;
	if (n % 2 == 0)
		mid = a[n / 2];
	else
		mid = a[(n + 1) / 2];
	long long cnt = 0;
	for (long long i = 1; i <= n; i++) {
		b[++cnt] = abs(a[i] - mid);
	}
	sort(b + 1, b + 1 + n);
	long long ct = 1, ans = 0;
	for (long long i = 2; i <= n; i++) {
		if (ans + b[i] <= m) {
			ans = ans + b[i];
			ct++;
		} else {
			cout << ct;
			return 0;
		}
	}
}