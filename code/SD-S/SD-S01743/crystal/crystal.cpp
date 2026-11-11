#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

using ll = long long;

ll read() {
	ll res = 0, si = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') si = -si; ch = getchar(); }
	while (ch >= '0' && ch <= '9') res = 10 * res + ch - '0', ch = getchar();
	return res * si;
}

ll n;
ll m, a[N], sum[N];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	int ans = 1;
	for (int i = 2; i <= n; i++) {
		int l = 1, r = i, res = 1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (a[i] * mid <= sum[i] - sum[i - mid] + m) res = mid, l = mid + 1;
			else r = mid - 1;
		}
		ans = max(ans, res);
	}
	cout << ans;
	return 0;
}
