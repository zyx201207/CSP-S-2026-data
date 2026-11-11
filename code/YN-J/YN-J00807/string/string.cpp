#include <bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n;
	cin >> n;
	if (n <= 1) {
		cout << '0';
		return 0;
	}
	for (long long i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	char v = c[1];
	bool flag = 0;
	for (long long i = 1; i <= n; i++) {
		if (c[i] != v) {
			flag = 1;
		}
	}
	if (flag == 0) {
		cout << '0';
		return 0;
	}
	long long k = 0;
	bool flag1 = 0;
	for (long long i = n; i > k; i--) {
		k++;
		if (a[k] != a[i] || c[k] != c[i]) {
			flag1 = 1;
		}
	}
	if (flag1 == 0) {
		cout << 0;
		return 0;
	}
	k = 0;
	long long ans = 0;
	for (long long i = n; i > k; i--) {
		k++;
		if (a[k] == a[i] && c[k] != c[i]) {
			ans += a[i];
		} else if (a[k] != a[i] && c[k] == c[i]) {
			ans += abs(a[k] - a[i]);

		} else if (a[k] != a[i] && c[k] != c[i]) {
			ans += max(a[i], a[k]);
		}
	}
	cout << ans;
}