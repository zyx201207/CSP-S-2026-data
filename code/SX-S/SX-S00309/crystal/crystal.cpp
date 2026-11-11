#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500010];
long long pre[500010];

bool cmp(long long x, long long y) {
	return x > y;
}

bool check(int x) {
	for (int i = 1; i <= n; i++) {
		if (i + x - 1 <= n) {
			long long sum = 1ll * x * a[i] - (pre[i + x - 1] - pre[i - 1]);
			if (sum <= m) {
				return 1;
			}
		}
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
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i];
	}
	int l = 1, r = n;
	long long ans = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			l = mid + 1;
			ans = mid;
		} else {
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
}
