#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005];

bool check(long long len) {
	long long sum = 0;
	for (int i = 1; i <= len; i++)
		sum += (a[len] - a[i]);
	if (sum <= m)
		return 1;
	for (int i = len + 1; i <= n; i++) {
		sum -= (a[i - 1] - a[i - len]);
		sum += (len - 1) * (a[i] - a[i - 1]);
		if (sum <= m)
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
	long long l = 1, r = n;
	while (l < r) {
		long long mid = (l + r + 1) / 2;
		if (check(mid))
			l = mid;
		else
			r = mid - 1;
	}
	cout << l;
	return 0;
}