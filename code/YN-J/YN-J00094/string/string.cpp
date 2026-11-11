#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long n, a[N], ans;
char c[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;

	for (int i = 1; i <= n; i++) {

		cin >> a[i] >> c[i];
	}

	int l = 1, r = n;

	while (l < r) {
		long long mn = min(a[r], a[l]);

		if (c[l] != c[r])
			ans += mn;

		if (a[l] == mn)
			l++;
		else
			a[l] -= mn;

		if (a[r] == mn)
			r--;
		else
			a[r] -= mn;
	}

	cout << ans;
	return 0;
}
