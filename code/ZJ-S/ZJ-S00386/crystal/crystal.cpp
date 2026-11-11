#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500010];
void solve1 () {
	long long ans = 1;
	for (long long i = 2; i <= n; i++) {
		long long t = (i - 1) * i / 2;
		if (m >= t) ans = i;
	}
	cout << ans;
	return;
}
void solve2 () {
	long long ans = 1, gc = a[2] - a[1];
	for (long long i = 2; i <= n; i++) {
		long long t = gc * i * (i - 1) / 2;
		if (m >= t) ans = i;
	}
	cout << ans;
	return;
}
int main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	bool flag = true, fl = true;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != i) flag = false;
		if (i >= 3 && a[i] - a[i - 1] != a[i - 1] - a[i - 2]) fl = false;
	}
	if (flag) {
		solve1();
		return 0;
	}
	if (fl) {
		solve2();
		return 0;
	}
	sort(a + 1, a + 1 + n);
	long long ans = 1;
	for (long long i = 2; i <= n; i++) {
		long long t = m;
		long long cnt = 1;
		for (long long j = i - 1; j >= 1; j--) {
			t -= a[i] - a[j];
			if (t >= 0) cnt++;
			if (t <= 0) break;
		}
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}