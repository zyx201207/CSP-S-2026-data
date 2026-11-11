#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], sum, mx, ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	sort(a + 1, a + n + 1);
	long long l = 0;
	for (long long i = 1; i <= n; i++) {
		sum += (a[i] - a[i - 1]) * (i - 1 - l);
		while (sum > m) {
			l++;
			sum -= a[i] - a[l];
		}
		ans = max(ans, i - l);
	}
	cout << ans;
	for (long long i = 1; i <= mx; i++)
		ans *= ans;
	return 0;
}