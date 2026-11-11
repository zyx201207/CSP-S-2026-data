#include <bits/stdc++.h>
using namespace std;
long long n, m, s, ans, cnt;
long long a[500000 + 50];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	s = n;
	if (s % 2 == 0) {
		s /= 2;
	} else {
		s /= 2 ;
		s += 1;
	}
	s = a[s];
	for (long long i = 1; i <= n; i++) {
		a[i] = abs(s - a[i]);
		if (ans + a[i] <= m) {
			ans += a[i];
			cnt++;
		} else {
			break;
		}
	}
	cout << cnt;
	return 0;

}