#include<bits/stdc++.h>
using namespace std;

const long long N = 2e5 + 10;

long long n, a[N];
char c[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;

	for (long long i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}

	long long l = 1, r = n;
	long long ans = 0;

	while (l < r) {
		// jump the smaller one
		if (a[l] < a[r]) {
			if (c[l] != c[r]) ans += a[l];
			a[r] -= a[l];
			l++;
		} else if (a[l] > a[r]) {
			if (c[l] != c[r]) ans += a[r];
			a[l] -= a[r];
			r--;
		} else { // a[l] == a[r]
			if (c[l] != c[r]) ans += a[l];
			l++;
			r--;
		}
	}

	cout << ans << "\n";

	return 0;
}
