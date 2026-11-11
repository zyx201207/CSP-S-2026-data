#include <bits/stdc++.h>
using namespace std;
#define int long long

void fre() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
}
int n, m;
int a[(int)5e5 + 2];
int q[(int)5e5 + 2];
int dn;
int minn, maxx;

bool cmp(int x, int y) {
	return x > y;
}
int mins;

signed main() {
	fre();
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		q[i] = q[i - 1] + (a[i] - a[i - 1]) * (i - 1);
	}
	for (int i = 1; i <= n; i++) {
		int ans = 1, mis = 0;
		if (q[i] <= m) {
			ans = i;
		} else {
			int l = 1, r = i;
			while (l <= r) {
				int mid = (l + r) / 2;
				if (q[i] - (a[i] - a[mid]) * (mid) - q[mid] <= m) {
					r = mid - 1;
					ans = max(ans, i - mid);
					mis = mid;
				} else {
					l = mid + 1;
				}
			}
		}
//		cout << q[i] << " ";
		maxx = max(maxx, ans);
	}
	cout << maxx;
	return 0;
}
/*
5 5
1 2 4 8 9

2 3
1 4
*/