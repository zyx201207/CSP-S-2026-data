#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 5e5 + 5;

int n, ans, f = 1, f2 = 1;
ll m, a[N], pre[N], sum;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i == a[i] && f) {
			f = 1;
		} else {
			f = 0;
		}
		if (i > 2 && a[i] == a[i - 1] + a[i - 2] && f2) {
			f2 = 1;
		} else if (i > 2) {
			f2 = 0;
		}
	}
	sort(a + 1, a + 1 + n);
	if (f) {
		for (int i = 1; i <= n; i++) {
			sum += i;
			if (sum > m) {
				cout << i;
				return 0;
			}
		}
		cout << n;
		return 0;
	}
	if (f2) {
		int h = 1;
		for (int i = 1; i <= n; i++) {
			if ((i - 1) * a[i] - sum <= m) {
				h = i;
			}
			sum += a[i];
		}
		cout << h;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i];
 	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < i; j++) {
			if (a[i] * (i - j + 1) - pre[i] + pre[j - 1] <= m) {
				ans = max(i - j + 1, ans);
			}
		} 
	}
	cout << ans;
	return 0;
} 
/*
5 5
1 2 4 8 3 9
*/
/*
5 8
-3 -1 2 2 7
*/
