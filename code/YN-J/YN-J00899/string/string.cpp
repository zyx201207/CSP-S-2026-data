#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 10, M = 1e7 + 10;
long long n, a[N], len, o = 1, ans;
char c[N], s[M];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;

	for (int i = 1; i <= n; i++) {

		cin >> a[i] >> c[i];
		len += a[i];

		for (int j = o; j < o + a[i]; j++)

			s[j] = c[i];
		o += a[i];
	}

	if (len % 2 == 0) {
		for (int i = 1; i <= len / 2; i++) {

			if (s[i] != s[len + 1 - i])
				ans++;
		}
	} else {
		for (int i = 1; i <= len / 2 + 1; i++) {

			if (s[i] != s[len + 1 - i])
				ans++;
		}
	}

	cout << ans;
	return 0;
}
