#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
	long long n, ans = 0;
	cin >> n;
	long long a[200005];
	char b[200005];
	for (long i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}
	for (long i = 1; i <= (n + 1) / 2; i++) {
		if (b[i] != b[n + 1 - i]) {
			ans = ans + max(a[i], a[n + 1 - i]);
		} else {
			ans = ans;
		}
	}
	cout << ans;
	return 0;
}