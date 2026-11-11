#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500005], cj[500005], qzh[500005];
int n, m;

bool check(int t) {
	for (int i = t; i <= n; i++) {
		int sum = 0;
		for (int j = i - t + 1; j < i; j++) {
			sum += qzh[i] - qzh[j - 1];
		}
		if (sum <= m) {
			return 1;
		}
	}
	return 0;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int cs;
	bool flag = 1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i >= 3) {
			if (a[i] - a[i - 1] != a[i - 1] - a[i - 2]) {
				flag = 0;
			}
		}
	}
	if (flag) {
		cs = a[2] - a[1];
		int l = 1, r = 1500000000;
		while (l < r) {
			int mid = (l + r) >> 1;
			double bj, bj2;
			bj = 1.0 * (cs *mid + cs);
			bj2 = 2.0 * m / mid;
			if (bj2 - bj >= 0.0001 || bj2 == bj) {
				l = mid + 1;
			} else {
				r = mid;
			}
		}
		cout << l - 1;
		return 0;
	}
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++) {
		cj[i] = a[i] - a[i - 1];
		qzh[i] = qzh[i - 1] + cj[i];
	}
	int l = 0, r = m;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	cout << l << endl;
//	for (int i = 2; i <= n; i++) {
//		cout << qzh[i] << " ";
//	}
	return 0;
}
/*
5 6
1 2 3 4 5
*/