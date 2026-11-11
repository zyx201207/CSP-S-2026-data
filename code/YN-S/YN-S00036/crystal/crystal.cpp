#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int m;
int a[500010];
int l = 1;
int r;
int mid;
int ret;

int check(int x) {
	int cnt = 0;
	for (int i = 1; i <= n; i += 1) {
		if (a[i] < x) {
			cnt += x - a[i];
		} else {
			break;
		}
	}
	if (cnt <= m) {
		return 1;
	} else {
		return 0;
	}
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n;
	cin >> m;
	for (int i = 1; i <= n; i += 1) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	r = n;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(a[mid]) == 1) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	l -= 1;
	for (int i = 1; i <= n; i += 1) {
		if (a[i] <= a[l]) {
			ret += 1;
		}
	}
	cout << ret;
	return 0;
}