#include <bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read() {
	char ch = getchar();
	ll x = 0, f = 1;
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
int n;
ll m, a[500010], use[500010];
int ans = 1;
bool check(int x) {
	for (int i = 1; i + x - 1 <= n; i ++ ) {
		int j = i + x - 1;
		// [i, j]
		if (use[j] - use[i] - (i - 1) * (a[j] - a[i]) <= m) return 1; 
	}
	return 0;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read(); m = read();
	for (int i = 1; i <= n; i ++ ) a[i] = read();
	sort(a + 1, a + n + 1);
	use[1] = 0;
	for (int i = 2; i <= n; i ++ ) {
		use[i] = use[i - 1] + (a[i] - a[i - 1]) * (i - 1);
	}
	int l = 1, r = n;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		} else r = mid;
	}
	cout << ans;
	return 0;
}