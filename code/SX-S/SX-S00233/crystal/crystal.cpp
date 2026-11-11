#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5+5, M = 1e7;
long long n, m, a[N], num[M], d[N], sumd[N];

void solveAB() {
	long long x = upper_bound(num + 1, num + 1 + m, m) - num;
	if (x == 1)
		x = 0;
	cout << x;
}

bool check(long long x) {
	long long minn = 1e18;
	for (long long i = 1; i <= n - x + 1; i++) {
		long long maxx = a[i + x - 1], summ = 0;
		for (long long j = i; j <= i + x - 1; j++) {
			summ = summ + maxx - a[j];
		}
		minn = min(minn, summ);
	}
	if (minn <= m)
		return 1;
	return 0;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	bool flagA = 1;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != i)
			flagA = 0;
	}
	long long fomer = a[2] - a[1];
	bool flagB = 1;
	for (long long i = 2; i <= n; i++) {
		if (a[i] - a[i - 1] != fomer) {
			flagB = 0;
		}
	}
	if (flagA == 1) {
		for (long long i = 1; i <= min(m, M); i++) {
			num[i] = num[i - 1] + i;
		}
		solveAB();
		return 0;
	} else if (flagB == 1) {
		for (long long i = 1; i <= min(m, M); i++) {
			num[i] = num[i - 1] + i * abs(fomer);
		}
		solveAB();
		return 0;
	} else {
		sort(a + 1, a + 1 + n);
		long long l = 1, r = m, mid, ans;
		while (l <= r) {
			mid = (l + r) >> 1;
			if (check(mid)) {
				ans = mid;
				l = mid + 1;
			} else
				r = mid - 1;
		}
		cout << ans;
	}
	return 0;
}
