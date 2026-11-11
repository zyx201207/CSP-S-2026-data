#include <bits/stdc++.h>
using namespace std;
long long a[500005], b[500005];
long long n, m, ans = 0;

bool check(long long s) {
	long long x = a[s];
	long long sum = 0, tot = 1, cnt = m;
	for (int i = 1; i <= n; i++) {
		b[tot] = x - a[i];
		if (b[tot] >= 0) {
			tot++;
		} else {
			b[tot] = 100000000000000;
		}
	}
	sort(b + 1, b + 1 + tot);
	for (int i = 1; i <= n; i++) {
		if (b[i] <= cnt) {
			sum++;
			cnt -= b[i];
		} else {
			break;
		}
	}
	if (sum < ans) {
		ans = max(sum, ans);
		return 1;
	} else {
		ans = max(sum, ans);
		return 0;
	}
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	if (n <= 5000) {
		for (int i = 1; i <= n; i++) {
			check(i);
		}
		cout << ans;
		return 0;
	}
	long long l = 1, r = n;
	while (l < r) {
		for (int i = 1; i <= n; i++) {
			b[i] = 1e14;
		}
		int mid = (r + l + 1) / 2;
		if (check(mid)) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	r = n;
	while (l < r) {
		for (int i = 1; i <= n; i++) {
			b[i] = 1e14;
		}
		int mid = (r + l + 1) / 2;
		if (check(mid)) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	cout << ans;
	return 0;
}