#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
char c[200005];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	int l = 1, r = n, sum = 0;
	while (l < r) {
		if (c[l] != c[r]) {
			sum += min(a[l], a[r]);
		}
		a[l] = a[l] - min(a[l], a[r]);
		a[r] = a[r] - min(a[l], a[r]);
		if (a[l] <= 0) {
			l++;
		}
		if (a[r] <= 0) {
			r--;
		}
	}
	cout << sum;
	return 0;
}