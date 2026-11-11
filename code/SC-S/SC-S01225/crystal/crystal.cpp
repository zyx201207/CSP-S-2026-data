#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, m;
bool l = true;
bool d = false;
int a[500005];
int f (int x) {
	int j = 0;
	for (int i = 1; i <= x; i++) {
		if (i * (i + 1) / 2 > x) {
			j = i - 1;
			break;
		} else if (i * (i + 1) / 2 == x) {
			j = i + 1;
			break;
		}
	}
	return j;
}
int main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < n; i++) {
		if (abs (a[i] - a[i + 1]) > m) {
			l = false;
		} else {
			l = true;
		}
		if (a[i] == a[i + 1]) d = true;
	}
	if (l == false) {
		if (d == false) {
			cout << 0;
		} else {
			cout << 2;
		}
		return 0;
	}
	int t = 0;
	for (int i = 1; i < n; i++) {
		if (a[i + 1] - a[i] > 1) {
			t = a[i + 1] - a[i];
			m *= t;
			n *= t;
			break;
		}
	}
	
	if (m == n * (n + 1) / 2) {
		cout << n / t;
		return 0;
	}
	if (f (m) == 0) {
		if (d == false) {
			cout << 0;
		} else {
			cout << 2;
		}
		return 0;
	}
	if (f (m) == 1) {
		cout << 2;
		return 0;
	}
	if (t - 1 > 0) {
		if (f (m) / (t - 1) > n) cout << n / t;
		else cout << f (m) / (t - 1);
		return 0;
	} else cout << f (m);
	return 0;
}