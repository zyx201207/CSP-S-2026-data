#include <bits/stdc++.h>
using namespace std;

long long n, a[500005], b[500005], ans, cnt, maxnn, m;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i < n; i++) {
		b[i] = a[n] - a[i];
	}
	long long l = n - 1, r = n;
	while (l > 0) {
		ans = ans + b[l] - b[r];
		if (ans > m) {
			r--;
			ans = 0;
			cnt = 0;
			l = r - 1;
		} else {
			l--;
			cnt++;
			if (cnt > maxnn) {
				maxnn = cnt;
			}
		}
	}
	cout << maxnn + 1;
	return 0;
}