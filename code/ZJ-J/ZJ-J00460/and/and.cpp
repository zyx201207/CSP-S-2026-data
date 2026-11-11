#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
int n, m, a[N];
int c[40];

int cnt(int x) {
	int res = 0;
	while (x) {
		if (x & 1) res++;
		x >>= 1;
	}
	return res;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	int fl = 0;
	for (int i = 0; i <= 25; i++) if (n == (1 << i)) fl = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != i - 1) fl = 0;
	}
	if (fl) {
		int ans = n - 1;
		for (int i = n; i >= n - m + 1; i--) ans &= a[i];
		cout << ans << '\n';
		return 0;
	}
	if (m == 1) {
		int ans = 0;
		for (int i = 1; i <= n; i++) ans = max(ans, a[i]);
		cout << ans << '\n';
		return 0;
	}
	if (m == n) {
		int ans = INT_MAX;
		for (int i = 1; i <= n; i++) {
			ans &= a[i];
		}
		cout << ans << '\n';
		return 0;
	}
	if (m == n - 1) {
		int res = INT_MAX, ans = 0;
		for (int i = 1; i <= n; i++) res &= a[i];
		for (int i = 1; i <= n; i++) ans = max(ans, (~(res ^ a[i])));
		cout << ans << '\n';
		return 0;
	}
	if (m == 2 && n <= 2000) {
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				ans = max(ans, (a[i] & a[j]));
			}
		}
		cout << ans << '\n';
		return 0;
	}
	if (n <= 20) {
		for (int i = 1; i <= n; i++) {
			for (int x = a[i], j = 0; j <= 30; j++) {
				if (x & (1 << j)) {
					c[j] |= (1 << i);
				}
			}
		}
		int ans = 0, nst = INT_MAX;
		for (int i = 30; i >= 0; i--) {
			if (cnt(c[i] & nst) >= m) {
				ans += (1 << i);
				nst &= c[i];
			}
		}
		cout << ans << '\n';
		return 0;			
	}
	return 0;
}

