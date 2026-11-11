#include <bits/stdc++.h>
using namespace std;
long long a[500010] = {};
int main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	long long m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	long long last = 0;
	for (int i = 1; i <= n - 1; i++) {
		last += a[n] - a[i];
	}
	if (last <= m) {
		cout << n;
		return 0;
	}
	for (int i = n - 1; i >= 1; i--) {
		last -= i * (a[i + 1] - a[i]);
		if (last <= m) {
			cout << i;
			return 0;
		}
	}
	return 0;
}
