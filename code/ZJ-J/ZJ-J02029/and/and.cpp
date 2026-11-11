#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[200005], qz[200005], hz[200005], max1 = -1, max2 = -1, max3 = -1, h;
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i == 1) h = a[i];
		else h &= a[i];
		max1 = max(max1, a[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			max2 = max(max2, a[i] & a[j]);
		}
	}
	qz[1] = a[1], hz[n] = a[n];
	for (int i = 2; i <= n; i++) {
		qz[i] = qz[i-1] & a[i];
	}
	for (int i = n-1; i >= 1; i--) {
		hz[i] = hz[i+1] & a[i];
	}
	if (m == 1) cout << max1;
	else if (m == 2) cout << max2;
	else if (m == n) cout << h;
	else if (m == n - 1) {
		max3 = hz[2];
		for (int i = 2; i < n; i++) {
			max3 = max(max3, qz[i-1] & hz[i+1]);
		}
		max3 = max(max3, qz[n-1]);
		cout << max3;
	} else {
		int max4 = 2147483647;
		sort(a + 1, a + n + 1);
		for (int i = n; i > n - m; i--) {
			max4 &= a[i];
		}
		cout << max4;
	}
	return 0;
}