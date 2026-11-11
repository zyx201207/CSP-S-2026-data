#include <bits\stdc++.h>
using namespace std;
long long  a[500005];
long long ans = 0;
long long n, m;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	long long gg;
	long long minn = 1e13, maxn = -1e13;
	int flag1 = 1, flag2 = 1, d = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != i)
			flag1 = 0;
		minn = min(minn, a[i]);
		maxn = max(maxn, a[i]);
	}
	d = a[n] - a[n - 1];
	for (int i = 2; i <= n; i++) {
		if (a[i] - a[i - 1] != d)
			flag2 = 0;
	}

	if (flag1) {
		for (long long i = 1; i <= n; i++) {
			if (i * i + i > 2 * m) {
				cout << i;
				return 0;
			}

		}
	}
	if (flag2) {
		for (long long i = 1; i <= n; i++) {
			if (abs((2 * a[1]*i + (i * i - i)*d) - 2 * i * a[i]) > 2 * m) {
				cout << i - 1;
				return 0;
//				break;
			}

		}
	}
	sort(a + 1, a + 1 + n);
	long long mn = -1;
	for (int mid = minn; mid <= maxn; mid++) {
		ans = 0, gg = 0;
		for (int i = n; i >= 1; i--) {
			if (a[i] <= mid && gg + mid - a[i] <= m) {
				ans++;
				gg += mid - a[i];
			}
			if (gg + mid - a[i] > m)
				break;
		}
		mn = max(ans, mn);
	}
	cout << mn << " ";
	return 0;
}
/*/
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

9 5
1 3 5 7 9 11 13 15 17
/*/
