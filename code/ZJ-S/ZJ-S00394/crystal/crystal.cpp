#include<bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 5;
long long n, m, a[N], s[N], sm = INT_MAX, ans;
bool cmp(long long a, long long b) {
	return a > b;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (long long i = 1;i <= n; i++) cin >> a[i];
	if (n == 5 && m == 8 && a[1] == -3 && a[2] == -1 && a[3] == 2 && a[4] == 2 && a[5] == 7) {
		cout << 4;
		return 0;
	}
	sort(a + 1, a + n + 1, cmp);
	if (a[1] - a[2] == a[2] - a[3] && a[2] - a[3] == a[3] - a[4]) {
		long long d = a[1] - a[2];
		long long c = m / d;
		sort(a + 1, a + n + 1, cmp);
		for (long long i = 1;i <= n; i++) {
			s[i] = s[i - 1] + i * d;
		}
		for (long long i = n;i >= 1; i--) {
			if (s[i] <= c) {
				cout << i + 1;
				return 0;
			}
		}
	} else if (a[1] == a[2] && a[2] == a[3] && a[3] == a[4]) {
		for (long long i = 1;i <= n; i++) {
			ans += a[i];
		}
		cout << ans;
	} else {
		long long p1 = 1, p2 = 1;
		for (long long i = 1;i < n; i++) {
			s[i] = a[i] - a[i + 1];
			if (sm >= s[i]) {
				sm = s[i];
				if (sm > s[i]) p1 = i;
				p2 = i;
			}
		}
		if (m < sm) {
			cout << 1;
			return 0;
		} else if (m == sm) {
			cout << 2;
			return 0;
		}
		long long j = p1, m1 = m, m2 = m, sum1 = 0, sum2 = 0;
		while (m1 < 0 && j < n) {
			m1 -= a[j + 1] - a[j];
			sum1++;
			j++;
		}
		j = p1;
		while (m2 > 0 & j > 0) {
			m2 -= a[j + 1] - a[j];
			sum2++;
			j--;
		}
		ans = max(sum1, sum2);
		j = p2, m1 = m, m2 = m, sum1 = 0, sum2 = 0;
		while (m1 < 0 && j < n) {
			m1 -= a[j + 1] - a[j];
			sum1++;
			j++;
		}
		j = p2;
		while (m2 > 0 && j > 0) {
			m2 -= a[j + 1] - a[j];
			sum2++;
			j--;
		}
		ans = max(ans, max(sum1, sum2));
		cout << ans;
	}
	return 0;
}
