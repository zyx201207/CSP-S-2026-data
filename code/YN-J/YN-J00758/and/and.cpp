#include <bits/stdc++.h>
using namespace std;
int a[200005];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, d;
	cin >> n >> m;
	int maxx = 0;
	bool f = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if ((a[i] & (a[i] + 1)) != 0) {
			f = 1;
		}
		if (i == 1) {
			d = a[i];
		} else {
			d = d & a[i];
		}
		maxx = max(a[i], maxx);
	}
	sort(a + 1, a + 1 + n);
	if (m == 1) {
		cout << maxx;
	} else if (m == n) {
		cout << d;
	} else if (f == 0) {
		cout << a[n - m + 1];
	} else {
		cout << 0;
	}
	return 0;
}