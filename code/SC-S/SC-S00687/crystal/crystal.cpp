#include<bits/stdc++.h>
using namespace std;
long long n, m;
long long ans;
long long a[500005];
long long d[500005];
int main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (long long i = 1; i <= n; i++) {
		d[i] = a[i] - a[i - 1];
	}
	long long l = 1;
	for (long long r = 1; r <= n; r++) {
		ans = max(ans, r - l);
		m -= d[r] * (r - l);
		while (m < 0) {
			m += a[r] - a[l];
			l++;
		}
	}
	cout << ans;
	return 0;
}