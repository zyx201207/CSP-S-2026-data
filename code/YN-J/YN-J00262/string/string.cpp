//T2
#include <bits/stdc++.h>
using namespace std;
long long n, a[1000000], ans;
char b[1000005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}
	long long l = 1, r = n;
	while (l < r) {
		long long p = min(a[l], a[r]);
		if (b[l] != b[r]) {
			ans += p;
			a[l] -= p;
			a[r] -= p;
		} else {
			a[l] -= p;
			a[r] -= p;
		}
		if (a[l] == 0) {
			l++;
		}
		if (a[r] == 0) {
			r--;
		}
	}
	cout << ans;
	return 0;
}