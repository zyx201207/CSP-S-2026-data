#include<bits/stdc++.h>
using namespace std;
long long n, m, a[500010], now = 0;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	long long now = 0, u;
	for (int i = 1; i < n; i++) {
		long long s = a[i + 1] - a[i];
		if (s < 0) s = -s;
		if (now + i * s > m) break;
		now = now + i * s;
		u = i + 1;
	}
	for (int i = u; i <= n; i++) {
		if (a[u + 1] == a[u]) u++;
		else break;
	}
	int l = 1, r = u;
	long long ans = u;
	while (r != n) {
		long long d = a[r] - a[l];
		if (d < 0) d = -d;
		now = now - d;
		l++;
		for (int i = r; i < n; i++) {
			long long s = a[i + 1] - a[i];
			if (s < 0) s = -s;
			if (now + (r - l + 1) * s > m) break;
			now = now + (r - l + 1) * s;
			r = r + 1;
		}
		for (int i = r; i < n; i++) {
			if (a[r + 1] == a[r]) r++;
			else break;
		}
		if (ans < r - l + 1) ans = r - l + 1;
	}
	cout << ans << '\n';
	return 0;
}