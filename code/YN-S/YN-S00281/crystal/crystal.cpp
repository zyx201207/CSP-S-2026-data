#include <bits/stdc++.h>
using namespace std;
int n;
long long m, last = 0, maxn = LONG_LONG_MIN, minn = LONG_LONG_MAX;
long long maxx = 1;
long long a[500005];
bool flag_a = 1, flag_b = 1, flag = 1;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxn = max(maxn, a[i]);
		minn = min(minn, a[i]);
		if (a[i] != i) {
			flag_a = 0;
		}
		if (a[i] - a[i - 1] != a[2] - a[1] && i != 1) {
			flag_b = 0;
		}
		if (a[i] != a[i - 1] && i != 1) {
			flag = 0;
		}
	}
	sort(a + 1, a + n + 1);
	last = a[2] - a[1];
	if (flag) {
		cout << n;
		return 0;
	} else if (flag_a) {
		long long cnt = 0;
		for (int i = 1; i < n; i++) {
			cnt += i;
			if (cnt > m) {
				cout << i;
				return 0;
			}
		}
		cout << n;
		return 0;
	} else if (flag_b) {
		long long cnt = 0, sum = 1;
		for (int i = last; i <= maxn - minn; i += last) {
			cnt += i;
			sum++;
			if (cnt > m) {
				cout << sum;
				return 0;
			}
		}
		cout << n;
		return 0;
	} else if (n <= 5005) {
		for (int i = 1; i <= n; i++) {
			long long cnt = 0, sum = 1;
			for (int j = i - 1; j >= 1; j--) {
				if (cnt + abs(a[i] - a[j]) > m) {
					break;
				} else if (cnt + abs(a[i] - a[j]) == m) {
					sum++;
					break;
				} else {
					sum++;
					cnt += abs(a[i] - a[j]);
				}
			}
			maxx = max(maxx, sum);
		}
		cout << maxx;
		return 0;
	}
	cout >> n;
	//crystal
	return 0;
}