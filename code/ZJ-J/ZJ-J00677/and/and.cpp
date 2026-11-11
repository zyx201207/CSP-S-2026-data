#include <bits/stdc++.h>
using namespace std;
unsigned a[200005];
bool checkA(unsigned x) {
	unsigned p = 1;
	for (int i = 0; i < 31; i++) {
		if (x == p - 1) return 1;
		p *= 2;
	}
	return 0;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	unsigned n, m, mx = 0, res = 2147483647;
	bool flagA = 1, flagB = 1;
	cin >> n >> m;
	for (unsigned i = 1; i <= n; i++) {
		cin >> a[i];
		res &= a[i];
		mx = max(mx, a[i]);
		if (!checkA(a[i])) flagA = 0;
		if (a[i] != i - 1) flagB = 0;
	}
	if (m == 1) {
		cout << mx;
		return 0;
	}
	if (m == n) {
		cout << res;
		return 0;
	}
	if (flagB) {
		cout << a[n - m + 1];
		return 0;
	}
	if (flagA) {
		sort(a + 1, a + n + 1);
		cout << a[n - m + 1];
		return 0;
	}
	sort(a + 1, a + n + 1);
	unsigned ans = 2147483647;
	for (unsigned i = n; i >= n - m + 1; i--) {
		ans &= a[i];
	}
	cout << ans;
	return 0;
}
