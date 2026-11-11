/*
CSP-J 2026 T3
by hty
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int a[N];
int maxx, n, m, sum;

bool cmp(int x, int y) {
	return x > y;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (m == 1) {
		for (int i = 1; i <= n; i++)
			maxx = max(maxx, a[i]);
		cout << maxx;
		return 0;
	} else if (m == n) {
		sum = a[1];
		for (int i = 2; i <= n; i++)
			sum = sum & a[i];
		cout << sum;
		return 0;
	} else if (m == n - 1) {
		for (int i = 1; i <= n; i++) {
			if (i == 1) {
				sum = a[2];
			} else {
				sum = a[1];
			}
			for (int j = 1; j <= n; j++) {
				if (j == i)
					continue;
				else
					sum = sum & a[i];
			}
			maxx = max(maxx, sum);
		}
		cout << maxx;
		return 0;
	} else if ((m == 2) && (n * n <= (int)1e8)) {
		maxx = -1;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				maxx = max(maxx, a[i] & a[j]);
			}
		}
		cout << maxx;
		return 0;
	} else {
		sort(a + 1, a + n + 1, cmp);
		cout << a[m];
	}
	return 0;
}