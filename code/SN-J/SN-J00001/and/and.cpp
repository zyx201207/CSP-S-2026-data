#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[200005];
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	int maxn = -1;
	int yu;
	int t = 1; 
	int t1 = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i == 1) yu = a[1];
		maxn = max(maxn, a[i]);
		yu &= a[i];
		if (a[i] != i - 1) {
			t = 0;
		}
		if (a[i] != 1 && a[i] != 3 && a[i] != 7 && a[i] != 15 && a[i] != 31 && a[i] != 63 && a[i] != 127 && a[i] != 255 && a[i] != 511 && a[i] != 1023 && a[i] != 2047 && a[i] != 4095 && a[i] != 8191 && a[i] != 16383 && a[i] != 32767 && a[i] != 65535 && a[i] != 131071 && a[i] != 262143 && a[i] != 524287 && a[i] != 1048575 && a[i] != 2097151 && a[i] != 4194303 && a[i] != 8388607 && a[i] != 16777215 && a[i] != 33554431 && a[i] != 67108863 && a[i] != 134217727 && a[i] != 268435455 && a[i] != 536870911) {
			t1 = 0;
		}
	}
	if (m == 1) {
		cout << maxn;
	} else if (m == 2) {
		int ans = -1;
		for (int i = 1; i < n; i++) {
		    for (int j = i + 1; j <= n; j++) {
		    	ans = max(ans, a[i] & a[j]);
			}
		}
		cout << ans;
	} else if (m == n) {
		cout << yu;
	} else if (t) {
		cout << 0;
	} else if (t1) {
		sort(a + 1, a + 1 + n);
		cout << a[n - m + 1];
	}
	return 0;
}

