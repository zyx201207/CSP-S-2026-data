#include <bits/stdc++.h>
using namespace std;
#define ll long long
int const N = 2e5 + 10;
int a[N];
char c[N];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	ll cnt = 1, cnt1 = 1, x, sum = 0;
	for (int i = 1; i <= n - 1; i++) {
		if (c[i] == c[i + 1]) {
			cnt++;
		}
		if (a[i] == a[i + 1]) {
			cnt1++;
		}
		sum += a[i];
		x = a[i];
	}
	if (cnt == n) {
		cout << 0;
		return 0;
	}
	if (n % 2 == 0 && cnt1 == n) {
		cout << (n / 2)*x;
		return 0;
	}
	if (n % 2 == 1) {
		cout << (sum / 2 - a[1]) + sum / 2;
	}
	string s;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= a[i]; j++) {
			s += c[i];
		}
	}

	return 0;
}