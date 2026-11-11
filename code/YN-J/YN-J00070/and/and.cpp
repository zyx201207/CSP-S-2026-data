#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int a[200090];
int l, r;
int sum ;
int maxn;

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (m == 2) {
		int l = 1, r = 2;
		while (l <= n - 1) {
			sum = a[l] & a[r];
			maxn = max (maxn, sum);
			if (r != n) {
				r++;
			} else {
				l++, r = l + 1;
			}
		}
		cout << maxn;
		return 0;
	}
	if (m == 1) {
		int ma = 0;
		for (int i = 1; i <= n; i++) {
			ma = max(ma, a[i]);
		}
		cout << ma;
		return 0;
	}
	if (m == n) {
		int cnt = a[1];
		for (int i = 2; i <= n; i++) {
			cnt &= a[i];
		}
		cout << cnt;
	}

	return 0;
}
