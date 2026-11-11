#include <bits/stdc++.h>
using namespace std;
long long a[500005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n, m, dd, d;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dd = a[i];
		d = a[i - 1];
		a[i] = dd - d;
	}
	bool f = 1;
	sort(a + 1, a + 1 + n);
	for (int i = 3; i <= n; i++) {
		a[i] = a[i] + a[i - 1];
		if (a[i] > m) {
			cout << i - 1;
			f = 0;
			break;
		}
	}
	long long ans;
	if (f == 1) {
		cout << n;
	}
	//cout << ans;
	return 0;
}