#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n, m;
int a[N];
int d[N];

bool check(int x) {
	long long cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] > x) {
			return cnt <= m;
		}
		cnt += (x - a[i]);
	}
	return cnt <= m;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int l = -1e12, r = 1e12, ans = -1e13;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			l = mid + 1;
			ans = mid;
		} else {
			r = mid - 1;
		}
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] > ans) {
			cout << sum << endl;
			return 0;
		}
		sum++;
	}
	cout << sum;
	return 0;
}
