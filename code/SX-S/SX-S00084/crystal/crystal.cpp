#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], cnt;

inline bool cmp(int x, int y) {
	return x < y;
}

inline bool check(long long p) {
	long long sum = 0;
	for (int i = 1; i <= p; i++) {
		sum += a[p] - a[i];
	}
	if (sum <= m)
		return 1;
	return 0;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	long long l = 1, r = n;
	while (l <= r) {
		long long mid = (l + r + 1) / 2;
		if (check(mid) == 1) {
			cnt = max(cnt, mid);
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << cnt;
	return 0;
}
