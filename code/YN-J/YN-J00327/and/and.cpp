#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int a[200005];
int sum, sum2, ans, ans2;
int maxx = -1e18;
bool f, f2;

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		sum = 0, sum2 = 0, ans = 0, ans2 = 0, f = 0, f2 = 0;
		for (int j = 1; j <= i + 1; j++) {
			if (i & (j << 1) ) {
				sum++;
				if (!f) {
					f = 1;
					ans = a[j];
				}
				ans &= a[j];
			} else {
				sum2++;
				if (!f2) {
					f2 = 1;
					ans2 = a[j];
				}
				ans2 &= a[j];
			}
		}
		if (sum == m) {
			maxx = max(maxx, ans);
		}
		if (sum2 == m) {
			maxx = max(maxx, ans2);
		}
	}
	cout << maxx;
	return 0;
}