#include <bits/stdc++.h>
using namespace std;
long long m, n, a[500005], s[500005], t[5000005], maxx = -2000000000012, minn = 2000000000012, ans = -2000000000012;

bool flag(long long a, long long b) {
	return a > b;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	if (m == 0) {
		cout << 1;
		return 0;
	}
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = a[i] + m;
		if (a[i] > maxx)
			maxx = a[i];
		if (a[i] < minn) {
			minn = a[i];
		}
		for (long long j = a[i]; j <= s[i]; j++) {
			t[abs(j)]++;
//			if (t[abs(j)] > ans)
//				ans = t[abs(j)];
		}
	}
//	cout << ans;
	sort(t + minn, t + maxx + m + 1, flag);
	cout << t[abs(minn)];
	return 0;
}