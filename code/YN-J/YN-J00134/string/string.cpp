#include <bits/stdc++.h>
using namespace std;
string s;
long long n, bbb = 0, ans = 0;
long long a[200005];
char c[200005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		bbb += a[i];
		for (int j = bbb - a[i]; j <= bbb; j++) {
			s[j] = c[i];
		}
	}
	if (bbb % 2 == 1) {
		for (int i = 0, j = bbb - 1; i < bbb / 2, j > bbb / 2 - 1; i++, j--) {
			if (s[i] != s[j]) {
				ans++;
			}
		}
	} else {
		for (int i = 0, j = bbb - 1; i < bbb / 2, j > bbb / 2; i++, j--) {
			if (s[i] != s[j]) {
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}