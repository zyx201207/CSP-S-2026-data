#include <bits/stdc++.h>
using namespace std;
long long n, m, ans = 0;
vector<long long> a;

long long f(long long x) {
	long long l = x - 1, r = x + 1, ld, rd, k = m, minn = 1;
	while (k >= 0) {
		ld = 4294967295;
		rd = 4294967295;
		if (l > 0)
			ld = abs(a[x] - abs(a[l]));
		if (r > 0)
			rd = abs(abs(a[r]) - a[x]);
		if (k >= min(ld, rd)) {
			k = k - min(ld, rd);
			minn++;
			if (ld > rd)
				r++;
			else if (ld == rd && abs(a[l] - a[l - 1]) <= a[r + 1] - a[r])
				l--;
			else
				r++;
		} else
			break;
	}
	return minn;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	a.resize(n + 2, 0);
	a[0] = 4294967295 ;
	a[n + 1] = 4294967295 ;
	for (long long i = 1; i <= n; i++)
		cin >> a[i];
	sort(a.begin() + 1, a.end() - 1);
	for (long long i = 1; i <= n; i++) {
		ans = max(ans, f(i));
	}
	cout << ans;
	return 0;
}