#include <bits/stdc++.h>
using namespace std;
long long a[5000000];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n, m, l = 0, ll = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		l += a[i];

	}
	l /= n;
	for (int i = 1; i <= n; i++) {
		if (a[i] <= l)
			ll++;
	}
	cout << ll;
	return 0;
}