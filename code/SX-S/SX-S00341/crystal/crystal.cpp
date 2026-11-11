#include <bits/stdc++.h>
using namespace std;
int n;
long long a[500005];
long long m, ans = 1, na, l;

long long check(int x) {
	long long cnt = 0;
	na = 0;
	for (int i = l ; a[i] <= x; i++) {
		cnt += (x - a[i]);
		if (a[i] <= x) {
			na++;
		}
	}
	return cnt;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a, a + n + 1);
	l = a[1];
	long long  r = a[n];
	while (l <= r) {
		int mid = (l + r) / 2;
		long long q = check(mid);
		if (q <= m) {
			ans = max(ans, na);
			l = mid + 1;
		} else
			r = mid - 1;
	}
	cout << ans;
	return 0;
}