#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[200005];
char b[200005];
string s, sum;

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	int n;
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		ans += a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= a[i]; j++) {
			s += b[i];
		}
	}
	for (int i = n; i >= 1; i--) {
		for (int j = a[i]; j >= 1; j--) {
			sum += b[i];
		}
	}
	int cnt = 0;
	for (int i = 0; i < ans; i++) {
		if (sum[i] != s[i]) {
			cnt++;
		}
	}
	cout << cnt / 2;
	return 0;
}