#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long n, m, a[N], maxn = INT_MIN + 1;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxn = max(maxn, a[i]);
	}
	if (m == 1) {
		cout << maxn;
		return 0;
	} else if (m == n) {
		int sum = a[1];
		for (int i = 2; i <= n; i++) {
			sum &= a[i];
		}
		cout << sum;
	} else if (m == 2) {
		int lst[2005] = {};
		for (int i = 1; i <= n - 1; i++) {
			lst[i] = a[i] & a[i + 1];
		}
		int mx = INT_MIN + 2;
		for (int i = 1; i <= n - 1; i++) {
			mx = max(mx, lst[i]);
		}
		cout << mx;
	} else if (m == n - 1) {
		int lst[N] = {};
		int mx = INT_MIN + 2;
		for (int i = 2; i <= n - 1; i++) {
			lst[i] = a[i] & a[i + 1];
		}
		lst[1] = a[1] & a[2];
		for (int i = 1; i <= n; i++) {
			mx = max(mx, lst[i]);
		}
		cout << mx;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}