#include<bits/stdc++.h>
using namespace std;

const long long N = 5e5 + 10;

long long n, m, a[N], s[N];

bool check(long long x) {
	for (long long l = 1, r = x; r <= n; l++, r++) {
		long long sum = x * a[r] - (s[r] - s[l - 1]);
		if (sum <= m) return true;
	}
	return false;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (long long i = 1; i <= n; i++)
		cin >> a[i];

	sort(a + 1, a + n + 1);

	for (long long i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];

	long long l = 1, r = n, ans = -1;
	while (l <= r) {
		long long mid = (l + r) >> 1;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}

	cout << ans << "\n";

	return 0;
}
