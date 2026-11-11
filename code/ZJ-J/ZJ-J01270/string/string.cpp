#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, a[200005], p[200005], q[200005], ans = 0;
char c[200005], pc[200005], qc[200005];
signed main() {
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	int l = 1, r = n, sum = 0;
	while(l < r) {
		int x = min(a[l], a[r]);
		sum++;
		p[sum] = a[l];
		q[sum] = a[l];
		pc[sum] = c[l];
		qc[sum] = c[r];
		a[l] -= x;
		a[r] -= x;
		if (a[l] == 0) l++;
		if (a[r] == 0) r--;
		if (r - l == 1) break;
	}
	for (int i = 1; i <= sum; i++) {
		if (pc[i] != qc[i]) {
			ans += p[i];
		}
	}
	cout << ans;
	return 0;
}
