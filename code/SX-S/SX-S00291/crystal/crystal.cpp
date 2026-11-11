#include <bits/stdc++.h>
using namespace std;
long long n, m, ans = 0;
long long a[500009];
long long mx = INT_MIN;

bool check(long long x) {
	long long cnt = 0, num = m, f = 1;
	for (int i = 1; i <= n; i++) {
		if (a[i] <= x) {
			if (x - a[i] <= num) {
				num -= x - a[i];
				cnt++;
			} else {
				num = -1;
				break;
			}
			f = 0;
		} else
			break;
	}
	if (num != -1 || f) {
		ans = max(ans, cnt);
		return 1;
	}
	return 0;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	mx = max(mx, a[n]);
	long long l = INT_MIN, r = INT_MAX;
	for (int i = 1; i <= mx * 10; i++) {
		if (!check(i))
			break;
	}
	cout << ans;
	return 0;
}
