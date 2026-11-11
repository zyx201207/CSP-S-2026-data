#include <bits/stdc++.h>
using namespace std;
#define int long long
char c[200005];
int a[200005];
string s, s1;

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, cnt = 0, cnt1 = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	for (int i = 2; i <= n; i++) {
		if (c[i] == c[i - 1]) {
			cnt1++;
		}
	}
	if (cnt1 + 1 != n) {
		for (int i = 1; i * 2 <= n + 1; i++) {
			if (a[i] == a[n - i + 1] && c[i] == c[n - i + 1]) {
				a[i] = 0;
				a[n - i + 1] = 0;
			}
			if (a[i] != a[n - i + 1] && c[i] == c[n - i + 1]) {
				a[i] = abs(a[i] - a[n - i + 1]);
				a[n - i + 1] = 0;
			}
			if (c[i] != c[n - i + 1]) {
				a[n - i + 1] = 0;
			}
		}
		for (int i = 1; i <= n; i++) {
			cnt += a[i];
		}
	}
	cout << cnt;
	return 0;
}