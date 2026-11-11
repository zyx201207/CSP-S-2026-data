#include <bits/stdc++.h>
using namespace std;
const int MAX = 5e5+5;
long long n;
long long m;
long long a[MAX];

bool check(long long x) {
	long long cnt = m;
	for (int i = 1; i <= x; i++) {
		cnt -= (a[x] - a[i]);
	}
	if (cnt >= 0)
		return 1;
	for (int i = x + 1; i <= n; i++) {
		cnt += (a[i - 1] - a[i - x]);
		cnt -= (a[i] - a[i - 1]) * x;
		if (cnt >= 0)
			return 1;
	}
	return 0;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	long long l = 1, r = n, mid, ans;
	while (l <= r) {
		mid = (l + r + 1) >> 1;
		bool f = check(mid);
		if (f) {
			ans = mid;
			l = mid + 1;
		} else
			r = mid - 1;
	}
	cout << ans;
	return 0;
}