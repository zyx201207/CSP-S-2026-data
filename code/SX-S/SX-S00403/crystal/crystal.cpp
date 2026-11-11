#include <bits/stdc++.h>
using namespace std;
int n;
long long m, a[500010], qzh[500010];

bool check(int x) {
	for (int i = x; i <= n; i++) {
		long long t = x * a[i];
		t -= qzh[i] - qzh[i - x];
		if (t <= m) {
			return 1;
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
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		qzh[i] = qzh[i - 1] + a[i];
	}
	int l = 1, r = n;
	while (l < r) {
		int mid = (l + r + 1) / 2;
		if (check(mid)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	cout << l;
	return 0;
}