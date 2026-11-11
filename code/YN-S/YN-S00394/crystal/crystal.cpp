#include <bits/stdc++.h>
using namespace std;

long long n, m, a[500050];

bool check(int x) {
	long long q = a[x];
	long long sum = 0;
	for (long long i = 1; i < x; i++) {
		sum += (a[x] - a[i]);
	}
	if (sum <= m) {
		return true;
	} else {
		return false;
	}
}

int main() {

	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	long long l = 1, r = n, ans = 1;
	while (r >= l) {
		long long mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
}