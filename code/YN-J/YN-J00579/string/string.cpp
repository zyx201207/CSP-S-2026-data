#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	long long a[200005] = {}, cnt = 0;
	char s[200005] = {};
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> s[i];
	}
	int c = 1;
	while (n > c) {
		if (a[c] == 0)
			++c;
		if (a[n] == 0)
			--n;
		if (s[c] != s[n]) {
			if (a[c] > a[n]) {
				cnt += a[n];
				a[c] = a[c] - a[n];
				a[n] = 0;
			} else
				cnt += a[c], a[n] = a[n] - a[c], a[c] = 0;
		} else if (a[c] > a[n])
			a[c] -= a[n], a[n] = 0;
		if (s[c] == s[n] && !(a[c] > a[n]))
			a[n] -= a[c], a[c] = 0;
	}
	cout << cnt;

	return 0;
}